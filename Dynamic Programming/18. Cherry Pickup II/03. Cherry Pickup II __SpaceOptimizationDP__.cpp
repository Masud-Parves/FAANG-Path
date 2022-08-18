/*
    Problems Link : https://leetcode.com/problems/cherry-pickup-ii/
    TC - O(rows*cols*cols)
    SC - O(cols*cols)
*/

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> previousRow(cols, vector<int>(cols, 0));

        for(int c1=0; c1<cols; c1++){
            for(int c2=0; c2<cols ; c2++){
                previousRow[c1][c2] = grid[rows-1][c1];
                if(c1 != c2) previousRow[c1][c2] += grid[rows-1][c2];
            }
        }

        for(int r=rows-2; r>=0; r--){
            vector<vector<int>> currentRow(cols, vector<int>(cols, 0));
            for(int c1=0; c1<cols; c1++){
                for(int c2=0; c2<cols; c2++){
                    int result = INT_MIN;

                    for(int c1i=-1; c1i<=1; c1i++){
                        for(int c2i=-1; c2i<=1; c2i++){
                            int cherry = grid[r][c1];
                            if(c1!=c2) cherry+=grid[r][c2];
                            int nextC1 = c1 + c1i, nextC2 = c2 + c2i;
                            if(nextC1<0 || nextC2<0 || nextC1 == cols || nextC2 == cols) continue;
                            result = max(result, cherry+previousRow[nextC1][nextC2]);
                        }
                    }
                    currentRow[c1][c2] = result;
                }
            }
            previousRow = currentRow;
        }
        return previousRow[0][cols-1];
    }
};