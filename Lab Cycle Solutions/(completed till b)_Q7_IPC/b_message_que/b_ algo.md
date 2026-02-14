# b) Using message queue

**Step 1:** Start

**Step 2:** Define a structure `msg_buffer` containing a `long` for message type and a `char` array for the message text.

**Step 3:** Declare variables for the message key, queue ID, an instance of the message structure, and the process ID.

**Step 4:** Generate a unique system key using the `ftok` function with the file "progfile" and identifier 65.

**Step 5:** Create a message queue using `msgget` with the generated key, 0666 permissions, and the IPC_CREAT flag.

**Step 6:** If the message queue ID is -1, print an error message indicating failure and terminate the program.

**Step 7:** Create a child process using the `fork` system call.

**Step 8:** Check if the process ID equals 0 to execute the child process logic.

**Step 9:** Inside the child process, use `msgrcv` to wait for and read a message of type 1 from the queue.

**Step 10:** Print the received string to the console.

**Step 11:** Calculate the length of the string and reverse it by swapping characters from the start and end indices.

**Step 12:** Print the reversed string, set the message type to 2, and use `msgsnd` to send the reversed string back to the queue.

**Step 13:** If the process ID is not 0, execute the parent process logic.

**Step 14:** Prompt the user to enter a string and store it in the message buffer.

**Step 15:** Copy the input string into a temporary variable to preserve the original value.

**Step 16:** Set the message type to 1 and use `msgsnd` to send the input string to the queue.

**Step 17:** Print the sent string, then use `msgrcv` to wait for and read the message of type 2 (the reversed string) from the queue.

**Step 18:** Compare the received string with the temporary original string.

**Step 19:** If the strings are identical, print that the string is a palindrome; otherwise, print that it is not.

**Step 20:** Remove the message queue from the system using `msgctl` with the IPC_RMID flag.

**Step 21:** Stop
