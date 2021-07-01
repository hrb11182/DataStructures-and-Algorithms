//BRUTEFORCE
//T-COMPLEXITY - O(n^2)
/*
Here we take two nested loops one will be fixed on the first element and the second will ceck all the possiblities for that element we will calculate the area by formula {(i-j) * min(arr(i), arr(j))} and we store the the answer in a variable and we will update that value only when we get the greater value then the previously stored else we return that value after all calculations.
*/

//T-OPTIMAL
/*
    1- Take two pointers right and left place them on the begning and the end of the array.

    2- Now use the formula mentioned in above approach to calculate the area and store it in a variable as mentioned in above approach.
    
    3- Now move that pointer whose value is less to there respective direction(left pointer towards right and right towards left).
*/
int maxArea(vector<int>& height) {
    int water = 0;
    int left_ptr = 0, right_ptr = height.size() - 1;
    while (left_ptr < right_ptr) {
        int container_height = min(height[left_ptr], height[right_ptr]);
        water = max(water, (right_ptr - left_ptr) * container_height);
        while (height[left_ptr] <= container_height && left_ptr < right_ptr) left_ptr++;
        while (height[right_ptr] <= container_height && left_ptr < right_ptr) right_ptr--;
    }
    return water;
}