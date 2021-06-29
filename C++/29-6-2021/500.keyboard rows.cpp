/*
Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

In the American keyboard:

the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".

 

Example 1:

Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]
Example 2:

Input: words = ["omk"]
Output: []
Example 3:

Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"]
 

Constraints:

1 <= words.length <= 20
1 <= words[i].length <= 100
words[i] consists of English letters (both lowercase and uppercase). 
*/


class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char, int>r1;
        map<char, int>r2;
        map<char, int>r3;
// Taken three maps for each row of the keyboard. 
        r1['q']=1;
        r1['w']=1;
        r1['e']=1;
        r1['r']=1;
        r1['t']=1;
        r1['y']=1;
        r1['u']=1;
        r1['i']=1;
        r1['o']=1;
        r1['p']=1;
        r2['a']=1;
        r2['s']=1;
        r2['d']=1;
        r2['f']=1;
        r2['g']=1;
        r2['h']=1;
        r2['j']=1;
        r2['k']=1;
        r2['l']=1;
        r3['z']=1;
        r3['x']=1;
        r3['c']=1;
        r3['v']=1;
        r3['b']=1;
        r3['n']=1;
        r3['m']=1;
// Pushed all the words in the map.
        int n =  words.size();
// Number of letters in the word given in the input.
        vector<string> ans;
// To store the answer.
        for(int i = 0;  i<n; i++){
// Lopping through main array of strings.
        	int flag =0;
        	string z=words[i];
// To store the present words of the array.
        	transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
// To transform the capital to lower case.        	
        	for(int j=0; j<(int)z.length();j++){
        		if(r1.find(words[i][j])==r1.end()){
        			flag++;
        			break;
        		}
        	}
        	for(int j=0; j<(int)words[i].length();j++){
        		if(r2.find(words[i][j])==r2.end()){
        			flag++;
        			break;
        		}
        	}
        	for(int j=0; j<(int)words[i].length();j++){
        		if(r3.find(words[i][j])==r3.end()){
        			flag++;
        			break;
        		}
        	}
// This three loops will find the letters in the three maps.
        	if(flag<3)
        		ans.push_back(z);
// Flag value will never exceed 3 because if a word is found using one loop from above 3 then that loop will never hit the if condition mentioned in loop but for other loops the flag will be increased by 1 because if word belong to one row then it will be found in one loop iteration so all the loops will run for one time and it will produce only 2.
        }
        return ans;
    }
};