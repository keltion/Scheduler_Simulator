#include <memory>
#include <vector>

#include "fcfs.h"
#include "sjf.h"
#include "process.h"

std::vector<std::unique_ptr<Process>> memory;


void MakeProcess(int& number_of_process, int& total_time) {
    char process_id = 'A';
    int arrive_time, run_time; 

    std::cout << "Number of process to create: ";
    std::cin >> number_of_process;
    for (int i = 0; i < number_of_process; i++) {
        char pid = process_id + i;
        std::cout << "Enter " << pid << "'s run time and arrive time: ";
        std::cin >> run_time >> arrive_time;
        std::unique_ptr<Process> process = std::make_unique<Process>(run_time, arrive_time, pid);
        memory.emplace_back(std::move(process));
        total_time += run_time;
    }
}

int main() {
    int number_of_process;
    int total_time = 0;

    MakeProcess(number_of_process, total_time);   

    std::cout << "===== FCFC =>" << std::endl;
    FCFS fcfs(number_of_process, total_time, memory);
    fcfs.CPUAllocate();
    fcfs.PrintFootPrint();

    std::cout << "===== SJF =>" << std::endl;
    SJF sjf(number_of_process, total_time, memory);
    sjf.CPUAllocate();
    sjf.PrintFootPrint();
}