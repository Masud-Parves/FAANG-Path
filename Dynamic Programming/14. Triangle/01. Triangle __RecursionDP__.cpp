/*
    Problems Link : https://leetcode.com/problems/triangle/
    TC - O(rows*cols)
    SC - O(rows*cols) + O(max(rows, cols)) Recursion Stack Memory.
*/

class Solution {
private:
    int helper(int r, int c, vector<vector<int>>& triangle, vector<vector<int>>& DP, int rows){
        if(r == rows-1){
            return triangle[r][c];
        }

        int& cache = DP[r][c];
        if(cache != -1){
            return cache;
        }
        int way1, way2;
        way1 = triangle[r][c] + helper(r+1, c, triangle, DP, rows);
        way2 = triangle[r][c] + helper(r+1, c+1, triangle, DP, rows);
        return cache = min(way1, way2);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<vector<int>> DP(rows);

        for(int r=0; r<rows; r++){
            DP[r].resize(r+1);
            for(int c=0; c<=r; c++){
                DP[r][c] = -1;
            }
        }
        return helper(0, 0, triangle, DP, rows);
    }
};