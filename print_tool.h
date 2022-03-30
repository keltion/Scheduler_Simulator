#pragma once

#include <iostream>

class PrintTool {
public:
    PrintTool(int& process_count, int& process_time) {
        std::vector<bool> footprint(process_time, false);
        for(int i = 0; i < process_count; i++) {
            canvas.emplace_back(footprint);
        }
    }
    void Record(char pid, int time) {
        canvas[pid - 'A'][time] = true;
    }

    void print() const {
        int idx = 0;
        for(auto &process : canvas) {
            char process_name = 'A' + idx;
            std::cout << process_name << " ";
            for(bool i : process) {
                if(i == true) {
                    std::cout << "▪";
                } else {
                    std::cout << "▫";
                }
            }
            idx++;
            std::cout << "\n";
            
        }
    }  
private:
    std::vector<std::vector<bool>> canvas;
};