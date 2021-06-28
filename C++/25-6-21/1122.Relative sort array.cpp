/*
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.

 

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
 

Constraints:

1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
All the elements of arr2 are distinct.
Each arr2[i] is in arr1.
*/



class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		map<int, int>mp;
// Declared a map to store the element from arr1 and its occurance(OHw many times it occur in arr1).
		vector<int> ans;
// Array to store the answer.
		for(auto x: arr1)
			mp[x]++;
// Iterating through array 1 and storing it in map.
		for(auto temp: arr2){
// Iterating through array 2.
			if(mp.find(temp)!=mp.end()){
// If temp is present in the map and it is not the last element.
				auto x = mp.find(temp);
// Storing temp to x.
				int count = x->second;
// Storing the count of x in the count (second value mapped in map.)
				vector<int>v(count, temp);
// Now making an array of length equal to count and having all the values equal to the x.
				ans.insert(ans.end(), v.begin(), v.end());
// This will insert v at the end of ans.
				mp.erase(temp);
// Now erasing the value from map.
			}
		}
		for(auto x: mp){
			int ele = x.first;
			int count = x.second;
			vector<int>v(count, ele);
			ans.insert(ans.end(), v.begin(), v.end());
		}
// This loop to store the rest of the elements from map to the answer.
		return ans;		
	}
};