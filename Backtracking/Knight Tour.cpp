#include<bits/stdc++.h>

using namespace std;

// Topic : Backtracking
// Problem Link : https://www.codingninjas.com/codestudio/problems/knight-tour_1170518?leftPanelTab=0
// TC : O(8^(n*m)) 
// SC : O(n*m) + recursion stack memory.

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

bool isSafe(int r, int c, int n, int m, vector<vector<int>>& sol){
    return (r>=0 && r<n && c>=0 && c<m && sol[r][c] == -1);
}

bool getKnightTour(int r, int c, int currMove, int n, int m, vector<vector<int>>& sol){
    if(currMove == n*m-1){
        sol[r][c] = currMove;
        return true;
    }
    sol[r][c] = currMove;
    for(int i=0; i<8; i++){
        int next_row = r + dx[i];
        int next_col = c + dy[i];
        if(isSafe(next_row, next_col, n, m, sol)) {
            if(getKnightTour(next_row, next_col, currMove+1, n, m, sol) == true) {
                return true;
            }
        }
    } 
    sol[r][c] = -1;
    return false;
}


vector<vector<int>> knightTour(int n, int m) {
    /* 
        Return matrix of size n*m where integer
        at cell(i, j) represent move number of knight to reach that
        cell. Move number start from 0.

        It may be possible that there is no possible order to visit each cell
        exactly once. In that case, return a matrix of size n*m having all the values
        equal to -1.
    */

    // Write your code here.
    vector<vector<int>>sol(n, vector<int>(m, -1));
    int currMove = 0;
    if(getKnightTour(0, 0, currMove, n, m, sol) == false) {
        vector<vector<int>>sol(n, vector<int>(m, -1));
    }
    
    return sol;
}