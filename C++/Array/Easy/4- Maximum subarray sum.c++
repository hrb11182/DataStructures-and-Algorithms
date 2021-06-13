/*
//BRUTEFORCE -:
 In this we take three loops and start iterating the array and try to find the sub array.

 
Best approach-:(Kadane's algorithm)
//T-OPTIMAL O(n)
//S-OPTIMAL O(1)
    1-We will traverse the array and and take two variables "sum" and "maxsum".

    2-sum will be initialised to zero and maxsum will store the 1st element of array.

    3- And the moment sum exceeds the maxsum we will update the value of maxsum and make it equal to sum.

    4- And whenever sum's value become negetive we will  convert it to "0". 

Take two variables one will calculate the max sum and another will 
*/
#include <bits/stdc++.h>

using name space std;

int main()
{
    int maxSubarraySum(vector<int> & nums)
    {
        int sum = 0;
        int max_sum = INT_MIN;
        //LEARN INT_MIN.
        for (auto it : nums)
        {
            sum += it;
            maxi = max(sum, maxi);
            if (sum < 0)
                sum = 0;
        }
        return maxi;
    }
}
