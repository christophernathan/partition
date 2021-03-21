# partition

## analysis

A simple dynamic programming implementation of the partition problem and its variations. The original problem is as follows: Given an array or list of integers, is it possible to split the integers into 2 distinct subsets so that the sum of integers in each subset is equal. My implementation for this problem utilizes a boolean array with number of elements equal to the sum of each integer in the given array. Each integer in the array is processed sequentially. The elements in the boolean array that are true represent sums that can be made with any arbitrary subset of integers. Thus, each subsequent integer expands upon the possible sums that have already been recorded. My implementation generalizes the original problem, so `partition()` prints the entire boolean array. It will be possible to divide the given array of integers into 2 complementary subsets if T[N/2] is true, where N is the sum of all the integers. Note that this will never be true if the total sum of the integers is odd, and due to integer division, T[N/2] will not be logical if N is odd.

