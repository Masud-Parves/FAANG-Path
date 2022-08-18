/*
    Problems Link : https://leetcode.com/problems/unique-paths-ii/
    TC - O(row*col)
    SC - O(row*col)
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> DP(row, vector<int>(col, 0));
        
        for(int r = 0; r<row ; r++){
          for(int c = 0; c<col ; c++){
              if(r==0 && c==0) {
                  DP[r][c] = 1;
              } else if(obstacleGrid[r][c] == 1){
                  DP[r][c] = 0;
              } else {
                  if(r>0) DP[r][c] += DP[r-1][c];
                  if(c>0) DP[r][c] += DP[r][c-1];
              }
          }
        }
        return DP[row-1][col-1];
    }
};