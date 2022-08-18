/*
    Problems Link : https://leetcode.com/problems/unique-paths-ii/
    TC - O(row*col)
    SC - O(col)
*/
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int row = obstacleGrid.size(), col = obstacleGrid[0].size();
      if(obstacleGrid[0][0] == 1) return 0;
      vector<int> previous(col, 0);
      
      for(int r = 0; r<row ; r++){
        vector<int> current(col, 0);
        for(int c = 0; c<col ; c++){
            if(obstacleGrid[r][c] == 1){
                current[c] = 0;
                continue;
            }
            if(r==0 && c==0) {
                current[0] = 1;
            }  else {
                if(r>0) current[c] += previous[c];
                if(c>0) current[c] += current[c-1];
            }
        }
        previous = current;
      }
      return previous[col-1];
  }
};