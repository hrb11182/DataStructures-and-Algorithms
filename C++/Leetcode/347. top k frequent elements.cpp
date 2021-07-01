/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/




class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>m;
        int n = nums.size();
        for(int i=0; i<n; i++)
            m[nums[i]]++;
// Created a map and stored all the elements in map and incremented the map to store the frequency.

            vector<pair<int, int>>ans;
// To store the answer.
            for(auto i=m.begin();i!=m.end();i++)
                ans.push_back((i->second, i->first));
// Storing the pair in answer.
            sort(ans.begin(), ans.end());
// Sorted the answer.
            reverse(ans.begin(), ans.end());
// Since we need the more frequent element first so we just reversed the sorted array.

            vector<int>a(k);
            for(int i = 0; i<k; i++)
                a[i]=ans[i].second;
// This loop  returns the number of top frequen elements.
            return a;
    }
};