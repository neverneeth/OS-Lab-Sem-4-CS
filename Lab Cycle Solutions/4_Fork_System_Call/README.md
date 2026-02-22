# Algorithm

**Step 1:** Start

**Step 2:** Print a message to the console indicating that the program has started running.

**Step 3:** Create a new child process by duplicating the current parent process.

**Step 4:** Check if the current execution stream belongs to the newly created child process.

**Step 5:** If it is the child process, print a message stating that it is the child process, and display its own unique process ID along with its parent's process ID.

**Step 6:** If the current execution stream belongs to the parent process, pause and wait for the child process to completely finish its execution.

**Step 7:** Once the child process has finished, have the parent process print a message stating that it is the parent process, and display its own process ID.

**Step 8:** Pause the execution of the program for a long duration (one thousand seconds) to keep the processes active and observable in the system.

**Step 9:** Stop.
