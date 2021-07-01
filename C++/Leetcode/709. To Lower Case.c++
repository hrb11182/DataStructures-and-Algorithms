/*
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

 

Example 1:

Input: s = "Hello"
Output: "hello"
Example 2:

Input: s = "here"
Output: "here"
Example 3:

Input: s = "LOVELY"
Output: "lovely"
 

Constraints:

1 <= s.length <= 100
s consists of printable ASCII characters.
*/


class Solution {
public:
    string toLowerCase(string s) {
        int i=0;
        for(char x:s){
// Iterating through each letters of the word.
// ASCII value of uppercase alphabet is from 65 to 90 lower case 97 to 122.
        	if(x>=65 && x<=90){
        		x+=32;
// Here we added 32 because between the upper and the lower case of any alphabet there is the difference of 32.
        		s[i]=x;
// Now making that character of string to lowercase that was in upper.
        	}
        	i++;
        }
        return s;
    }
};