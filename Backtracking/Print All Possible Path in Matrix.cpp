#include<bits/stdc++.h>

using namespace std;

bool isSafe(int r, int c, int n, int m, vector<vector<int>>& visited){
    return (r>=0 && r<n && c>=0 && c<m && visited[r][c] == false);
}
void getAllPath(int r, int c, vector<vector<int>>& mat, vector<vector<int>>& visited,
               vector<vector<int>>& result, vector<int> path) {

    if(r == mat.size()-1 && c == mat[0].size()-1){
        path.push_back(mat[r][c]);
        result.push_back(path);
        return;
    }
    
    if(isSafe(r, c, mat.size(), mat[0].size(), visited) == false) return;
    
    
    path.push_back(mat[r][c]);
    visited[r][c] = 1;
    getAllPath(r, c+1, mat, visited, result, path);
    getAllPath(r+1, c, mat, visited, result, path);
    
    visited[r][c] = 0;
    path.pop_back();
}

vector<vector<int>> printAllpaths(vector<vector<int> > & mat , int n , int m)
{
    vector<vector<int>> result;
    vector<int>path;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    getAllPath(0, 0, mat, visited, result, path);
    return result;
}
