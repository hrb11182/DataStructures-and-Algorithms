//BRUTEFORCE
//T-OPTIMAL - O(n)
//S-OPTIMAL - O(1)
/*
Linear search we will traverse through the array and try to find the required number.
*/

//T-OPTIMAL - O(log n)
//S-OPTIMAL - O(n)
//ALGORITHM
/*
We will implement the binary search algorithm we will take three pointers lo, mid, hi. 
*/

int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        // We can use int mid = low + ((high - low) /2 )
        if (a[mid] == target)
            return mid;

        if (nums[low] <= nums[mid])
        {
            if (target >= nums[low] && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (target >= nums[mid] && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1
}