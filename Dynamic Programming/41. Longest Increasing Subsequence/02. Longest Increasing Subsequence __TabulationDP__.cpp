/*
    Problems Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    TC - O(n*n)
    SC - O(n)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>nextRow(n+1, 0), curentRow(n+1, 0);

        for(int i=n-1; i>=0; i--){
        	for(int p=i-1; p>=-1; p--){
        		currentRow[p+1] = nextRow[p+1];
        		if(p == -1 || nums[p]<nums[i]){
        			currentRow[p+1] = max(currentRow[p+1], 1 + nextRow[i+1]); 
        		}
        	}
        	nextRow = currentRow;
        }
        return nextRow[0];
    }
};