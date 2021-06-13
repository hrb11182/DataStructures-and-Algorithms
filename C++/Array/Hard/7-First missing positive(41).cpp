//LEARN - BITWISE OPERATION.
/*
                First Missing Positive

Given an unsorted integer array nums, find the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
 

Constraints:

1 <= nums.length <= 5 * 10^5
-2^31 <= nums[i] <= 2^31 - 1
*/

/*
//ALGORITHM 
//S-OPTIMAL O(1) -:
    1- Start traversing the array and place the number "i" at "ith" index for ex if 3 is present on 1st index then swap it with the element presene at the 3rd index.

    2- Ignore the negetive numbers from the list.

    3- Ignore the numbers greater then the size of the array.

    4- Our answer will be the first element index which doesn't contain element equal to its index.for ex if 2 is not on the second index so 2 is our answer.
*/
/*
//ALGORITHM
//S-OPTIMAL O(n)
//T-OPTIMAL O(n)
    1- Make a hash table traverse through the array and store the values in hash table.
    2- Again traverse the array and try to find the values equal to the index position in the hash table.for ex if we are at 1st index we look for the value 1 in hash table if present we move forward but if not we will return that index as answer.
*/
/*
//ALGORITHM
// S-OPTIMAL O(1)
    1- Traverse the array and make all the elements "1" whose value is either greater then the size of the array or less then zero.
    2- Traverse the array - "Suppose we are at ith index and value n is stored on that index then go to the nth(i,e -(n-1)) element of array and make it negative" - for example - we are at 1st index and 3 stored in that inde so we go to the third element of array that is 2nd index and we make it negetive.
    3- Again traverse through the array and the moment you encounter the positive value on any index return the value of that index as answer.
*/

// TIPS -:There is a corner case if every index has the element equal to it then we can return the   answer either by adding 1 to the value of last index or we can return the index itself after adding 1 to it.

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int firstMissingPositive(vector<int> & nums)
    {
        bool contains_one = false;
        // To check thepresence of 1.
        for (int x : nums)
        // Range based loop.
        {
            if (x == 1)
            // If 1 found.
            {
                contains_one = true;
                // Make the boolean true.
                break;
            }
        }
        if (!contains_one)
            // If it doesn't contain 1 then return 1.
            return 1;
        int n = nums.size();
        // Making a variable to store the size of array.
        if (n == 1)
            // If max size is 1.
            return 2;

        for (int i = 0; i < n; ++i)
            if (nums[i] <= 0 || nums[i] > n)
                nums[i] = 1;
        // Converting all the negetive numbers and the numbers greater then the size of array to 1.

        for (int i = 0; i < 1; ++i)
        {
            int x = abs(nums[i]);
            if (nums[x - 1] > 0)
                nums[x - 1] *= -1;
        }
        // This loop goes to the (x-1)th index of array and make it negetive.
        for (int i = 0; i < n; ++i)
            if (nums[i] > 0)
                return i + 1;
        // If any index is found of positive integer return by adding 1 to that index.

        return n + 1;
    }
}