/*
Jiya likes a sequence if all its elements when multiplied yields a number , whose least significant digit is either 2, 3 or 5.

Given the number of  test case t.The first line of each test case is a number n.Next line contains n integers - A1,A2,......An.For each given test case tell whether the given sequence will be liked by Jiya.

INPUT FORMAT-

First line constains t number of test cases.

Every test case has first line as the number of intergers the sequence contains, followed by sequence in the next line.

OUTPUT FORMAT -

Print "YES" or "NO",whether Jiya likes the sequence or not.

CONSTRAINTS-

1≤t≤100

1≤n≤15

1≤Ai≤10, for all i

 

HINT - Least significant digit of a number can be obtained by taking the number % 10.

Mind the case of output to be printed.

Sample Input
2
5
2 2 2 2 2
4
2 2 2 2
Sample Output
YES
NO

Time Limit: 1
Memory Limit: 256
Source Limit:
Explanation
For the first testcase,considering the sequence 2 2 2 2 2, when we multiply all the elements get 32 as the product.The least significant digit of 32 is 2 , so the string is liked by Jiya.

For the second testcase,considering the sequence 2 2 2 2, when we multiply all the elements get 16 as the product.The least significant digit of 16 is 6 , so the string is not liked by Jiya.
*/

/* Solution*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long product = 1;
        //Range of product according to question was 10^15.
        for (int i = 0; i < n; ++i)
        {
            // Taking digit as a input whose products to be calculated.
            int x;
            cin >> x;
            product = product * x;
            //Multiplying every upcomming digit to product.
        }
        int digit = product % 10;
        // Getting the last digit of the product calculated.
        if (digit == 2 || digit == 5 || digit == 3)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        // Checking the given conditions.
    }
}