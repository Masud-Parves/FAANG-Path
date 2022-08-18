/*
    Problems Link : https://leetcode.com/problems/triangle/
    TC - O(rows*cols)
    SC - O(rows)
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<int> next(rows, INT_MAX/2);

        // Base Case
        for(int c=0; c<rows; c++){
            next[c] = triangle[rows-1][c];
        }
        
        for(int r=rows-2; r>=0; r--){
            vector<int> current(rows, INT_MAX/2);
            for(int c=r; c>=0 ; c--){
                current[c] = min(current[c], triangle[r][c]+next[c]);
                current[c] = min(current[c], triangle[r][c]+next[c+1]);
            }
            next = current;
        }
        
        return next[0];
    }
};