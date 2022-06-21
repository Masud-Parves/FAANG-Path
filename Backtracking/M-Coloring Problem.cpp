#include<bits/stdc++.h>

using namespace std;

// Problem Link : https://www.codingninjas.com/codestudio/problems/m-coloring-problem_981273?leftPanelTab=0
// Topic : Backtracking
// TC : O(N^M) , where N is number of Node and M is number of given color
// SC : O(N) Extra space for color array


bool isPossible(int node, vector<vector<int>> &mat, int c, vector<int>& color){
    for(int i=0; i<mat.size(); i++){
        if(mat[node][i] == 1 && color[i] == c) return false;
    }
    return true;
}

bool helper(int node, vector<vector<int>> &mat, int m, vector<int>& color){
    if(node == mat.size()){
        return true;
    }
    
    for(int c = 1; c<=m; c++){
        if(isPossible(node, mat, c, color) == true) {
            color[node] = c;
            if(helper(node+1, mat, m, color) == true) {
                return true;
            }
            color[node] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    vector<int> color(n, 0);
    return (helper(0, mat, m, color) == true ) ? "YES" : "NO";
}