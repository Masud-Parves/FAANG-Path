/*
    Problems Link : https://leetcode.com/problems/cherry-pickup-ii/
    TC - O(rows*cols*cols)
    SC - O(rows*cols*cols) + O(rows) Recursion Stack Memory.
*/

class Solution {
private:
    int helper(int r, int c1, int c2, vector<vector<int>>& grid, vector<vector<vector<int>>>& DP, int rows, int cols){
        if(r<0 || c1<0 || c2<0 || c1==cols || c2==cols) return INT_MIN;
        if(r == rows-1){
            if(c1==c2) return grid[r][c1];
            return grid[r][c1] + grid[r][c2];
        }
        
        int& cache = DP[r][c1][c2];
        if(cache != -1){
            return cache;
        }
        
        cache = INT_MIN;
        for(int c1i=-1; c1i<=1; c1i++){
            for(int c2i =-1; c2i<=1; c2i++){
                int c = c1+c1i, cc = c2+c2i, cherry = grid[r][c1];
                if(c1 != c2) cherry +=  grid[r][c2];
                cache = max(cache, cherry + helper(r+1, c, cc, grid, DP, rows, cols));
            }
        }
        return cache;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> DP(rows+1, vector<vector<int>>(cols+1, vector<int>(cols+1, -1)));
        return helper(0, 0, cols-1, grid, DP, rows, cols);
    }
};