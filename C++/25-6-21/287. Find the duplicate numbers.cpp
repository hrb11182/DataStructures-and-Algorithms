/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [1,1]
Output: 1
Example 4:

Input: nums = [1,1,2]
Output: 1
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?
*/

//Bruteforce.
//Time - O(nlogn)
//Space - O(n)
/*
1- sort the array.
2- Traverse the array wev will find some consicutive indexes having same value so we will return that value.
*/

//Hashing
//Time - O(n)
//Space - O(n)
/*
We will create an hash and we will store all the elements of the array with there respective frequencies and if we get the frequency of any number greater then the 1 we will return that value.
*/


//Linkedlist cycle metheod.

/*
Tortroise method using two  pointers slow and fast slow moves by one step and fast by 2 untill collision occur if collided then we will make fast to point on the first element and now both will move by 1 step untill they collid if collid thet will be the answer.
*/


class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = nums[0];
// Initialised slow pointer.
		int fast = nums[0];
// Initialised fast pointer.
		do{
			slow = nums[slow];
// Moving slow one step forward.
			fast = nums[nums[fast]];
// Moving fast two step forward.
		}while(slow != fast);
// Untill both collide.
		fast = nums[0];
// Setting fast to 0.
		while(slow != fast){
			slow = nums[slow];
			fast = nums[fast];
		}
// Again moving both by one step forward if they collid that number will be duplicate.
		return slow;
// Returning the answer.
	}
};