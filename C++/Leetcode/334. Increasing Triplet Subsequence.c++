/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 

Constraints:

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)return false;
// It is impossible to find the triplet in thr array of 3 elements.
        int left = INT_MAX;
        int mid = INT_MAX;
// Taken two pointers and and initialised them with the max value we can say infinite.
        for(int i=0; i<nums.size(); i++){
// Iterating through the array.
        	if(nums[i]>mid) return true;
// If present element become greater then mid then we got our answer.
        	else if(nums[i]>left && nums[i]<mid)mid=nums[i];
// If present element is greater then the left but less then the mid so make it mid.
        	else if(nums[i]<left)left=nums[i];
// If present element is smaller then left make it left.
        }
// In this we only want to achive this condition.(left<mid<nums[i]).
        return false;
    }
};