/*
    Problems Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    TC - O(n*n)
    SC - O(n*n) + O(n) Recursion Stack Memory
*/

class Solution {
private:
	int calculateLIS(int now, int pre, vector<int>& nums, vector<vector<int>>& DP){
        if(now == nums.size()) return 0;
        
        int &cache = DP[now][pre+1];
        if(cache != -1){
            return cache;
        }
        
        cache = calculateLIS(now+1, pre, nums, DP);
        if(pre == -1 || nums[now] > nums[pre]){
            cache = max(cache, 1+calculateLIS(now+1, now, nums, DP));
        }
        return cache;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> DP(n+1, vector<int>(n+1, -1));
        int result = calculateLIS(0, -1, nums, DP);
        return result;
    }
};