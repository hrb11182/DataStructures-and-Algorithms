/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
Example 3:

Input: m = 7, n = 3
Output: 28
Example 4:

Input: m = 3, n = 3
Output: 6
 

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 109.
*/

//BRUTEFORCE.
/*
Using recursion
*/

int countPaths(int i, int j, int n, int m) {
// Function of return type integer.
	if(i==(n-1) && j==(m-1)) return 1;
// This tells that if you reached at the last box of matrix means your target return 1.
	if(i>=n || j>=m) return 0;
// If you passed the Row as well as collumn's heighest value that means there is no path avilable.
	else return countPaths(i+1, j) + countPaths(i, j+1);
// Recursive call saying that it can move right or down 1st and 2nd call respectively.  	
}


//T-Complexity - O(n*m)
//S-Complexity - O(n*m)

/*
DP Approach
*/

int countPaths(int i, int j, int n, int m, vector<vector<int>>& dp) {
// Function of return type integer.
	if(i==(n-1) && j==(m-1)) return 1;
// This tells that if you reached at the last box of matrix means your target return 1.
	if(i>=n || j>=m) return 0;
// If you passed the Row as well as collumn's heighest value that means there is no path avilable.
	if(dp[i][j]!= -1) return dp[i][j];
// Checking that this call is stored in the dp table or not.
	else return dp[i][j] = countPaths(i+1, j, dp) + countPaths(i, j+1, dp);
// Recursive call saying that it can move right or down 1st and 2nd call respectively.  	
}

//Combination method.
//T -  Complexity - O(m-1)
//S -  Complexity - O(1)
/*
This will be done using (nCr) here we have where n= (n + m -2) and r = (m-1 or n-1) here if row = n in grid then we can move only n-1 steps along row and similarly if row = m then m-1 along column.
*/

class Solution {
public:
	int uniquePaths(int m, int n) {
// M & N denotes Row and column.
		int N = n + m -2;
		int r = m-1;
// Calculated using formula mentioned above.
		double res = 1;
// To store results.

		for(int i = 1;i <= r; i++)
			res = res*(N-r+i)/i;
		return (int)res;
	}
};
