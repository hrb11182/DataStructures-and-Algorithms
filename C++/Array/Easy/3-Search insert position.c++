#include <bits/stdc++.h>

using namespace std;

int main()
{
    int searchInsert(vector<int> & nums, int toInsert)
    // Function to take vector of int and a number to be inserted in array.
    {
        int left_ptr = 0, right_ptr = nums.size() - 1;
        // Dclared the left and right pointer.
        while (left_ptr <= right_ptr)
        {
            mid_ptr = left_ptr + (right_ptr - left_ptr) / 2;
            // Calculating the value of the mid pointer.
            if (nums[mid_ptr] < toInsert)
            {
                left_ptr = mid_ptr + 1;
            }
            else if (nums(mid_ptr) > toInsert)
            {
                right_ptr = mid_ptr - 1;
            }
            else
            {
                return mid_ptr;
            }
        }
        return left_ptr;

        // left_ptr need to be returened when ever the condition {left_ptr<=right_ptr}will be used.

        // All the above conditions are the conditions of binary search were we find the pivot point that is mid_ptr in our case and check that element we are searching is greater then pivot if yes check for the element in right half of the array else left half of array.
    }
}