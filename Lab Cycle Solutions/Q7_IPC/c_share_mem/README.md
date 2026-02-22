# Algorithm

**Step 1:** Start

**Step 2:** Create a shared memory object with read and write permissions and set its size to a fixed capacity.

**Step 3:** Map the shared memory object into the process's address space to allow direct access via a pointer.

**Step 4:** Create and initialize a named semaphore with a value of zero to synchronize operations between processes.

**Step 5:** Create a child process using the system call to split execution into parent and child branches.

**Step 6:** Check if the current process is the child process (process ID is zero).

**Step 7:** Inside the child process, wait on the semaphore until the parent signals that data has been written.

**Step 8:** Read the three strings from the shared memory location.

**Step 9:** Concatenate the three strings into a single string with spaces separating them.

**Step 10:** Write the combined string back into the shared memory, overwriting the previous content.

**Step 11:** Close the semaphore, unmap the memory, and terminate the child process.

**Step 12:** If the current process is the parent, prompt the user to enter three separate strings and remove trailing newlines.

**Step 13:** Format and write the three strings into the shared memory, separated by newlines.

**Step 14:** Signal the semaphore to notify the child process that input data is available.

**Step 15:** Wait for the child process to complete its execution.

**Step 16:** Read the concatenated string from the shared memory into a local buffer.

**Step 17:** Iterate through the string and toggle the case of each character (convert lowercase to uppercase and vice versa).

**Step 18:** Print the final modified string to the console.

**Step 19:** Close the semaphore, unmap the shared memory, and unlink the shared memory object to clean up resources.

**Step 20:** Stop.
