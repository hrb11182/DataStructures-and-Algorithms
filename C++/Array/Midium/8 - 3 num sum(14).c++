//BRUTEFORCE TC - O(n^3 * logm) SC - O(m)  here m is the  size of set.
/*
Run the three loops and traverse  the array to find the triplets {i(0 to n-1), j(i+1 to n-1), k(j+1 to n-1)} strore the triplets in sets and return the answer you need to store the triplets in sets because set dosent allow the duplicates.
*/

//APPROACH - 2(Hashing)
/*
TC - O(n^2 * log m).
SC - O(m) + O(n).
Here we traverse the array and store all its element in hash table and we run a two nested for loop {i(0 to n-1) and j(i+1 to n-1)} and we remove both the elements from hash first on which i and j are pointing and then we try to find the third element from hash(formula c = target - [a + b]) and when we are done with our operation with that elements we will add them back to the hash table.
*/
//APPROACH - 3(Two pointer approach)

/*
First sort the array and fix a value and then take two pointers high and low place low at the begning of array and high at the end of array now calculate the sum of both high and low and compare it with the number you want{num = target - a(fixed value of array)} if it is greater then your sum then move low pointer towargs right else move high pointer towards left to eliminate duplicates compare the values of both the pointers with there previous value if they are equal skip untill u find a unique value. 
*/

//APPROACH - 3 CODE

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(num.begin(), num.end());
    vector<vector<int>> result;

    for (int i = 0; i < nums.size; i++)
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int lo == i + 1, hi = nums.size(), sum = 0 - nums[i];

            while (lo < hi)
            {
                if (nums[lo] + nums[hi] == sum)
                {
                    vector<int> temp;
                    temp.push_back(num[i]);
                    temp.push_back(num[lo]);
                    temp.push_back(num[hi]);
                    result.push_back(temp);

                    while (lo < hi && nums[lo] == nums[lo + 1])
                        lo++;
                    while (lo < hi && nums[hi] == nums[hi - 1])
                        hi++;

                    lo++;
                    hi++;
                }
                else if (nums[lo] + nums[hi] < sum)
                    lo++;
                else
                    hi--;
            }
        }
    }
    return result;
}