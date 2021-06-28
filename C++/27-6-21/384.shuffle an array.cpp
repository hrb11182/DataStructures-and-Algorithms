/*
Given an integer array nums, design an algorithm to randomdomly shuffle the array.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the integer array nums.
int[] reset() Resets the array to its original configuration and returns it.
int[] shuffle() Returns a randomdom shuffling of the array.
 

Example 1:

Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must be equally likely to be returned. Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the randomdom shuffling of array [1,2,3]. Example: return [1, 3, 2]

 

Constraints:

1 <= nums.length <= 200
-106 <= nums[i] <= 106
All the elements of nums are unique.
At most 5 * 104 calls will be made to reset and shuffle.

*/ 

/*
We will take a pointer and make it point on the last element of array initially and now we choose a randomdom element from rest of the elements present in left side of the selected element and swap them and move our pointer one step ahed towards left and repeat the process again.

*/

class Solution {
public:
    

    vector<int>original;
    vector<int>random;
    Solution(vector<int>& nums) {
        original=nums;
        random=nums;
    }
// We defined two arrays original and random and copied the nums in to it.

    vector<int> reset() {
        return original;
    }
// Reset function whenever the reset function is called we return original array.

    vector<int> shuffle() {
        if(random.empty())
            return random;
// If random is empty return the array we need not to do any thing.
        int n=random.size();
        for(int i=n;i>0;i--)
// Traversing from the last.
            swap(random[i-1],random[rand()%i]);// Learn about rand function.
// This function will swap the element on which we are and the elements found by the rand function. 
        return random;
    }
};