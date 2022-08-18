/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?leftPanelTab=1
    TC - O(n*target)
    SC - O(n*target) + O(n) Recursion Stack Memory
*/

int MOD = (int)(1e9+7);

int calculateSubsetSumToK(int idx, int target, vector<int> &nums, vector<vector<int>>& DP){
    if(idx == 0){
        if(target == 0 && nums[0] == 0) return 2;
        if(target == 0 || target == nums[0]) return 1;
        return 0;
    }
    
    int &cache = DP[idx][target];
    if(cache != -1) {
        return cache;
    }
    
    int pick = 0, not_pick;
    
    if(nums[idx] <= target){
        pick = calculateSubsetSumToK(idx-1, target-nums[idx], nums, DP);
    }
    not_pick = calculateSubsetSumToK(idx-1, target, nums, DP);
    return cache = (pick + not_pick)%MOD;
}

int countPartitions(int n, int d, vector<int> &nums) {
    
    int totalSum = 0;
    for(auto val : nums){
        totalSum += val;
    }
    
    if((totalSum-d)<0 || (totalSum-d)%2) return 0;
    
    int target = (totalSum - d)/2;
    vector<vector<int>>DP(n, vector<int>(target+1, -1));
    return calculateSubsetSumToK(n-1, target, nums, DP);
}