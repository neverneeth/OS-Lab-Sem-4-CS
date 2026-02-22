# Algorithm 1

**Step 1:** Start

**Step 2:** Check if the total number of command-line arguments provided is exactly three.

**Step 3:** If the argument count is not three, print an error message and terminate the program.

**Step 4:** Convert the second command-line argument from a text string into an integer value and store it.

**Step 5:** Convert the third command-line argument from a text string into an integer value and store it.

**Step 6:** Calculate the sum of the two stored integer values.

**Step 7:** Print the two individual integer values along with their calculated sum to the console.

**Step 8:** Stop.


# Algorithm 2

**Step 1:** Start

**Step 2:** Create a new child process by duplicating the current parent process.

**Step 3:** Check if the current execution stream belongs to the newly created child process.

**Step 4:** If it is the child process, prepare a list of arguments containing the name of the external adder program, two numerical values as text strings, and a termination marker.

**Step 5:** Have the child process execute the external adder program using the prepared list of arguments, replacing its current memory image entirely.

**Step 6:** If the current execution stream belongs to the parent process, pause and wait for the child process to completely finish its execution.

**Step 7:** Once the child process has finished, have the parent process print a message stating that this is the second program.

**Step 8:** Stop.
