/*
Cheems doesn't like extra content so coming straight to the point. Given the input of one line, having words separated by a single space, print each word of the input, each in a new line.
Also, change all the alphabets to uppercase along with doing this.

Input:-
Given in one line, all letters are lowercase only, separated by a single space.

Characters used in input are from 'a' to 'z' only ( 26 in total ) , both included.

Length of input <= 10^4.  

Output:-
Output each word with characters in uppercase.

Note:- A testcase contains only one word as the input to get partial marks. Also, the ideal solution has been provided, you can test any of your legal input to get its answer.

Sample Input
my name is himanshu rai
Sample Output
MY
NAME
IS
HIMANSHU
rai
Time Limit: 1
Memory Limit: 256
Source Limit:
Explanation
Every word of the input has been placed in the new line with characters in uppercase as well..
*/

// Solution-:
// Time complexity = O(n) || Space complexity

#include <bits/stdc++.h>

using namespace std;

char upper_case(char c)
{
    //return 'A' + (c - 'a');
    //FOR UPPER CASE
    return 'a' + (c - 'A');
    //for lower case.
}
/* Above function converts the lower case letters to upper case according
to the formula if the difference between the small 'a' and any other 
character which is stored in 'c' a variable is added to the Character 'A'
then it will return the ASCII code of the capital version of the letter 
strored in variable 'c' */

int main()
{
    while (true)
    {
        // infinite loop
        string s;
        cin >> s;
        //used cin because it breaks at space.
        if (s.size() == 0)
        {
            // if the input string is empty then break.
            break;
        }
        for (int i = 0; i < s.size(); ++i)
        {
            s[i] = upper_case(s[i]);
        }
        //This loop will looop through the characters of string and pass it
        //to the upper_case() or lower_case() functions as required
        cout << s << endl;
    }
}