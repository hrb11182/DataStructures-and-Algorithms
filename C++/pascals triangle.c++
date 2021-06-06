/*
This year Santa wants to make a Christmas tree. But this time he wants to decorate it with numbers as in the Pascal’s triangle. But Santa is very busy in packing the gifts. Now, you being Santa’s friend help in making the tree.

Input: In the first line, you will be given ”t” no. of test cases. For each test case, you will be given a whole number “N”.

Output: For each value N, Print the first N lines in Christmas tree.

Constraints:   1≤T≤100
1 ≤ N ≤ 40

 

Sample Input
2
3
5
Sample Output
1 
1 1 
1 2 1 
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
Time Limit: 5
Memory Limit: 256
Source Limit:
Explanation
For each line find the binomial coeffients and print the values with required spaces between them.
*/

//Solution

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
        int a[n][n];
        a[0][0] = 1;
        for (int i = 1; i < n; ++i)
        {
            a[i][0] = 1;
            // First column will always have 1 since col is not
            //changing so y axis remain 0 and x will change since rows
            //are changing
            a[i][i] = 1;
            //Similarly last col will always have 1 since this triagle expand towrds
            //right and down so both row adn col will change acc to value of i.
            for (int j = 1; j < i; ++j)
            {
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
                //here we added number just before the number
                // above the current number we are trying to find and
                //the number above it.
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                cout << a[i][j] << " ";
            }
            //This two loops are printing the triangle.
            cout << endl;
        }
    }
}

// Solution 2
/* Here we will use precomputation technique we will calculate each pascal triangle for the max range of input but it will only work when range of input is known*/

#include <bits/stdc++.h>

using namespace std;
const int N = 50;

int main()
{
    int t;
    cin >> t;
    long long int a[N][N];
    a[0][0] = 1;
    for (int i = 1; i < N; ++i)
    {
        a[i][0] = 1;
        // First column will always have 1 since col is not
        //changing so y axis remain 0 and x will change since rows
        //are changing
        a[i][i] = 1;
        //Similarly last col will always have 1 since this triagle expand towrds
        //right and down so both row adn col will change acc to value of i.
        for (int j = 1; j < i; ++j)
        {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            //here we added number just before the number
            // above the current number we are trying to find and
            //the number above it.
        }
    }
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                cout << a[i][j] << " ";
            }
            //This two loops are printing the triangle.
            cout << endl;
        }
    }
}