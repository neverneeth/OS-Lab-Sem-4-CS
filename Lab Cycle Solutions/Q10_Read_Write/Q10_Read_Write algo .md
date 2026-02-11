# Algorithm: Writer-Priority Readers-Writers

This algorithm ensures that writers are given priority over readers to prevent writer starvation.

## 1. Main Process Algorithm
* **Step 1: Start.**
* **Step 2: Resource Allocation.** Allocate memory for a shared data structure containing reader/writer counts and semaphores.
* **Step 3: Initialization.** * Set reader count (`rc`) and writer count (`wc`) to 0.
    * Initialize four semaphores (`mutex`, `w_mutex`, `rw_mutex`, `r_mutex`) to 1 (unlocked).
* **Step 4: Thread Spawning.** Create multiple Reader and Writer threads concurrently.
* **Step 5: Synchronization.** Wait for all threads to finish their execution (Joining).
* **Step 6: Cleanup.** Destroy all semaphores and free the allocated memory.
* **Step 7: Stop.**

---

## 2. Reader Thread Algorithm
* **Step 1: Turnstile Entry.** Wait on `r_mutex` and immediately signal it. This acts as a gate that closes if a writer is waiting.
* **Step 2: Update Reader Count.** Wait on `mutex`, increment `rc`.
* **Step 3: Lock File Access.** If this is the first reader (`rc == 1`), wait on `rw_mutex` to block writers from the file.
* **Step 4: Release Count Lock.** Signal `mutex`.
* **Step 5: Critical Section.** Perform the reading operation.
* **Step 6: Update Reader Count.** Wait on `mutex`, decrement `rc`.
* **Step 7: Unlock File Access.** If this is the last reader (`rc == 0`), signal `rw_mutex` to allow writers to access the file.
* **Step 8: Finalize.** Signal `mutex` and terminate thread.

---

## 3. Writer Thread Algorithm
* **Step 1: Update Writer Count.** Wait on `w_mutex`, increment `wc`.
* **Step 2: Close Turnstile.** If this is the first writer (`wc == 1`), wait on `r_mutex` to prevent new readers from entering.
* **Step 3: Release Count Lock.** Signal `w_mutex`.
* **Step 4: Lock File Access.** Wait on `rw_mutex` for exclusive access to the resource.
* **Step 5: Critical Section.** Perform the writing operation.
* **Step 6: Unlock File Access.** Signal `rw_mutex`.
* **Step 7: Update Writer Count.** Wait on `w_mutex`, decrement `wc`.
* **Step 8: Open Turnstile.** If this is the last writer (`wc == 0`), signal `r_mutex` to allow readers to enter again.
* **Step 9: Finalize.** Signal `w_mutex` and terminate thread.
