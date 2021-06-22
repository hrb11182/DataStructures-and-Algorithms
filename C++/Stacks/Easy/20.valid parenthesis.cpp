/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

/*
Take a iterator, define a stack data structure of character type now using iterator start traversing the array linearly wheneever you get an opening bracket of any type push it in to the stack and when ever you encounter a closing bracket go to the stack and check if the stack is empty or not if empty so return false because it cant be balanced if you encounter a closing bracket first but if stack is not empty pop out the first value of stack and compare it with the bracket you have if it is its opening bracket of that type then move forword else re turn false if you you reach the end and all brackets matched and stack is empty return true else false.
*/

//S-COMPLEXITY - O(n)
//T-COMPLEXITY - O(N)
class Solution {
public:
    bool isValid(string s) {
        stack<char>st; 
// Decleration of stack.
        for(auto it: s) {
// Iterating through the given string using the for loop and iterator.
            if(it=='(' || it=='{' || it == '[') st.push(it); 
// This to check the opening brackets and if it is it will push it in to the stack.
            else {
                if(st.size() == 0) return false; 
// If string is empty return false.
                char ch = st.top();
                st.pop(); 
// Taking out the top most value of stack and storing it to ch variable by using this two lines.  
                if((it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{')) continue;
// Checking all the brackets with their corresponding pair.
                else return false;
// If they dosent match return false.
            }
        }
        return st.empty(); 
// Checking stack is empty or not.
    }
};