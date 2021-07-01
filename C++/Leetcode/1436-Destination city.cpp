/*
You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

 

Example 1:

Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo" 
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
Example 2:

Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are: 
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
Clearly the destination city is "A".
Example 3:

Input: paths = [["A","Z"]]
Output: "Z"
 

Constraints:

1 <= paths.length <= 100
paths[i].length == 2
1 <= cityAi.length, cityBi.length <= 10
cityAi != cityBi
All strings consist of lowercase and uppercase English letters and the space character.
*/
// Time : O(N)
// Space: O(N)
/*
Here we will define a set and add all the destination cities to it if we talk about the first example in the question then set will contain  <"New York", "Lima", "Sao Paulo"> and we now iterate through all the given cities and we remove those cities from set which are starting point of any journey so here we will remove <"New York", "Lima"> from set so we left with the <"Sao Paulo"> so it will be our answer.
*/


class Solution {//Hashset
public: 
  string destCity(vector<vector<string>>& paths) {                
        unordered_set<string> startingCities;
// Set decleration
        for(auto& e: paths)  startingCities.insert(e[0]);  
// Iterating through the path array and picking the first value of a journey and putting it in the set.                      
        for(auto& e: paths) 
            if(!startingCities.count(e[1])) return e[1];   
// Now again iterating through array path and checking that which destination dosent belong to set.          
        return "";
    }
};