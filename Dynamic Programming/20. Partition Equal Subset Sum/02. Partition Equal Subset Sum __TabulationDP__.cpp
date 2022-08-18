/*
    Problems Link : https://leetcode.com/problems/partition-equal-subset-sum/
    TC - O(n*target)
    SC - O(n*target)
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto& num : nums){
            sum += num;
        }
        if(sum&1 || n<=1) return false;
        int target = sum/2;
        vector<vector<bool>> DP(n, vector<bool>(target+1, false));

        for(int i=0; i<n; i++){
            DP[i][0] = true;
        }
        DP[n-1][nums[n-1]] = true;

        for(int i=n-2; i>=0; i--){
            for(int t=1; t<=target; t++){
                DP[i][t] = DP[i+1][t];
                if(t-nums[i]>=0) DP[i][t] = DP[i][t] | DP[i+1][t-nums[i]];
            }
        }

        return DP[0][target];
    }
};