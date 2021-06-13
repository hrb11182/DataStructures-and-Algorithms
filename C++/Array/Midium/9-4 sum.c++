//T-OPTIMAL
//S-OPTIMAL
// APPROACH
/*
Here first we sort the array and we will take two nested loops {(i=0 to n-1) & (j=i+1 to n-1)} and two pointers  hi and lo will points on the last elements of array and the second element of the loop j and then we take the sum of numbers on which i,j,hi,lo is pointing if the sum is correct we return that numbers but if the sum is less we move lo pointer towards right if more move hi pointer towards the left if hi & lo crosses each other we start incrementing j and repet the process again and if we hit the last element for j then we increment i and repeat the process again.during all the above steps we will try to skip duplicates in case of all four pointers {i,j,lo,hi}
*/

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;

    if (nums.empty())
        return result;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int target_2 = target - nums[j] - nums[i];
            int front = j + 1;
            int back = n - 1;
            while (front < back)
            {
                int two_sum = nums[front] + nums[back];
                if (tow_sum < target_2)
                    front++;
                else if (two_sum > target_2)
                    back--;
                else
                {
                    vector<int> quadruplet(4, 0);
                    quadruplet[0] = nums[i];
                    quadruplet[1] = nums[j];
                    quadruplet[2] = nums[front];
                    quadruplet[3] = nums[back];
                    res.push_back(quadruplet);

                    while (front < back && num[front] == quadruplet[2])
                        ++front;
                    while (front < back == quadruplet[3])
                        --back;
                    // Skipping the duplicates for pointer front and back.
                }
            }
            while (j + 1 < n && num[j + 1] == num[j])
                ++j;
            // Skipping the duplicates for pointer j.
        }
        while (i + 1 < n && num[i + 1] == num[i])
            ++i;
        // Skipping the duplicates for pointer i.
    }
}