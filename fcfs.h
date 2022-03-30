#pragma once

#include <algorithm>
#include <iostream>
#include <memory>
#include <map>
#include <queue>
#include <string>

#include "print_tool.h"
#include "process.h"

class FCFS {
public:
    FCFS(int& process_count, int& process_time,
        std::vector<std::unique_ptr<Process>>& memory)
        : cpu_time_(0), print_tool_(
              std::make_unique<PrintTool>(process_count, process_time)) {
        ready_queue_.reserve(memory.size());
        for (const auto& process : memory) {
            ready_queue_.emplace_back(std::make_unique<Process>(*process));
        }
    }

    void SortProcess() {
        std::sort(std::begin(ready_queue_), std::end(ready_queue_),
                  [](const std::unique_ptr<Process>& lhs,
                     const std::unique_ptr<Process>& rhs) {
            return lhs->GetArriveTime() < rhs->GetArriveTime();
        });
    }

    void CPUAllocate() {
        SortProcess();
        while(!ready_queue_.empty()) {
            std::unique_ptr<Process> process = std::move(ready_queue_.front());
            ready_queue_.erase(ready_queue_.begin());
            while(process->GetRunTime()) {
                process->DecreaseRunTime(1);
                print_tool_->Record(process->ProcessName(), cpu_time_); 
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
    int cpu_time_;
};