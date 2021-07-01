/*
You are given an integer array nums (0-indexed). In one operation, you can choose an element of the array and increment it by 1.

For example, if nums = [1,2,3], you can choose to increment nums[1] to make nums = [1,3,3].
Return the minimum number of operations needed to make nums strictly increasing.

An array nums is strictly increasing if nums[i] < nums[i+1] for all 0 <= i < nums.length - 1. An array of length 1 is trivially strictly increasing.

 

Example 1:

Input: nums = [1,1,1]
Output: 3
Explanation: You can do the following operations:
1) Increment nums[2], so nums becomes [1,1,2].
2) Increment nums[1], so nums becomes [1,2,2].
3) Increment nums[2], so nums becomes [1,2,3].
Example 2:

Input: nums = [1,5,2,4,1]
Output: 14
Example 3:

Input: nums = [8]
Output: 0
 

Constraints:

1 <= nums.length <= 5000
1 <= nums[i] <= 104
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
// Vriable to store the number of addition to be done.
        for(int i=1; i< nums.size(); i++){
// Iterating through each element of array.
        	if(nums[i]<=nums[i-1]){
// Comparing them.
        		int change = nums[i-1]-nums[i]+1;
// Calculating number to be added to make them strictly.
        		count+=change;
// Adding thet number to count.
        		nums[i]+= change;
// Adding it to present numbr to make array strictly increasing.
        	}
        }
        return count; 
    }
};