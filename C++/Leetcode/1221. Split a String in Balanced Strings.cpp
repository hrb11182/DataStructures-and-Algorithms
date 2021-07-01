/*
Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

Given a balanced string s, split it in the maximum amount of balanced strings.

Return the maximum amount of split balanced strings.

 

Example 1:

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
Example 2:

Input: s = "RLLLLRRRLR"
Output: 3
Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.
Example 3:

Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".
Example 4:

Input: s = "RLRRRLLRLL"
Output: 2
Explanation: s can be split into "RL", "RRRLLRLL", since each substring contains an equal number of 'L' and 'R'
 

Constraints:

1 <= s.length <= 1000
s[i] is either 'L' or 'R'.
s is a balanced string..
*/



class Solution {
public:
    int balancedStringSplit(string s) {
        int total = 0;
// to store answer.
        vector<int>a(2, 0);
// vector of size 2 all initialised with zero.
        for(int i=0; i<(int)s.size();i++){
// Traversing through the string.
        	(s[i]=='L') ? ++a[0] : ++a[1];
// If 'L is found increment a[0]'else a[1](for 'R')
        	if(a[0]!=0 && a[0]==a[1]){
        		total++;
// Comparing the a[0] with a[1].
        		a[0]=a[1]=0;
// Making both of them zero for the next substring.
        	}
        }
        return total;
    }
};