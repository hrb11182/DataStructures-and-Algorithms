/*
A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

 

Example 1:

Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32
Example 2:

Input: n = "82734"
Output: 8
Example 3:

Input: n = "27346209830709182346"
Output: 9
 

Constraints:

1 <= n.length <= 105
n consists of only digits.
n does not contain any leading zeros and represents a positive integer.
*/

/* Adecimal number is called deci binary if it consists of only 1 and 0 and need not to start with 0 for examplo 100,1010,1110 etc but not 01,001,0111 etc */
 

 /*
if we need to add deci binary to make a given num then min numbers of deci binary number needed will be equal to the max digit present in the given number for ex 32 here 3 can be make using 1+1+1 because adding 0 will make no change but in 2 1+1+0 because we consumed 3 spaces in the previous digit no if we put this operations side by side we get-:

3 2
-------
1 1
1 1
1 0
__________
32

so by adding 11+11+10 we get 32 so from here max number of digits will be 3 number of 1 consumed by the biggest digit of the given number..
 */

class Solution {
public:
    int minPartitions(string n) {
    	int ans=0;
        for(char x:n){
// we iterated through the each characters.
        	int curr = x-48; //Every character will have ASCII between 48 to 57.
// Suppose in string x=3 so here since it is achar so its ascii will be used 51 so 51-48 = 3 so we converted string to integer.
        	ans = max(ans, curr);
        }
        return ans;
    }
};