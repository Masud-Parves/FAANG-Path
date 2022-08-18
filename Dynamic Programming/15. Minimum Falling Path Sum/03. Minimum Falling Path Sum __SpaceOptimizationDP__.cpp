/*
    Problems Link : https://leetcode.com/problems/minimum-falling-path-sum/
    TC - O(rows*cols)
    SC - O(cols)
*/

class Solution {
public:
int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> previousRow(cols, INT_MAX/2);
        int result = INT_MAX;
        
        for(int i=0; i<cols; i++){
            previousRow[i] = matrix[0][i];
        }

        for(int r=1; r<rows; r++){
            vector<int> currentRow(cols, INT_MAX/2);
            for(int c=0; c<cols ; c++){
                currentRow[c] = min(currentRow[c], matrix[r][c] + previousRow[c]);
                if(c+1<cols) {
                    currentRow[c] = min(currentRow[c], matrix[r][c] + previousRow[c+1]);
                }
                if(c>0) {
                    currentRow[c] = min(currentRow[c], matrix[r][c] + previousRow[c-1]);
                }
            }
            previousRow = currentRow;
        }

        for(int i=0; i<cols; i++){
            result = min(result, previousRow[i]);
        }
        return result;
    }
};