# Scheduler Simulator

This is a project that implements the 'scheduling policy' of the Operating System.  
Implementation target: **FCFS**, **SJF**, **RR**, **MLFQ**, **lottery** scheduling

---

## 1. First Come First Served(FCFS)
- Schedule the process that arrives first
- Advantage: Simple and easy to implement
- Disadvantage: Convoy effect occurs
  
<img width="50%" src="https://user-images.githubusercontent.com/76467273/160879866-5c4e137b-0a53-45ed-83b1-aca60bae0724.png"/>

<br>

## 2. Shortest Job First(SJF)
- Schedule the process with the shortest execution time first
- Advantage: If all tasks arrive at the same time, turnaround time can be minimized
- Disadvantage: Convoy effect occurs
  
<img width="50%" src="https://user-images.githubusercontent.com/76467273/161820856-2138c617-d482-4053-8c43-33618d64c7f9.png"/>

<br>

## 3. Round Robin(RR)

- Schedule the process only for a time slice and switch to the next process.
- The shorter the time slice, the better the response time.
- However, the shorter the time slice, the higher the context exchange cost.
- Advantage: The response time is fast.
- Disadvantage: The turnaround time is slow.

<img width="50%" src="https://user-images.githubusercontent.com/76467273/161819601-4f16ae80-a604-4027-adb9-8f23f67c17a9.png"/>  

<br>
  
---

### # Example Input Data
<img width="80%" src="https://user-images.githubusercontent.com/76467273/160879219-4e022e79-f2fe-4d73-9d08-54925037c569.png"/>