# CPU Scheduling Algorithms

**Step 1:** Start.

**Step 2:** Declare `Proc` structure (ID, Arrival, Burst, Priority, Remaining) and input process count ($n$).

**Step 3:** Input process details (ID, Arrival, Burst, Priority) for $n$ processes. Initialize `remaining` = `burst`.

**Step 4:** **FCFS Scheduling**:
* **Logic:** Sort process list by Arrival Time.
* **Execution:** Iterate list. If idle, advance time; else add `burst` to `current_time`.
* **Output:** Calculate and print `turnaround`, `waiting` times, and Gantt Chart.

**Step 5:** **Non-Preemptive Priority Scheduling**:
* **Init:** Reset variables.
* **Loop:** While processes remain:
    * **Select:** Find arrived, incomplete process with **Highest Priority**.
    * **Execute:** Add `burst` to `current_time`, mark complete, and calculate stats.
* **Output:** Print Gantt Chart and averages.

**Step 6:** **Round Robin Scheduling** (Time Quantum = 3):
* **Init:** Reset variables, sort by Arrival.
* **Loop:** Cycle through list:
    * **Check:** If arrived and incomplete:
        * If `remaining` > 3: Run 3 units, update `remaining` and time.
        * If `remaining` $\le$ 3: Run remaining time, finish process, and calculate stats.
* **Output:** Print Gantt Chart and averages.

**Step 7:** **SRTF Scheduling**:
* **Init:** Reset variables.
* **Loop:** Increment time unit by unit:
    * **Select:** Choose arrived, incomplete process with **Minimum Remaining Time**.
    * **Execute:** Run 1 unit. Update `remaining`. If 0, mark complete and calculate stats.
* **Output:** Print Gantt Chart and averages.

**Step 8:** **Comparison**:
* **Logic:** Compare **Average Waiting Time** of all four algorithms.
* **Result:** Identify and print the algorithm with the minimum waiting time.

**Step 9:** Stop.
