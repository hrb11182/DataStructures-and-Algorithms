/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

//BRUTEFORCE
//T-OPTIMAL - O(n)
/*
We can implement a linear search in this problem we will use two loops one from the stating of the array and second from the back of the array both will print the index when the element is found.
*/

//T-OPTIMAL - O(log n)
/*
Here we can use the upper and lower bound {upper bound will always return the nearest greater element of the target for ex [1,2,3,4,5,10,12] if we are searching 5 here then it will return 10 next greater element}{lower bound will return that specific element if present if not it will return the index of nearest possible greater for ex- [12, 25, 51, 52] suppose we are searching 28 so it will return the index of 51} in case multiple target values in the array it will return the index of its first occurance.
*/

/*
Solution with the binary search.
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	vector<int> result;
    	int firstIndex = firstPosition(nums, target);
    	int lastIndex = lastPosition(nums, target);
    	result.push_back(firstIndex);
    	result.push_back(lastIndex);
    	return result;
    }
    int firstPosition(vectot<int>& nums int target){
    	int mid;
    	int left = 0;
    	int right = nums.size()-1;
    	int position = -1;

    	while(left<= right){
    		mid = ( left + right) >>> 1;
    		if(nums[mid] == target){
    			position = mid;
    			right  = mid - 1;
    		}else if(nums[mid] < target){
    			left = mid + 1;
    		}else{
    			right = mid - 1;
    		}
    	}
    	return position;
    }

    int lastPosition(vector<int>& nums int target){
    	int mid;
    	int left = 0;
    	int right = nums.size()-1;
    	int position = -1;

    	while(left<= right){
    		mid = ( left + right) >>> 1;
    		if(nums[mid] == target){
    			position = mid;
    			leftt  = mid + 1;
    		}else if(nums[mid] < target){
    			left = mid +1;
    		}else{
    			right = mid + 1;
    		}
    	}
    	return position;
    }
};