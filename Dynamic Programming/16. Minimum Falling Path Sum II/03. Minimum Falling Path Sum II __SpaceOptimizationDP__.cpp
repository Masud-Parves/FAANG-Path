/*
    Problems Link : https://leetcode.com/problems/minimum-falling-path-sum-ii/
    TC - O(N^2)
    SC - O(N)
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> previousRow(n, INT_MAX/2);
        int result = INT_MAX;
        for(int c=0; c<n; c++){
            previousRow[c] = grid[0][c];
        }
        
        for(int r=1; r<n ; r++){
            vector<int> currentRow(n, INT_MAX/2);
            for(int p=0; p<n; p++){
                for(int c=0; c<n; c++){
                    if(p==c) continue;
                    currentRow[c] = min(currentRow[c], grid[r][c] + previousRow[p]);
                }
            }
            previousRow = currentRow;
        }

        for(int c=0; c<n; c++){
            result = min(result, previousRow[c]);
        }
        return result;
    }
};