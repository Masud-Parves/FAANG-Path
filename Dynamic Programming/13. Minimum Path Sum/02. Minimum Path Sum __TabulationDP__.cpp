/*
    Problems Link : https://leetcode.com/problems/minimum-path-sum/
    TC - O(rows*cols)
    SC - O(rows*cols)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> DP(rows, vector<int>(cols, INT_MAX/2));

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(r==0 && c==0) DP[r][c] = grid[r][c];
                else {
                    if(r>0) DP[r][c] = min(DP[r][c], grid[r][c] + DP[r-1][c]);
                    if(c>0) DP[r][c] = min(DP[r][c], grid[r][c] + DP[r][c-1]);
                }
            }
        }

        return DP[rows-1][cols-1];
    }
};