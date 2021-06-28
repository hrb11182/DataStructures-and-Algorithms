/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

//Bruteforce.
//T-Complexity - O(nlogn) + O(n^2)
//S - XComplexity -  O(n)
/*
1- We will sort all the intervals if it is given in an unsorted order.
2- Now you will point on one element and traverse all the elements of the array and try to find that which of the elements are overlapping with the elements you selected.
3- Initialise another data structure and store the elements generated after overlapping of the main array elements.
4-  And you are going to skip all the intervels that are already being merged with any other intervals.
*/


//T-Complexity - O(nlogn) + O(n)
//S - XComplexity -  O(n)

/*
1- We need to sort the array.
2- Once the array will be sorted it assures that all the intervals will be consicutive for a given pair.
3-  We take a pair store the first element in it and traverse through the array and we will try to find the pairs which merges with this selected pair if we encounter any pair that doesnt merges then we transfer the resultant pair from the merges took so far to a new data structure and now we put that pair where it stooped merging to the pair and we move that element to the pair and repeat the process again.
3- Merging will be simple compare first and lart element of both the pairs and choose the greater among them.
*/


class solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> mergedIntervals;
		if(intervals.size() == 0) return mergedIntervals;

		sort(intervals.begin(), intervals.end());
		vector<int> tempInterval = intervals[0];

		for(auto it : intervals){
			if(it[0] <= tempInterval[1]) {
// Checking if both elements can be merged or not by comparing the last element of the tempInterval and the first element of the element pointed by our iterator.
				tempInterval[1] = max(it[1], tempInterval[1]);
			}else{
				mergedIntervals.push_back(tempInterval);
				tempInterval = it;
			}
		}
		mergedIntervals.push_back(tempInterval);
		return mergedIntervals;
	}
};
