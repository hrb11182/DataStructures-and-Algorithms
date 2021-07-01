/*
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]
 

Constraints:

1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6
*/

//Brute force
//t=O(n^2)
/*
In this we are going to traverse the array from begining to the present num for ex for 1st idx from 0 to 1, for 2nd idx 0 to 2 and so on for every index we need to traverse the array onec and calculate the sum.
*/

//t=O(n)
//s=O(1)

/*
Here inmstead of adding all elements from begning we can add the new element  to the previous sum calculated by us for ex 0+1=1 now we introduced 2 so insted of doing 0+1+2 we can do 1+2.
*/


class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1; i<nums.size(); ++i)
        	nums[i] += nums[i-1];
// Modifyng the current element of nums in order to store the sum of all its previous elements we can take another variable result to do so.
        return nums;
    }
};