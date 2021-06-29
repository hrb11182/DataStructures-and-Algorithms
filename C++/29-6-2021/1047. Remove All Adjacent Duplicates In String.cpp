/*
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
*/


// Two pointers approach
/*
Here we will take two pointers i and j i will be at oth index and j will be at the i+1 index and we will compare both of them and if both are not equal we will move them one step ahead and if they become equal we will remove both the elements on i and j by using sub string method by taking one substring from 0 to i-1 and secod from j+1 to the end of array
*/


class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
// Defined stack.
        string ans;
        for(int i=0;i<s.size();i++){
            if(st.size() == 0){
                
                st.push(s[i]);
            }
// If stack is empty we can push any thing without any doubt.
            else if(s[i] == st.top()){
                st.pop();
            }
// If it is not empty and it is equal to the present element then we will pop out that element.
            else{
                st.push(s[i]);
            }
// If it is not equal then we can push it directly.
        }
        
        while(st.size() != 0){
            ans += st.top();
            st.pop();
        }
// Untill stack is empty we will add all the elements of the stack in the answer one by one.
        reverse(ans.begin(),ans.end());
        return ans;
// Since top element of the stack is the last of the answer so we reverse the answer.
        }
};
