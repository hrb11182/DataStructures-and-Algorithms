/* Question -:
                            1. Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/

//Brute force approach-:

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> twoSum(vector<int> & nums, int target)
    {
        /* Initialised a vector which takes the vector and an integer as an input*/
        vector<int> result;
        /*Another vector to store the result*/
        for (auto it1 = nums.begin(); it1 != nums.end(); ++it1)
        {
            /*This loop is pointing on one element of vector say 0th and loop given below traverse the rest of the array to find the next possible element of pair*/
            auto it2 = find(it1 + 1, nums.end(), target - *it1);
            /* Auto(to auto detect datatypes) key word is used to initialise the iterator and "*" at it2 is used to access the value where it 2 is pointing*/
            if (it2 != nums.end())
            {
                /*if it2 hasn't got the end means element found*/
                result.push_back(it1 - nums.begin());
                /* This two lines is tho get the index position where the iterator is present*/
                result.push_back(it2 - nums.begin());
                /* Since iterator doesn't have any indexing scheme so if we substract nums.begin from the present iterators position then it will return the present iterator position for ex nums.begin() = 0 and if iterator is at idx 5 then 5-0 will return 5 position of our iterator*/
                break
            }
        }
        return result;
    }
}