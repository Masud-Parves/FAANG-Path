/*
    Problems Link : https://leetcode.com/problems/target-sum/
    TC - O(n*target)
    SC - O(n*target)
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for(auto val : nums){
            totalSum += val;
        }

        int amount = totalSum - target;
        if(amount< 0 || amount%2 != 0) return 0;
        amount = (totalSum-target)/2;
        vector<vector<int>> DP(n, vector<int>(amount+1, 0));
        
        DP[0][0] = 1 + (nums[0] == 0);
        if(nums[0] != 0 && nums[0]<=amount) DP[0][nums[0]] = 1;      
        
        for(int idx = 1; idx<n ; idx++){
            for(int t = 0; t<=amount ; t++){
                DP[idx][t] =  DP[idx-1][t];
                if(nums[idx]<=t) {
                    DP[idx][t] += DP[idx-1][t-nums[idx]];
                }
            }
        }
        return DP[n-1][amount];
    }
};