#  REaders Writers Algorithm

**Step 1:** Start the program.

**Step 2:** Declare global semaphores named `resource`, `readTry`, and `rmutex` to manage synchronization.

**Step 3:** Declare global integer variables `readCount` initialized to 0 (to track active readers) and `sharedData` initialized to 0 (the resource being shared).

**Step 4:** Define the `main` function and initialize the semaphores `resource`, `readTry`, and `rmutex` with a value of 1 using `sem_init`.

**Step 5:** Create an array of `pthread_t` identifiers for reader threads and writer threads.

**Step 6:** Start a loop to create 3 reader threads using `pthread_create`, passing a unique index to each thread and assigning them to execute the `reader` function.

**Step 7:** Start a loop to create 2 writer threads using `pthread_create`, passing a unique index to each thread and assigning them to execute the `writer` function.

**Step 8:** Begin the definition of the `reader` function, which accepts the thread ID as an argument.

**Step 9:** Inside the `reader` function, enter a loop to perform multiple read operations.

**Step 10:** Execute `sem_wait(&readTry)` to check if it is safe to enter (blocks if a writer is waiting) and `sem_wait(&rmutex)` to protect the `readCount` variable.

**Step 11:** Increment the `readCount` variable by 1 to indicate a new reader has entered.

**Step 12:** Check if `readCount` is equal to 1; if true, execute `sem_wait(&resource)` to lock the resource so no writers can enter while readers are present.

**Step 13:** Execute `sem_post(&rmutex)` and `sem_post(&readTry)` to release the entry locks for other readers.

**Step 14:** Enter the Critical Section, read the current value of `sharedData`, and print "Reader is reading".

**Step 15:** After reading, execute `sem_wait(&rmutex)` to gain access to the `readCount` variable again.

**Step 16:** Decrement the `readCount` variable by 1.

**Step 17:** Check if `readCount` is equal to 0; if true, execute `sem_post(&resource)` to unlock the resource, allowing writers to enter.

**Step 18:** Execute `sem_post(&rmutex)` to release the lock on `readCount` and repeat the loop or exit.

**Step 19:** Begin the definition of the `writer` function, which accepts the thread ID as an argument.

**Step 20:** Inside the `writer` function, enter a loop to perform multiple write operations.

**Step 21:** Execute `sem_wait(&readTry)` to lock the entry gate, preventing new readers from entering, and `sem_wait(&resource)` to ensure exclusive access to the shared data.

**Step 22:** Enter the Critical Section, increment the `sharedData` variable by 1, and print "Writer is writing" with the updated value.

**Step 23:** Execute `sem_post(&resource)` to release the shared data and `sem_post(&readTry)` to reopen the entry gate for readers or other writers.

**Step 24:** Back in the `main` function, use `pthread_join` in a loop to wait for all reader and writer threads to finish their execution.

**Step 25:** Destroy the semaphores `resource`, `readTry`, and `rmutex` using `sem_destroy` to clean up system resources.

**Step 26:** Stop.
