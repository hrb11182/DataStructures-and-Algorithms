/*
Problem
Monk loves Primes, whether it is number or word

Rules to convert a string to a number:
1. Convert the UpperCase letters to LowerCase letters
2. Convert the LowerCase letters to UpperCase letters

Add the ASCII values of all the UpperCase letters and subract the ASCII values of all the LowerCase letters. The resultant number is X.

Note: If X is negative take absolute value of it

Print 1 if X is a prime number and 0 if not
(Prime Number: A number which is divisble by the number one and itself, i.e, it has 2 divisors)

 

Input Format:

A single line which consists of a string

 

Output Format:

0 or 1 in a single line 

 

Constraints:

1 <= string length <= 2000

Time Limit: 2
Memory Limit: 256
Source Limit:
Explanation
Explanation:

l -> L => 76
B -> b => 98
X -> x => 120
p -> P => 80
s -> S => 83

76 - 98 - 120 + 80 + 83 = 21 and it is not a prime number
*/

#include <bits/stdc++.h>

using namespace std;
char upper(char c)
{
    return 'A' + (c - 'a');
    //refer capitalbaazi.
}

char lower(char c)
{
    return 'a' + (c - 'A');
    //refer capitalbaazi.
}

int main()
{
    string s;
    cin >> s;
    //This loop is converting the uppercase letters to lowercase and viceversa.
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = upper(s[i]);
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = lower(s[i]);
        }
    }
    int result;
    //This loop is calculating the sum of ASCII value of both upper and lower case and
    //subtracting the sum of lowercase from the sum of ASCII value of uppercase.
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            result = result - s[i];
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            result = result + s[i];
        }
    }
    //If the result is negetive then converting it in to the positive value by this if condition.
    if (result < 0)
    {
        result = result * -1;
    }
    //Checking if the result is prime.
    int flag = 0;
    for (int i = 2; i < result; ++i)
    {
        if (result % i == 0)
        {
            flag = 1;
            break;
        }
    }
    //If number is prime print 1 else 0.
    if (flag == 0)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}