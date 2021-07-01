/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/


//T-COMPLEXITY - O(n)
//S-COMPLEXITY - O(1)

/*
Take two variables count and max both will be initially initialised to zero we start iterating the array when we find zero we initialise the count to zero and once we find 1 we increase the count by 1 and compare it with max if max is smaller then that update max and make it equal to count.
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxi = 0;
        for(int i = 0; i<nums.size(); i++){
        	if(nums[i] == 1){
        		count++;
        	}else{
        		count = 0;
        	}
        	maxi = max(maxi, count);
        }
        return maxi;
    }
};