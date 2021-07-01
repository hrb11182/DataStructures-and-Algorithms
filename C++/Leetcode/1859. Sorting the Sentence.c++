/*
A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.

A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.

For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

 

Example 1:

Input: s = "is2 sentence4 This1 a3"
Output: "This is a sentence"
Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.
Example 2:

Input: s = "Myself2 Me1 I4 and3"
Output: "Me Myself and I"
Explanation: Sort the words in s to their original positions "Me1 Myself2 and3 I4", then remove the numbers.
 

Constraints:

2 <= s.length <= 200
s consists of lowercase and uppercase English letters, spaces, and digits from 1 to 9.
The number of words in s is between 1 and 9.
The words in s are separated by a single space.
s contains no leading or trailing spaces.
*/

class Solution {
public:
    string sortSentence(string s) {
        string word;
        vector<string>v(10);
// Initialised a vector of size 10 to store the words of the sentences.
        for(int i=0; i<s.size(); i++){
        	if(s[i]>=48 && s[i]<=57){
// ASCII value of the numbers starts from 48 and goes till 57 so we will convert the string to int if we encounter this range of ascii.
        		v[s[i]-48] = word +" ";
//  Here we will add the word itrated till now in the vector at the index position (s[i]-48) conversting the string to int.
        		word = "";
        		i++;
// Now we are making the word empty and moving the pointer i ahead.
        	}else word += s[i];
// If we dont hit any number we will keep on appending the letters to the string.
        }
        string ans;
// To store the answer.
        for(string x:v){
// Iterating through vector v and taking the element present at the starting index and storing it in the answer.
        	ans+=x;
        }
        ans.pop_back();
// need to remove the space added by the line 41.
        return ans; 
    }
};