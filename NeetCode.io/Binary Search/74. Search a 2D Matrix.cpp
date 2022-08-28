class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int L = 0, R = (row*col)-1, privotIndex = 0;
        
        while(L<=R){
            privotIndex = L + (R-L)/2;
            int curVal = matrix[privotIndex/col][privotIndex%col];
            if(curVal == target) return true;
            if(curVal < target) L = privotIndex+1;
            else R = privotIndex-1;
        }
        return false;
    }
};