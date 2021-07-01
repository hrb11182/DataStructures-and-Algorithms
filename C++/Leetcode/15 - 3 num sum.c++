//BRUTEFORCE TC - O(n^3 * logm) SC - O(m)  here m is the  size of set.
/*
Run the three loops and traverse  the array to find the triplets {i(0 to n-1), j(i+1 to n-1), k(j+1 to n-1)} strore the triplets in sets and return the answer you need to store the triplets in sets because set dosent allow the duplicates.
*/

//APPROACH - 2(Hashing)
/*
TC - O(n^2 * log m).
SC - O(m) + O(n).
Here we traverse the array and store all its element in hash table and we run a two nested for loop {i(0 to n-1) and j(i+1 to n-1)} and we remove both the elements from hash first on which i and j are pointing and then we try to find the third element from hash(formula c = target - [a + b]) and when we are done with our operation with that elements we will add them back to the hash table.
*/
//APPROACH - 3(Two pointer approach)

/*
First sort the array and fix a value and then take two pointers high and low place low at the begning of array and high at the end of array now calculate the sum of both high and low and compare it with the number you want{num = target - a(fixed value of array)} if it is greater then your sum then move low pointer towargs right else move high pointer towards left to eliminate duplicates compare the values of both the pointers with there previous value if they are equal skip untill u find a unique value. 
*/

//APPROACH - 3 CODE

class Solution {
public:
 vector<vector<int> > threeSum(vector<int> &num) {
    
    vector<vector<int> > res;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
        
        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back) {

            int sum = num[front] + num[back];
            
            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet = {num[i], num[front], num[back]};
                res.push_back(triplet);
                
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) back--;
            }
            
        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }
    
    return res;
    
}
};