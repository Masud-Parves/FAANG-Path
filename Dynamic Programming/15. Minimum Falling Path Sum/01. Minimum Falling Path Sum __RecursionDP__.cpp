/*
    Problems Link : https://leetcode.com/problems/minimum-falling-path-sum/
    TC - O(rows*cols)
    SC - O(rows*cols) + O(max(rows, cols)) Recursion Stack Memory.
*/

class Solution {
private:
    int helper(int r, int c, int rows, int cols, vector<vector<int>>& matrix, vector<vector<int>>& DP){
        if(c<0 || c==cols) return INT_MAX/2;
        if(r == rows-1 && c<cols){
            return matrix[r][c];
        }
        
        int& cache = DP[r][c];
        if(cache != -1){
            return cache;
        }
        
        int way1 = helper(r+1, c-1, rows, cols, matrix, DP);
        int way2 = helper(r+1, c, rows, cols, matrix, DP);
        int way3 = helper(r+1, c+1, rows, cols, matrix, DP);
        return cache = matrix[r][c] + min(way1, min(way2, way3));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> DP(rows, vector<int>(cols, -1));
        int result = INT_MAX;
        for(int c=0; c<cols; c++){
            result = min(result, helper(0, c, rows, cols, matrix, DP));
        }
        return result;
    }
};