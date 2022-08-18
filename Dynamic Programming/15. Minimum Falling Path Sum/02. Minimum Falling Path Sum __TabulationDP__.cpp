/*
    Problems Link : https://leetcode.com/problems/minimum-falling-path-sum/
    TC - O(rows*cols)
    SC - O(rows*cols)
*/

class Solution {
public:
int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> DP(rows, vector<int>(cols, INT_MAX/2));
        int result = INT_MAX;
        
        for(int i=0; i<cols; i++){
            DP[0][i] = matrix[0][i];
        }

        for(int r=1; r<rows; r++){
            for(int c=0; c<cols ; c++){
                DP[r][c] = min(DP[r][c], matrix[r][c] + DP[r-1][c]);
                if(c+1<cols) {
                    DP[r][c] = min(DP[r][c], matrix[r][c] + DP[r-1][c+1]);
                }
                if(c>0) {
                    DP[r][c] = min(DP[r][c], matrix[r][c] + DP[r-1][c-1]);
                }
            }
        }

        for(int i=0; i<cols; i++){
            result = min(result, DP[rows-1][i]);
        }
        return result;
    }

};