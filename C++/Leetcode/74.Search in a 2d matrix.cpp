 /*
 Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

 // Bruteforce
//T-Complexity-O(n*n)
//S-Complexity-O(1)
 /*
 Do the linrar search in 2d matrix and check that target exists or not.
 */


//T-Complexity -  O(n*log base2)

/*
You will be doing binary search on every row to find the target element.
*/

// Optimal soln.

/*
if the rows and cols both are sorted then we can follow this approach.

We place our pointer on the last column of the first row and we check  if this element is greater then the number we are searching or smaller if it is smaller then we will move along row(say first row) but if it is greater then we will move along col(say last col) suppose we got smaller element then we go along row and now again we chck the same condition with that element of row and decide either it is greater or smaller.

*/
 int i = 0, j = m - 1;
// First row (i) and last column (j).
 while(i<n && J>=0) {
// We will keep on moving untill we go out of the bounds.
 	if (mat[i][j] == x ){
 		cout<<1<<endl;
 	}
// If i found the element we return 1.	
 	if(mat[i][j] > x)
 		j--;
// If target element is smaller then the current element move along row.
 	else
 		i++;
// If greater move along column.
 }


 //T-Complexity -O(log bas 2(n*m))
 //S-complexity - O(1)

// Leet code problem solution where the last element of present row will be always smaller then the first element of the next row means we got a sorted array stored in a matrix of n x m.

/*
Either we put all the elements of matrix in an array as they occur in matrix and apply binary search else we assign our own indexes to each elements of the matrix so we will assign our own index and in order to find the index in n x m matrix which is equal to our index we can -
							1 - Divide the our index by row number and take it as the row index of matrix.
							2 - Anc take the modulo of our index by row number and take it as the column index of matrix.
							3 - Store it like this(row, col) this will represent the number should be present at the given index if it was an array.
*/


 class Solution {
 public:
 	bool searchMatrix(vector<vector<int>>& matrix, int target) {
 		if(!matrix.size()) return false;
// Matrix is empty.
 		int n = matrix.size();
// Computing the size of row of matrix.
 		int m = matrix[0].size();
// Computing the size of column of matrix.
 		int low = 0;
 		int high = (n * m ) - 1;
// n*m last element of matrix and we use 0 based indexing.
 		while(low <= high) {
 			int mid = (low + (high - low)/2);
// Calculating mid.
 			if(matrix[mid/m][mid%m] == target) {
 				return true;
 			}
 			if(matrix[mid/m][mid%m] < target) {
 				low = mid+1;
 			}else{
 				high = mid - 1;
 			}
 		}
 		return false;
 	}
// Binary search.
 };