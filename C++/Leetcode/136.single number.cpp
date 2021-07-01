/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.

*/

// T-Complexity- O(n)
// S-Complexity - O(1)

// We are going to use the xor operator here xor of two same numbers(A^A) will return 0 and the xor of a number with 0 will return that number(A^0 = A).


class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int n = (int)nums.size();
		int ans = 0;
		for(int i = 0; i<n; i++){
			//ans=ans^nums[i];
			ans^=nums[i];
		}
		return ans;
	}
};