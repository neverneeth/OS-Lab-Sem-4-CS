# Algorithm for Deadlock Detection Program

**Step 1:** Start 

**Step 2:** Declare integer variables to store the number of processes and the number of resource types.

**Step 3:** Prompt the user to input the number of processes and resource types and store them.

**Step 4:** Declare two-dimensional arrays (matrices) for Allocation and Max resources based on the user input sizes.

**Step 5:** Iterate through each process and resource type to accept input for the Allocation matrix.

**Step 6:** Iterate through each process and resource type to accept input for the Max matrix.

**Step 7:** Declare an array for Available resources and accept input values for each resource type from the user.

**Step 8:** Calculate the Need matrix by subtracting the Allocation matrix from the Max matrix for every process and resource type.

**Step 9:** Initialize a 'finished' boolean array to false for all processes to track their execution status.

**Step 10:** Initialize a safe sequence array and a counter variable to zero.

**Step 11:** Begin a main loop that continues running as long as the counter is less than the total number of processes.

**Step 12:** Inside the main loop, set a 'found' flag to false to track if any process is successfully executed in the current pass.

**Step 13:** Iterate through every process index to check if it can be safely executed.

**Step 14:** For each process, check if it is not yet marked as finished.

**Step 15:** If the process is not finished, check if its Need resources are less than or equal to the currently Available resources for all types.

**Step 16:** If the resources are sufficient, update the Available resources by adding the process's Allocation values to them.

**Step 17:** Add the current process index to the safe sequence array, mark the process as finished, increment the counter, and set the 'found' flag to true.

**Step 18:** After checking all processes in the current pass, check if the 'found' flag remains false.

**Step 19:** If the 'found' flag is false, print "System is in deadlock state" and terminate the program immediately.

**Step 20:** If the loop completes successfully (meaning all processes are finished), print "System is in safe state".

**Step 21:** Print the final safe sequence of processes stored in the array.

**Step 22:** Stop.