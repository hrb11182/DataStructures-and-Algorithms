/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Follow-up: Could you solve the problem in linear time and in O(1) space?

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
*/

//Bruteforce
//T-Complexity - O(n^2)
//S-complexity o(1).
/*
Pick one element and traverse the array and find that it occurs N/3 numbers of time or not if yes that willbe answer else do the same with the next element.
*/


//Hashing.
//T-Complexity - O(nlogn)
//S-Complexity - O(n)
/*
Store the number and its frequency in hash table and the elements appear equal to or more then n/3 times will be the majority element.
*/


//Boyre Moore Voating algorithm
//T-Complexity - 
//S-Complexity - 

/*
1- At max we can have two majority elements.
2- So we define two variables to store that elements.
3- Two more variable sto ster there count.
4- If we will encounter first two values we store it in  both variable and calculate its count.
5- Now when we reach the third variable we will keep on decreasing the count of both the variables untill we finish encountering the third element in this process if any of the variables count become 0 we replace that number with the third one and no we increment its count by 1 and we keep on incrementing untill we end up with that number.
*/

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int sz =  nums.size();
		int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
		for(i=0; i<sz; i++){
			if(nums[i] == num1)
				count1++;
			else if(nums[i] == num2)
				count2++;
			else if(count1 == 0){
				num1 = nums[i];
				count1 = 1;
			}else if(count2 == 0){
				num2 = nums[i];
				count2 = 1;
			}else{
				count1--;
				count2--;
			}
		}
		vector<int> ans;
// To store answers.
		count1 = count2 =0;
// Initialising count 1 and 2 to 0.
		for(i=0; i<sz; i++){
			if(nums[i] == num2)
				count2++;
			else if(nums[i] == num1)
				count1++;
		}
// Iterating the array and finding the frequency of the both the nums.
		if(count1>sz/3)
			ans.push_back(num1);
		if(count2 > sz/3)
			ans.push_back(num2);
// Checking which one matches the given condition.
		return ans;
	}
};

