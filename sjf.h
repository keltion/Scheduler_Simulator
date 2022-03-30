#pragma once

#include <algorithm>
#include <iostream>
#include <memory>
#include <map>
#include <queue>
#include <string>

#include "print_tool.h"
#include "process.h"

class SJF {
public:
    SJF() = default;
    SJF(int& process_count, int& process_time,
        std::vector<std::unique_ptr<Process>>& memory)
        : print_tool_(
            std::make_unique<PrintTool>(process_count, process_time)),
            cpu_time_(0), position_(0), total_time_(process_time) {
      memory_.reserve(memory.size());
      for (const auto& process : memory) {
        memory_.emplace_back(std::make_unique<Process>(*process));
      }
    }

    void SortByArriveTime(std::vector<std::unique_ptr<Process>>& ready_queue) {
        std::sort(std::begin(ready_queue), std::end(ready_queue),
                  [](const std::unique_ptr<Process>& lhs,
                     const std::unique_ptr<Process>& rhs) {
            return lhs->GetArriveTime() < rhs->GetArriveTime();
        });
    }
    
    void SortByRunTime(std::vector<std::unique_ptr<Process>>& ready_queue) {
        std::sort(std::begin(ready_queue), std::end(ready_queue),
                  [](const std::unique_ptr<Process>& lhs,
                     const std::unique_ptr<Process>& rhs) {
            return lhs->GetRunTime() < rhs->GetRunTime();
        });
    }

    void InputProcessInReadyQueueIfPossible() {
        int count = 0;
        int start = position_;
        // Find which process arrived based on current cpu_time_
        auto itr = memory_.begin();
        for (itr + position_; itr != memory_.end(); itr++) {
            if (cpu_time_ >= (*itr)->GetArriveTime()) {
                count++;
                continue;
            } else {
                break;
            }
        }
        position_ += count;

        itr = memory_.begin();
        for (itr + start; itr != memory_.begin() + position_; itr++) {
            ready_queue_.emplace_back(std::move(*itr));
        }
        return;
    }

    void SortReadyQueue() {
        SortByRunTime(ready_queue_);
    }

    void CPUAllocate() {
        SortByArriveTime(memory_);
        while(cpu_time_ < total_time_) {
            InputProcessInReadyQueueIfPossible();
            SortReadyQueue();
            if(!ready_queue_.empty()) {
                std::unique_ptr<Process> process = std::move(ready_queue_.front());
                ready_queue_.erase(ready_queue_.begin());
                while(process->GetRunTime()) {
                    process->DecreaseRunTime(1);
                    print_tool_->Record(process->ProcessName(), cpu_time_); 
                    cpu_time_++;
                }
            } else {
                cpu_time_++;
            }
            
        }
    }

    void PrintFootPrint() const {
        print_tool_->print();
    }

private:
    std::unique_ptr<PrintTool> print_tool_;
    std::vector<std::unique_ptr<Process>> ready_queue_;
    std::vector<std::unique_ptr<Process>> memory_;
    int cpu_time_;
    int position_;
    int total_time_;
};