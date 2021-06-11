#include <bits/stdc++.h>

using name space std;

int main()
{
    vector<int> plusOne(vector<int> & digits)
    //Function that takes vector of integers as input and name as the digits.
    {
        int idx == digits.size() - 1;
        // Tsken a variable and given it the value of last index of array.
        while (idx >= 0)
        {
            if (digits[idx] == 9)
            {
                digits[idx] = 0;
            }
            // This will check if the digit on which idx is pointing  is 9 if yes then 9 + 1 wll become 10 so 9will be replaced by zero.
            else
            {
                digits[idx] += 1;
                return digits;
                // If this condition is true then we can add 1 to the number where the idx is pointing because if the value on which idx pointing is 9 then there is nochance that we will hit this condition.
            }
            // If the digit on which idx is pointing is not 9 then add 1 to it.
            idx--;
            // This will make the idx to point on the previos position from its current position towards its left.
        }
        digits.insert(digits.begin(), 1) return digits;
        // This will be executed only when given number is 9999.......9 so we need to add a new element in array that is 1 and after it all the elements will be zero..
    }
}