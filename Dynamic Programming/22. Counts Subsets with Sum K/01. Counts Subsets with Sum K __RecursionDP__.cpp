/*
    Problems Link : https://leetcode.com/problems/target-sum/
    TC - O(n*target)
    SC - O(n*target) + O(n) Recursion Stack Memory
*/

class Solution {
private:
    int calculateWays(int idx, int target, vector<int>& nums, vector<vector<int>>&DP){
        if(idx == nums.size()-1){
            if(target == 0 && nums[idx] == 0) return 2;
            if(target == 0 || target == nums.back()) return 1;
            return 0;
        }
        
        int &cache = DP[idx][target];
        if(cache != -1){
            return cache;
        }
        
        int pick = 0, not_pick = 0;
        not_pick = calculateWays(idx+1, target, nums, DP);
        if(nums[idx]<=target) {
            pick = calculateWays(idx+1, target-nums[idx], nums, DP);
        }
        
        return cache = (pick + not_pick);
    }
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
        vector<vector<int>> DP(n, vector<int>(amount+1, -1));
        int ways = calculateWays(0, amount, nums, DP);
        return ways;
    }
};