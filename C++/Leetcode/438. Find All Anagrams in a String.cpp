/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.
*/
/* 
we will take a window of size equal to the first string whose anagram to be found and take two hashes in one we will store the string whose anagram to be found and in the second we will store the letters which is inside our window and we compare both of them if both become equal then we will insert the starting idx of our window to the answer vector and slide the window by one index ahead and once we end with the main array we will return the answer.
*/
// T-complexity = O(ALphabet size*len(s))
class Solution {
    
public:
    vector<int> findAnagrams(string s, string p) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> ans;
        vector<int> hash(26,0);
        vector<int> phash(26,0);
        int window = p.size();
// Making an window of size of array p.
        int len = s.size();
        if(len<window)
            return ans;
// In this case no anagrams are possible.
        int left = 0,right = 0;
        while(right<window)
        {
            phash[p[right]-'a'] +=1;
            hash[s[right++]-'a'] +=1;
        }
// This will take the right pointer and move it till the winow size and left will remain zero.
        right -=1;
        while(right<len)
        {
            if(phash == hash)
                ans.push_back(left);
            right+=1;
            if(right!=len)
                hash[s[right]-'a'] +=1;
            hash[s[left]-'a'] -=1;
            left+=1;
        }
        return ans;
    }
};