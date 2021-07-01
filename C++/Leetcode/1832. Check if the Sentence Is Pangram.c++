/*
A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

 

Example 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
Example 2:

Input: sentence = "leetcode"
Output: false
 

Constraints:

1 <= sentence.length <= 1000
sentence consists of lowercase English letters.
*/
class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        vector<int>v(26,0);
// Vector to map all the alphabets.
        for(int x:sentence){
        	v[x-97]++;
// We are converting char to int and increasing the count at that index.
        }
        for(int i=0; i<v.size();i++)
        	if(!v[i])return false;
        return true;
// Iterating the vector and looking for all the elements of the v if any of the alphabet is not found return false else true.
    }
};