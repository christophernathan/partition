# Partition

## About

A simple dynamic programming implementation of the partition problem and its variations. The original problem is as follows: Given an array or list of integers, is it possible to split the integers into 2 distinct subsets so that the sum of integers in each subset is equal.

## Analysis

My implementation for this problem utilizes a boolean array with number of elements equal to the sum of each integer in the given array. Each integer in the array is processed sequentially. The elements in the boolean array that are true represent sums that can be made with any arbitrary subset of integers. Thus, each subsequent integer expands upon the possible sums that have already been recorded. My implementation generalizes the original problem, so `partition()` prints the entire boolean array. It will be possible to divide the given array of integers into 2 complementary subsets if T[N/2] is true, where N is the sum of all the integers. Note that this will never be true if the total sum of the integers is odd, and due to integer division, T[N/2] will not be logical if N is odd.

One variation of this problem considers duplicate integers in the given array. The input for this variation is an array of integers, with a complementary array of integer quantities. For example, there will be `D[1]` of `C[1]` available to sum. My implementation of `partition_duplicates()` follows similar logic as the original problem solution, but instead of just adding 1 of the integer currently being processed, the integer can be added a maximum number of times equal to the quantity of it that exists in the array. This is accomplished with the innermost loop, where k goes from 0 to `D[i]`, where i is the index of the integer currently being processed.

A final variation of the problem considers an unlimited number of each integer in the given array. A coin changer is a common analogy for this problem, where one wants to find the number of ways to make change for a query sum. In my implementation, I utilize an int array instead of a boolean array because we want to tally the number of ways to make change. The logic is similar, though, in that subsequent sums in the array add the change potential of previous sums, where the subsequent sum is any previous sum plus the value of the integer currently being processed.

## Usage

Clone the repo, `cd` into the partition directory, and run `g++ -o partition partition.cpp`. Then, run the executable with `./partition`.