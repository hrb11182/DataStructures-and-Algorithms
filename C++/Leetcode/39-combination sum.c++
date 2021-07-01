/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
Example 4:

Input: candidates = [1], target = 1
Output: [[1]]
Example 5:

Input: candidates = [1], target = 2
Output: [[1,1]]
 

Constraints:

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
All elements of candidates are distinct.
1 <= target <= 500
*/


//ALGORITHM
//T-OPTIMAL o(2^T + K)
//S-COMPLEXITY O(BASED ON THE NUMBER OF COMBINATIONS)

// Take a datastructure (array, vector etc) to store the combination.
// Here there will be two conditions that you are going to pick a number to combine it to form the target or not.
// If you pick then you will insert that number in the array or vector, you will subtract that number from target and modify the value of target and you will again iterate the array from the very first index in oprder to find the new target.
// If you didn't pick then you will go to the next index position of array and you keep on moving untill you pick a number or you hit the above case.
// Both condition will work recursively.

class Solution {
public:
	void findCombination(int index, int target, vector<int> &candidates, vector<vector<int>> &allCombinations, vector<int> &combination){
		if(index == candidates.size()){
			if(target == 0){
				allCombinations.push_back(combination);
			}
			return;
// the above condition will work when we reached the end of array and target become 0 means we found the combination so we will add that particular combination to the main answer array.
		}
		if(candidates[index] <= target){
			combination.push_back(candidates[index]);
			int newtarget = target - candidates[index];
			findCombination(index, newtarget, candidates, allCombinations, combination);
// Recursive call.
			combination.pop_back();
		}
		findCombination(index + 1, target, candidates, allCombinations, combination);
	}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> allCombinations;
// This is to store all the possible combinations to be returned as the answer.
        vector<int> combination;
// To store a combination during recursive operation.
        findCombination(0, target, candidates, allCombinations, combination);
// 0 because we will start traversing through the 0th index initially.
        return allCombinations;
    }
};
