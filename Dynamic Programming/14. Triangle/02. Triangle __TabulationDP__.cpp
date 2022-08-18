/*
    Problems Link : https://leetcode.com/problems/triangle/
    TC - O(rows*cols)
    SC - O(rows*cols)
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<vector<int>> DP(rows);

        for(int r=0; r<rows; r++){
            DP[r].resize(r+1);
            for(int c=0; c<=r; c++){
                DP[r][c] = INT_MAX/2;
            }
        }
        // Base Case
        for(int c=0; c<rows; c++){
            DP[rows-1][c] = triangle[rows-1][c];
        }
        
        for(int r=rows-2; r>=0; r--){
            for(int c=r; c>=0 ; c--){
                DP[r][c] = min(DP[r][c], triangle[r][c]+DP[r+1][c]);
                DP[r][c] = min(DP[r][c], triangle[r][c]+DP[r+1][c+1]);
            }
        }
        
        return DP[0][0];
    }
};