/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/





class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int count = 0, min = 1000;
// Two variables to store the count and the size of the smallest element of strs vector.
		string str;
// Variable to store the values of the smallest element of strs.
		for(int i = 0; i<strs.size(); i++) {
// Traversing through the strs.
			int len = strs[i].length();
// Calculating length of each element.
			if(len < min){
// If it is less then min then value of  min will be the size of that element.
				min  = len;
				str = strs[i];
			}
		}
		for(int i = 0; i<min; i++){
// This loop will run up the size of min.
			for(int j=0; j<strs.size(); j++) {
// This loop will run till the last element of the strs array.
				if(strs[j][i] != str[i])
// If i will be 1 and f will be on first element of strs then they both point on the first letter of the first element of the strs array and compare it with the letters str(the smallest element of strs.)
					return str.substr(0, count);
			}
// This loops are checking the values of the string element of strs and finding the common letters.
			count++;
		}
		return str.substr(0, count);
// This return value
	}
};