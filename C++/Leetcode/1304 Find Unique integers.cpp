/*
Given an integer n, return any array containing n unique integers such that they add up to 0.

 

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]
*/

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n%2 != 0)
        	ans.push_back(0);
        	n--;
// This if condition checks that the size of the array is even or not if it is not even then we push 0 and decrease the size of array by 1 by doing this we converted the size of array from odd to even.

        int x=1;
    for(int i=0; i<n; i+=2) {
    	ans.push_back(x);
    	ans.push_back(-1*x);
    	x++;
    }
// Initialise x with 1 and now we start from 1 and keep on inserting complement numbers for ex in 1st iteration 1 and -1 in second 2 and -2 and so on untill we exaust the size of array.
    return ans;
   }
};