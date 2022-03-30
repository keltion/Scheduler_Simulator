# Scheduler Simulator

This is a project that implements the 'scheduling policy' of the Operating System.  
Implementation target: **FCFS**, **SJF**, **RR**, **MLFQ**, **lottery** scheduling

---

## 1. First Come First Served(FCFS)
- Schedule the process that arrives first
- Advantages: Simple and easy to implement
- Disadvantages: Convoy effect occurs
  
<img width="50%" src="https://user-images.githubusercontent.com/76467273/160879866-5c4e137b-0a53-45ed-83b1-aca60bae0724.png"/>

<br>

## 2. Shortest Job First(SJF)
- Schedule the process with the shortest execution time first
- Advantage: If all tasks arrive at the same time, turnaround time can be minimized
- Disadvantages: Convoy effect occurs
  
<img width="50%" src="https://user-images.githubusercontent.com/76467273/160880212-dd7a088a-a9fd-4f56-81f0-ddaf43e0e486.png"/>
  
---
### # Example Input Data
<img width="80%" src="https://user-images.githubusercontent.com/76467273/160879219-4e022e79-f2fe-4d73-9d08-54925037c569.png"/>