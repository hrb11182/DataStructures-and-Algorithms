/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104
*/


//BRUTEFORCE 
//T-Copmplexity - O(n)
//S-Complexity - O(1)
/*
We will be looping from 1 to n and every time we reach a value we multiply ans = ans*x and if the n is in minus then x^-n = 1/x^n if you are converting this negetive  one then we need to assign the answer in long.
*/

//T-Complexity - O(logbase 2 n)
//S-Complexity - O()

/*
if (n%2 == 0) then we need to do (x*x)^(n/2) and if (n%2 == 1) (ans = ans * x) and n is reduced by 1 (n = n-1) if (n == 0) we break.
*/

class Solution {
public:
	double myPow(double x, int n) {
		double ans = 1.0;
		long long nn = n;
		if(nn<0) nn = -1 * nn;
// If nn is negetive then converting it as a positive.
		while(nn) {
			if(nn % 2) {
				ans = ans * x;
				nn = nn - 1;
// This condition will execute if n%2 is true(means 1).
			}else{
				x = x * x;
				nn = nn/2;
// This condition will execute if n%2 is false(means 0).
			}
		}
// This loop will run untill nn become 0.
		if(n<0) ans = (double)(1.0)/(double)(ans);
// If n is negetive then answer need to be given in (1/x^n) form.
		return ans;
	}
};