/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
Example 4:

Input: s = "  Bob    Loves  Alice   "
Output: "Alice Loves Bob"
Example 5:

Input: s = "Alice does not even like bob"
Output: "bob like even not does Alice"
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
*/


//O(n^2) time and O(n) space

class Solution {
public:
	string reverseWords(string s) {
		string result;
// To store result.
		int i = 0;
		int n = s.length();

		while(i<n){
// Loop to traverse till the end of the string.
			while(i<n && s[i] ==' ') i++;
// This loop will tarverse the string untill it gets a white space.
			if(i>=n) break;
// If i exceeds max size of string break.
			int j = i + 1;
// Starting another loop from the next element of the string.
			while((j<n) && (s[j] != ' ')) j++;
// This loop will also break white spaces.
			string sub = s.substr(i, j-i);
// Using stl function to capture the string between i and j-1.
			if(result.length() == 0) result = sub;
// If there is nothing in result then transfer the subarray stored in sub in result.
			else result = sub + " "+ result;
// If any thing is already present in the result then add sub array before the result.
			i = j+1;
// This will make i point on the next substring of the given string.
		}
		return result;
	}
};