/*
13. Roman to Integer
Easy

937

80

Add to List

Share
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Example 2:

Input: s = "IV"
Output: 4
Example 3:

Input: s = "IX"
Output: 9
Example 4:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/



class Solution {
public:
	int romanToInt(string str) {
		map<char, int> roman;
// Declared a map of pairs to map the roman numbers with their respective integer values.
		roman.insert(make_pair('I', 1));
		roman.insert(make_pair('V', 5));
		roman.insert(make_pair('X', 10));
		roman.insert(make_pair('L', 50));
		roman.insert(make_pair('C', 100));
		roman.insert(make_pair('D', 500));
		roman.insert(make_pair('M', 1000));
// Mapping of roman numbers.

		int len = str.length(),num,sum=0;
// Declaring variables to store the string length num to store the value of roman number on which i  points and sum to store the sum.

		for(int i=0; i<len;) {
			if(i == (len-1) || (roman[str[i]] >= roman[str[i+1]])){
				num = roman[str[i]];
				i++;
// This loop checks that if the character on which i is pointing is the last or it is the element which is either greater then or equal to the next character according to their int conversion. 
			}else {
				num = roman[str[i+1]] - roman[str[i]];
				i = i+2;
// If it is smaller then its value needs to be subtracted from the next element.
			}
			sum = sum + num;
// Updating the sum value after every loop execution.
		}
		return sum;
// Returning the value of sum.
	}
}