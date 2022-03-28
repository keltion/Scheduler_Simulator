#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <queue>
#include <string>

#include "print_tool.h"
#include "process.h"

int cpu_time;

class FCFS {
public:
    FCFS(int& process_count, int& process_time)
        : print_tool_(
              std::make_unique<PrintTool>(process_count, process_time)) {}

    void SortProcess(std::vector<std::unique_ptr<Process>>& ready_queue) {
        std::sort(std::begin(ready_queue), std::end(ready_queue),
                  [](const std::unique_ptr<Process>& lhs,
                     const std::unique_ptr<Process>& rhs) {
            return lhs->GetArriveTime() < rhs->GetArriveTime();
        });
    }

    void CPUAllocate(std::vector<std::unique_ptr<Process>>& ready_queue) {
        SortProcess(ready_queue);
        while(!ready_queue.empty()) {
            std::unique_ptr<Process> process = std::move(ready_queue.front());
            ready_queue.erase(ready_queue.begin());
            while(process->GetRunTime()) {
                process->DecreaseRunTime(1);
                print_tool_->Record(process->ProcessName(), cpu_time); 
                cpu_time++;
            }
        }
    }

    void PrintFootPrint() {
        print_tool_->print();
    }

private:
    std::unique_ptr<PrintTool> print_tool_;
};