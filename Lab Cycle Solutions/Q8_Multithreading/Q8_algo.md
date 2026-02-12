# 8) Multithreading      

**Step 1:** Start.

**Step 2:** Check if the argument count is sufficient (greater than 1). If not, print an error and go to Step 11 (Stop).

**Step 3:** Convert the command-line string arguments into an integer array and store them.

**Step 4:** Initialize the `Thread` structure containing the integer array and its size.

**Step 5:** Create and launch **Thread 1** to calculate the **Mean**.

* *Thread 1 Logic:* Iterate through the array to sum all elements, divide by the count, and store the result in the global `mean` variable.

**Step 6:** Create and launch **Thread 2** to calculate the **Median**.

* *Thread 2 Logic:* Create a local copy of the array, sort it, find the middle value (handling even/odd sizes), store the result in the global `median` variable, and free the local memory.

**Step 7:** Create and launch **Thread 3** to calculate the **Standard Deviation**.

* *Thread 3 Logic:* Calculate the mean locally, sum the squared differences between each element and the mean, calculate the square root of the average variance, and store it in the global `std_dev` variable.

**Step 8:** Wait ( `pthread_join` ) for **Thread 1**, **Thread 2**, and **Thread 3** to finish their execution.

**Step 9:** Print the final calculated values for Mean, Median, and Standard Deviation.

**Step 10:** Free any remaining resources (if applicable).

**Step 11:** Stop.
