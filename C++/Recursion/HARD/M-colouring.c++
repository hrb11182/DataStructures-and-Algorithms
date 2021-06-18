/*
Given an undirected graph and a number m, determine if the graph can be coloured with at most m colours such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. 

Input-Output format: 

Input: 

A 2D array graph[V][V] where V is the number of vertices in graph and graph[V][V] is an adjacency matrix representation of the graph. A value graph[i][j] is 1 if there is a direct edge from i to j, otherwise graph[i][j] is 0.
An integer m is the maximum number of colors that can be used.
Output: 
An array color[V] that should have numbers from 1 to m. color[i] should represent the color assigned to the ith vertex. The code should also return false if the graph cannot be colored with m colors.

Example: 



Input:  
graph = {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
Output: 
Solution Exists: 
Following are the assigned colors
 1  2  3  2
Explanation: By coloring the vertices 
with following colors, adjacent 
vertices does not have same colors

Input: 
graph = {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
Output: Solution does not exist.
Explanation: No solution exits.
*/

//Solution
//T-Complexity - O(n^m)
//S-Complexity - O(n)
/*
You started with the first node you tried first colour if it fits you coloured it with that color and move to 2nd one and tried the first colour if it doesnot meets the condition you backtracked and removed that colour and  tried the second colour if it meets the required condition then colour applied if dosent you backtracked again and removed that colour and try using third colour and so on.
*/

bool isSafe(int node, int color[], bool graph[101][101], int n, int col){
// col means that one color we are trying to apply on respective node.
        for(int k = 0;k<n;k++){
                if(k!=node && graph[k][node]==1 && color[k] == col){
// This will check that two adjacent node dosent have same color if yes it will return false else true.
                        return false;
                }
        }
        return true;
}
bool solve(int node, int color[], int m, int N, bool graph[101][101]){
// node means the starting index passedin the graphColoring function.
        if(node==N){
                return TRUE;
        }
// here N total number of nodes node is the starting index from where we start to color if both become equal means we coloured all the nodes.
        for(int i;i<=m;i++){
// Loop to try every color 1 to m.
                if(isSafe(node, color, graph, N, i)){
// This function will check that is it safe to colour this node withe selected color or not.
                        color[node] = i;
                        if(solve(node+1, color, m, N, graph)) return true;
// This is a recursive call this will for each color for a node.
                        color[node] = 0;
// This is back tracking if it doesnt return true then we need to take off all the colors we did so far.
                }
        }
        return false;
// If it is impossible to color with the given amount of color it will return false.
}

bool graphColoring(bool graph[101][101], int m, int N){
// m = number of colours at maximum you need to colour the graph nodes.
// N = number of nodes.
        int color[N] = {0};
// This is an array which will store the nodes which are coloured.
        if(solve(0,color,m,N,graph)) return true;
// Recursive function which will calculate the colouring starting from 0 based indexing if it returns true then true will be returened else false will be returened.
        return false;
}