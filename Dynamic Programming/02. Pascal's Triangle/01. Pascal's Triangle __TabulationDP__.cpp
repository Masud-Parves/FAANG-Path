/*
    Problems Link : https://leetcode.com/problems/pascals-triangle/
    TC - O(numRows^2)
    SC - O(1)
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);
        
        for(int i=0; i<numRows; i++){
            triangle[i].resize(i+1);
            triangle[i][0] = triangle[i][i] = 1;
            for(int k=1; k<i; k++){
                triangle[i][k] = triangle[i-1][k] + triangle[i-1][k-1];
            }
        }
        return triangle;
    }
};