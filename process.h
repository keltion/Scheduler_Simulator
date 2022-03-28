#pragma once

#include <string>

class Process {
public:
    Process() = delete;
    Process(int run_time, int arrive_time, char name) : run_time_(run_time), arrive_time_(arrive_time), name_(name) {}
    int GetRunTime() const { return run_time_; }
    int GetArriveTime() const { return arrive_time_; }
    void DecreaseRunTime(int amount) { run_time_ -= amount; }
    char ProcessName() const { return name_; }

private:
    int run_time_;
    int arrive_time_;
    char name_;
};