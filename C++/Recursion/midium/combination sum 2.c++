/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

//BRUTEFORCE
/*
This approach will be same as the combination sum 1 in that question if we picked a number then we reset the loop to index 0 because we were allowed to use a number multiple times but here we dont need to reset because we are not allowed to use an element twice in a combination and we also need to remove the duplicate combinations so we will store the result in a hash set.
*/

//S-OPTIMAL - (k*x)
//T-OPTIMAL - O(2^n* k (number of elements in combination))
/*
In this approach we take a function which will take three parameters (starting index of recursive call , Target, and a data structure to store results) initially we start from idx 0 we will pick 0 th element and move till the nth element and we decide that we need to pick or not if same element exist on different index positions so we will pick 1 out of them which is on the smaller index position and we will update the starting index position,our target and insert that element in our defined datastructure number of elements we decide to pick for our first position of our combination for every pick for first position we that number of recursion call will opccur then for the second element of combination and then for 3rd and so on.
*/

class Solution {
	public:
		void findCombination(int index, int target, vector<int> &array, vector<vector<int>> &answer, vector<int>& ds) {
			if(target==0){
				answer.push_back(ds);
				return;
			}
// Above condition states that if the target become zero means we are done with the combination so we can add that combination to our answer array.
			for(int i = index; i<arr.size();i++){
// Loop to loop through all the elements of array.
				if(i>index && array[i]==array[i-1]) continue;
// Condition to make sure that we dont pick a same value at the same index(avoiding duplication).
				if(array[i]> target) break;
// If elements exceeds target break because wew are not going to get anything since array is sorted every thing on the right will be greater then the target. 
				ds.push_back(array[i]);
// If the above two conditions dosent satisfies then add that element to ds.
				findCombination(i+1, target - array[i], array, answer, ds);
// Recursive call.
				ds.pop_back();
// If combination cant be formed/completed pop out all the stored elementin ds.
			}
		}

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
// First of all we need to sort the array.
        vector<vector<int>> answer;
// To store answer.
        vector<int> ds;
// To store a single cobination at a time and once combination is formed it will be transfered to answer.
        findCombination(0, target, candidates, answer, ds);
// Calling the function to find the combination.
        return answer;
    }
};