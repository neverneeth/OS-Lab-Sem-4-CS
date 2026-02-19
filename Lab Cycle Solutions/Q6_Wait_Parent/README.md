# Parent Process Wait Algorithm

**Step 1:** Start

**Step 2:** Create a new child process by duplicating the current parent process.

**Step 3:** Check if the current execution stream belongs to the newly created child process.

**Step 4:** If it is the child process, print the specified course code text to the console.

**Step 5:** If the current execution stream belongs to the parent process, pause execution and wait for the child process to completely finish its task. 
**Step 6:** Once the child process has successfully completed and exited, have the parent process print the remaining course name text to the console.

**Step 7:** Stop.
