/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

 

Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 

Constraints:

0 <= n <= 30
*/
// BRUTEFORCE
/* We can use recursion */

//But we can optimise it using the memoization a technique to store the calculations so that if required they can be fetched in O(1) time.

int fib(int N){
	if (N<=1)
		return n;
	int a = 0, b = 1;
	for(int i = 2; i<=N; ++i){
		int sum = a +b;
		a = b;
		b = sum;
	}
	return b;
}

// Fib seriese - : 0, 1,1,2,3,5,8,13,21,34.....(n-1),n