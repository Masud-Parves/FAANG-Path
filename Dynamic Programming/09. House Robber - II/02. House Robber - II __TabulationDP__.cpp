/*
    Problems Link : https://leetcode.com/problems/house-robber-ii/
    TC - O(n)
    SC - O(n)
    N.B : This is maily 2 pass DP.
    Time Complexity will be 2*n but we ignore constant
*/

class Solution {
private:
    int rob_I(vector<int>& nums, int start) {
        int n = nums.size();
        vector<int> DP(n, 0);
        DP[n-1-(start==0)] = nums[n-1-(start==0)];
        for(int idx = n-2-(start==0); idx>=start; idx--){
            DP[idx] += nums[idx];
            if(idx+2<n-(start==0)){
                DP[idx] += DP[idx+2];
            }
            DP[idx] = max(DP[idx], DP[idx+1]);
        }
        return DP[0+start];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        return max(rob_I(nums, 0), rob_I(nums, 1));
    }
};