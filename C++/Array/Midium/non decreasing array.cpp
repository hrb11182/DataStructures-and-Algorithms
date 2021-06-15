//Non decreasing array
/*
Non decreasing array may be defined as an array such that no number in the array behind any number is smaller then that for ex- [4, 2, 5] the given example is a decreasing array because "2" comes after "4" and it is smaller then its previous element(4) but in other hand if we convert the given array to [1, 2, 5] by changing "4" to "1" this will become a non decreasing array.
*/

/*
Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

 

Example 1:

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:

Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.
 

Constraints:

n == nums.length
1 <= n <= 104
-105 <= nums[i] <= 105
*/