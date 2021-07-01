/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/



// Shifting all the elements "k" step froward from there exact position in array if there is no space left move them at starting of array.

//Time - O(n)
//Space - O(n)

/*
 Remove k elements from the back of array and store it in some other array say that secondary array and now move the rest of the element from array kth step forward and after doing that add all the elements removed earlier to the starting of array in order they were stored in the secondary array.
*/ 

//Time - O(n)
//Space - O(1)

/*
Now we can solve this problem by first reversing the k elements from the end and then rest of the element and after reversing both the parts of array reverse complete array now the resulting array after this three rverse will be the answer.

Rverse function - will work like swap 1st element with last 2nd with 2nd last and so on we can take two pointers to do so.
*/

class Solution {
public:
	void reverse(vector<int>& num, int low, int high){
		while(low<high){
			swap(num[low], num[high]);
			low++;
			high--;
		}
	}
	void rotate(vector<int>& nums, int k) {
		int n = (int)nums.size();
		k = k%n;
// This will work if we encounter a value more then the array size.
		reverse(nums, 0, n-k-1);
		reverse(nums, n-k, n-1);
		reverse(nums, 0, n-1);
	}
};