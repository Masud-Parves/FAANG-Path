#include<bits/stdc++.h>

using namespace std;


// Topic : Backtracking
// Problem Link : https://www.codingninjas.com/codestudio/problems/longest-route_1170525
// Learning Resource : https://www.techiedelight.com/find-longest-possible-route-matrix/


bool isSafe(int r, int c, vector<vector<int>>& mat, vector<vector<int>>& visited){
    return (r>=0 && r<mat.size() && c>=0 && c<mat[0].size() && mat[r][c] == 1 && visited[r][c] == false);
}

void findLongestPath(int i, int j, int dx, int dy, vector<vector<int>> &mat, vector<vector<int>> &visited, int dis, int& longestPath){
    if(mat[i][j] == 0) return;
    if(i == dx && j==dy){
        longestPath = max(longestPath, dis);
        return;
    }
    
    visited[i][j] = 1;
    if(isSafe(i+1, j, mat, visited)){
        findLongestPath(i+1, j, dx, dy, mat, visited, dis+1, longestPath);
    }
    if(isSafe(i, j+1, mat, visited)){
        findLongestPath(i, j+1, dx, dy, mat, visited, dis+1, longestPath);
    } 
    if(isSafe(i-1, j, mat, visited)){
        findLongestPath(i-1, j, dx, dy, mat, visited, dis+1, longestPath);
    } 
    if(isSafe(i, j-1, mat, visited)){
        findLongestPath(i, j-1, dx, dy, mat, visited, dis+1, longestPath);
    } 
    visited[i][j] = 0;
    return;
}
int longestPath(int n, int m, vector<vector<int>> &mat, int sx, int sy, int dx, int dy) {
    if(mat.size() == 0 || mat[sx][sy] == 0 || mat[dx][dy] == 0){
        return -1;
    }
	vector<vector<int>> visited(n, vector<int>(m, 0));
    
    int longestPath = 0;
    findLongestPath(sx, sy, dx, dy, mat, visited, 0, longestPath);
    return longestPath;
}

