/*
    Problems Link : https://leetcode.com/problems/partition-equal-subset-sum/
    TC - O(n*target)
    SC - O(n*target) + O(n) Recursion Stack Memory.
*/

class Solution {
private:
    int helper(int idx, int target, vector<int>& nums, vector<vector<int>>& DP){
        if(idx == nums.size()-1){
            return target == nums[idx];
        }

        if(target == 0) {
            return 1;
        }
        
        int& cache = DP[idx][target];
        if(cache != -1){
            return cache;
        }

        int way1 = 0, way2 = 0;
        way1 = helper(idx+1, target, nums, DP);
        if(target-nums[idx]>=0){
            way2 = helper(idx+1, target-nums[idx], nums, DP);
        }
        return cache = (way1 | way2);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto& num : nums){
            sum += num;
        }
        if(sum&1) return false;
        int target = sum/2;
        vector<vector<int>> DP(n, vector<int>(target+1, -1));
        return helper(0, target, nums, DP);
    }
};