/*
order and str are strings composed of lowercase letters. In order, no letter occurs more than once.

order was sorted in some custom order previously. We want to permute the characters of str so that they match the order that order was sorted. More specifically, if x occurs before y in order, then x should occur before y in the returned string.

Return any permutation of str (as a string) that satisfies this property.

Example:
Input: 
order = "cba"
str = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
 

Note:

order has length at most 26, and no character is repeated in order.
str has length at most 200.
order and str consist of lowercase letters only.

*/

class Solution {
public:
	string customSortString(string order, string str) {
		map<char, int>mp;
//Hash function to store string str.
		string ans = "";
// To store the answer.

		for(auto x:str)
			mp[x]++;
// This loop will insert all the elements of the str in map(or hash).
		for(auto x:order){
// Traversing through the order.
			if(mp.find(x)!= mp.end()){
// If x is present in the map ant it is not the last element of map.
				auto temp = mp.find(x);
// Iterating in map untill x is present.
				int count = temp->second;
// Moving the count pointer to the next of its present value.
				string s(count, x);
// This line created a string name "s" and strored "count" number of x in it. 
				ans+=s;
// Inserting s(all the x) in the answer.
				mp.erase(x);		
// Erasing all the values of x from map.
			}
		}
		for(auto x:mp){
			string s(x.second, x.first);
			ans+=s;
	}
	return ans;

	}
	
};