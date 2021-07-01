//S-OPTIMAL - O(1)
//T-OPTIMAL - O(n)
/*
    1-You have to linearly traverse from back of the array.
    2- Now you have to find the first index i such that {a[i]<a[i+i]}.
    3-Again traverse through the back and try to find the value which is greater then the value and index 1{a[i]}
    4-Swap the value found greater then the value at index 1 with the value at index 1.
    5- Reverse everything from a[2] to last index.
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
        for (k = n - 2; k >= 0; k--){
            if (nums[k] < nums[k + 1]){
                break;
            }
        }
        if (k < 0){
            reverse(nums.begin(), nums.end());
        }else{
            for (l = n - 1; l > k; l--){
                if (nums[l] > nums[k]){
                    break;
                }
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};