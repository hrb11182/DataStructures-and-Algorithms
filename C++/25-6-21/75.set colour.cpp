/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
Example 3:

Input: nums = [0]
Output: [0]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is 0, 1, or 2.

*/


//T-Complexity - O(log n)

class Solution {
public:
	void sortColors(vector<int>& nums) {
		sort(nums.begin(), nums.end());
	}
};

////T-Complexity - O(n)

class Solution {
public:
	void sortColors(vector<int>& nums){
		int n = (int)nums.size();
		int first=0, second=0, third = 0;
// Tken variables to store the number of counts of all three numbers(0,1,2) representing the colors.
		for(int i=0;i<n;i++){
			if(nums[i] == 0){
				first++;
			}else if(nums[i] == 1){
				second++;
			}else{
				third++;
			}
		}
// One thing to be noted that here three loop is used to traverse the one array only.


// This loop is counting the occurance of each element in array.
		for(int i  = 0; i<first; i++){
			nums[i] = 0;
		}
// This loop will traverse from first to the position equal to the count of 0.
		for(int i=first; i<first+second; i++){
			nums[i] = 1;
		}
// This is traversing from one more  then last element of first till the last element of second
		for(int i = first+second; i<first+second+third; i++){
			nums[i] = 2;
		}
// This is traversing from one more  then last element of second till the last element of third.

	}
};


//T-complexity = 

/*
We will take three pointers high, low, and mid. here mid and low will be initialised with 0 initially and high will be (n-1). We will move mid if we encounter 0 we will swap mid with low and increment low as well as mid and if we get 2 we swap mid with high and decrement high but if we get 1 then we do nothing and increment mid it will go on untill mid remains smaller then or equal to high.
*/ 

class Solution {
public:
	void sortColors(vector<int>& nums){
		int low = 0;
		int mid = 0;
		int high = n-1;

		while(mid<=high){
			int x = nums[m];
			if(x==0){
				swap(nums[low], nums[mid]);
				low++;
				mid++;
			}else if(x==1){
				mid++;
			}else{
				swap(nums[high], nums[low]);
				high--;
			}
		}
	}
};
//ERROR: N is not declared.