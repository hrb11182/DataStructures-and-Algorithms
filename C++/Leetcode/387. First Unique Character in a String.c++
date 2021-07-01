/*
Given a string s, return the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
*/
class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.length();
        vector<int> frequency(26, 0);
        for(int i = 0; s[i]!='\0'; ++i)
        	frequency[s[i]-'a']+=1;
// This loop  is storing the frequency of the each element in the array frequency by using its ascii value.

        for(int i = 0; s[i]!='\0'; ++i)
        	if(frequency[s[i]-'a']==1)
        		return i;
// traverse the array and try to find the character with  the frequency 1 if yes return i else -1.
        return -1;
    }
};