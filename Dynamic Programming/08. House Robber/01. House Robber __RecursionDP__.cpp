/*
    Problems Link : https://leetcode.com/problems/house-robber/
    TC - O(n)
    SC - O(n)
*/

class Solution {
private:
    int rob_I(vector<int>& nums, int flag) {
        int n = nums.size();
        vector<int> DP(n, 0);
        DP[n-1-(flag==0)] = nums[n-1-(flag==0)];
        for(int idx = n-2-(flag==0); idx>=0+flag; idx--){
            DP[idx] += nums[idx];
            if(idx+2<n){
                DP[idx] += DP[idx+2];
            }
            DP[idx] = max(DP[idx], DP[idx+1]);
        }
        return DP[0+flag];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        return max(rob_I(nums, 0), rob_I(nums, 1));
    }
};