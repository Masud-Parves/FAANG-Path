/*
    Problems Link : https://leetcode.com/problems/unique-paths/
    TC - O(row*col)
    SC - O(row*col)
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> DP(m, vector<int>(n, 0));
        for(int r=0; r<m ; r++){
            for(int c=0; c<n; c++){
                if(r==0 && c == 0) DP[r][c] = 1;
                else {
                    if(r>0) DP[r][c] += DP[r-1][c];
                    if(c>0) DP[r][c] += DP[r][c-1];
                }
            }
        }
        return DP[m-1][n-1];
    }
};