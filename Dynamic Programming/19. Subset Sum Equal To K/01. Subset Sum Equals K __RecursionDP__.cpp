/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954
    TC - O(n*target)
    SC - O(n*target) + O(max(n, target)) Recursion Stack Memory.
*/

bool findSubsetSum(int now, int target, vector<int>& nums, vector<vector<int>>& DP){
    if(target == 0) {
        return true;
    }
    if(now == 0){
        return target == nums[now];
    }
    
    int &cache = DP[now][target];
    if(cache != -1){
        return cache;
    }
    
    bool taken = false, not_taken;
    not_taken = findSubsetSum(now-1, target, nums, DP);
    if(nums[now]<=target) taken = findSubsetSum(now-1, target-nums[now], nums, DP);
    return cache = taken | not_taken;
    
}

bool subsetSumToK(int n, int k, vector<int> &nums) {
    
    if(n == 1) return k == nums[0];
    vector<vector<int>> DP(n, vector<int>(k+1, -1));
    
    return findSubsetSum(n-1, k, nums, DP);
}