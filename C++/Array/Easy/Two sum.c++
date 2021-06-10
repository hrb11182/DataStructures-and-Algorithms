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
    vector<int> twoSum(vector<int> nums, int target)
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
                break;
            }
        }
        return result;
    }
}

//  Second approach will be using hash table.

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> twoSum(vector<int> nums, int targetSum)
    {
        // Initialised a vector which takes the vector and an integer as an input
        unordered_map<int, int> umap;
        //Initialised a hash table using unordered map.
        for (int i = 0; i < nums.size(); ++i)
        {
            //Looping through the vector taken as an input.
            int num = nums[i];
            //Copying the element at ith index to a new variable.
            int targetNum = targetSum - num;
            //Calculating the value of the second number we need to find from the array.
            auto it = umap.find(targetNum);
            //initializing an terator and trying to find the second num in our hash table..
            if (it != umap.end())
            {
                //If ump.end is not found that means second number is found.
                return {it->second, i};
                //Due to the auto keyword iterator is of unordered map type so first value will be the value at ith idex and second value is the index itself since we need to reurn the value of index so we need to return it->second {because it is stored in that way in unordered map see line below this comment leave the bracket} .
            }
            umap[num] = i;
            //Storing in as as key value pair here num actual value is acting like a key and index position is a value.
        }
        return {};
    }
}