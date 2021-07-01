/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
*/

//BRUTEFORCE
//T-COMPLEXITY - O(n^2)
//S-Complexity - O(1)
/*
You will take i and j first loop i will point on first position and j will traverse rest of array and it will compute the max difference and store it in the max variable like this you will check every possibility and return the max.
*/

//S-COMPLEXITY - O(n)
//T-COMPLEXITY - O(1)

/*
Take a pointer and two variable(say profit and minimum price) initially make profit 0 and minimum_price some very large number now take the pointer and traverse the array once you reach the element compare that element with minimum_price if that element is smaller then update minimum_price and subtract minimum price from that number and compare the answer of that computation with the profit if it is greater then profit update it else move the pointer ahead and do the same once you end the array return profit.
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
        	minPrice = min(minPrice, price[i]);
        	profit = max(profit, prices[i] - minPrice);
        }
        return profit;
    }
};