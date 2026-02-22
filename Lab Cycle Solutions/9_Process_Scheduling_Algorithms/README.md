# AIM
Input a list of processes, their CPU burst times (integral values), arrival times, and
priorities. Then simulate FCFS, SRTF, non-preemptive priority (a larger priority number
implies a higher priority), and RR (quantum = 3 units) scheduling algorithms on the process mix, determining which algorithm results in the minimum average waiting time
(over all processes).     

# ALGORITHM

**Step 1:** Start.

**Step 2:** Declare the `Proc` structure containing process details (ID, Arrival, Burst, Priority, Remaining Time) and input the total number of processes ($n$).

**Step 3:** Iterate $n$ times to read the Process ID, Arrival Time, Burst Time, and Priority. Initialize `remaining` time equal to `burst` for all processes.

**Step 4:** Perform **FCFS Scheduling**:
* **Logic:** Create a copy of the process list and **sort** it by Arrival Time.
* **Execution:** Iterate through the sorted list. If the CPU is idle (`current_time` < `arrival`), advance time. Otherwise, add `burst` to `current_time` to find `completion`.
* **Calculation:** Compute `turnaround` (`completion` - `arrival`) and `waiting` (`turnaround` - `burst`) for each process.
* **Output:** Print the FCFS Gantt Chart and average Waiting/Turnaround times.

**Step 5:** Perform **Non-Preemptive Priority Scheduling**:
* **Initialization:** Reset `current_time` and `completed` counters. Mark all processes as incomplete.
* **Loop:** Repeat until all processes are finished:
    * **Search:** Iterate to find the process that has **Arrived** and is **Incomplete** with the **Highest Priority**.
    * **Execute:** Update `current_time` by adding the selected process's `burst`. Calculate `turnaround` and `waiting` times. Mark the process as complete.
* **Output:** Print the Priority Gantt Chart and average Waiting/Turnaround times.

**Step 6:** Perform **Round Robin Scheduling** (Time Quantum = 3):
* **Initialization:** Reset `current_time` and `remaining` time (to `burst`). Sort the list by Arrival Time.
* **Loop:** Cycle through the process list repeatedly until all are finished:
    * **Quantum Check:** If a process has arrived and is incomplete:
        * If `remaining` > 3: Execute for 3 units, subtract 3 from `remaining`, and advance `current_time`.
        * If `remaining` $\le$ 3: Execute for `remaining` time, set `remaining` to 0, update `current_time`, and calculate `turnaround` and `waiting` times.
* **Output:** Print the Round Robin Gantt Chart and average Waiting/Turnaround times.

**Step 7:** Perform **SRTF (Shortest Remaining Time First) Scheduling**:
* **Initialization:** Reset `current_time` and set `remaining` time equal to `burst` for all processes.
* **Loop:** Increment time unit by unit until all processes are completed:
    * **Selection:** Check all processes that have **Arrived** (`arrival` $\le$ `current_time`) and are incomplete. Select the process with the **Minimum Remaining Time**.
    * **Execute:** Execute the selected process for 1 unit of time: decrement its `remaining` time and increment `current_time`.
    * **Completion:** If `remaining` becomes 0, mark the process as completed. Calculate `turnaround` (`completion` - `arrival`) and `waiting` (`turnaround` - `burst`).
* **Output:** Print the SRTF Gantt Chart and average Waiting/Turnaround times.

**Step 8:** Compare Algorithms:
* **Comparison:** Compare the **Average Waiting Time** calculated from FCFS, Priority, Round Robin, and SRTF.
* **Selection:** Identify the algorithm with the minimum average waiting time.
* **Output:** Print the name of the **Best Algorithm** and its average waiting time.

**Step 9:** Stop.
