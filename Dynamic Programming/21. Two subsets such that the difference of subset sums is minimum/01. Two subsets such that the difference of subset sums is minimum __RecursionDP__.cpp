/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTab=0
    TC - O(n*target)
    SC - O(n*target) + O(n) Recursion Stack Memory.
*/


int findMinAbsDiff(int idx, int sum1, int target, vector<int>& nums, vector<vector<int>>& DP){
    if(idx<0) {
        int sum2 = target - sum1;
        return abs(sum1 - sum2);
    }

    int &cache = DP[idx][sum1];
    if(cache != -1){
        return cache;
    }

    int takeInSum = findMinAbsDiff(idx-1, sum1+nums[idx], target, nums, DP);
    int notTakeInSum = findMinAbsDiff(idx-1, sum1, target, nums, DP);
    return cache = min(takeInSum , notTakeInSum);
}
int minSubsetSumDifference(vector<int>& nums, int n)
{
    if(n == 1) return nums[0];
    
    int totalSum = 0;
    for(auto num : nums){
        totalSum += num;
    }
    vector<vector<int>> DP(n, vector<int>(totalSum+1, -1));
    
    return findMinAbsDiff(n-1, 0, totalSum, nums, DP);;
}