/*
    Problems Link : https://leetcode.com/problems/house-robber/
    TC - O(n)
    SC - O(n)
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> DP(n+1, 0);

        DP[n-1] = nums[n-1];
        for(int idx = n-2; idx>=0; idx--){
            DP[idx] += nums[idx];
            if(idx+2<n){
                DP[idx] += DP[idx+2];
            }
            DP[idx] = max(DP[idx], DP[idx+1]);
        }
        return DP[0];
    }
};