/*
    Problems Link : https://leetcode.com/problems/minimum-path-sum/
    TC - O(rows*cols)
    SC - O(cols)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> previous(cols, INT_MAX/2);

        for(int r=0; r<rows; r++){
            vector<int> current(cols, INT_MAX/2);
            for(int c=0; c<cols; c++){
                if(r==0 && c==0) current[c] = grid[r][c];
                else {
                    if(r>0) current[c] = min(current[c], grid[r][c] + previous[c]);
                    if(c>0) current[c] = min(current[c], grid[r][c] + current[c-1]);
                }
            }
            previous = current;
        }

        return previous[cols-1];
    }
};