#include<bits/stdc++.h>

using namespace std;
// Problem Link : https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030
// Topic : Backtracking
// Time Complexity : O(4^(n*n)), Space Complexity : O(n*n) + O(n+n) for Resucrsion Auxilary Space;


bool isValid(int r, int c, int row, int col){
    return (r>=0 && r<row && c>=0 && c<col);
}
void dfs(int x, int y , vector < vector < int >> & maze, vector < vector < bool >> & visited,vector < string >& result, string ans){
    
    if(x == maze.size() -1 && y == maze.size()-1) {
        result.push_back(ans);
        return;
    }
    
    visited[x][y] = true;
    
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};
    char s[5] = "DLRU";
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isValid(nx, ny, maze.size(), maze.size()) && maze[nx][ny] == 1 && visited[nx][ny] == false ){
            dfs(nx, ny, maze, visited, result, ans+s[i]);
        }
    }
    visited[x][y] = false;

    return;
}


vector < string > searchMaze(vector < vector < int >> & maze, int n) {
    vector < string > result;
    if(maze[0][0] == 0) {
        return result;
    }
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    dfs(0, 0, maze, visited, result, "");
    return result;
}