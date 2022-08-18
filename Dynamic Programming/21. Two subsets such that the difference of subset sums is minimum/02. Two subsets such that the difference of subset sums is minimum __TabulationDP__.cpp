/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTab=0
    TC - O(n*target)
    SC - O(n*target)
*/

int minSubsetSumDifference(vector<int>& nums, int n)
{
    if(n == 1) return nums[0];
    
    int totalSum = 0;
    for(auto num : nums){
        totalSum += num;
    }
    
    int target = totalSum/2;
    vector<vector<bool>> DP(n, vector<bool>(target+1, false));
    
    for(int r = 0; r < n; r++){
        DP[r][0] = true;
    }
    if(nums[0]<=target)
        DP[0][nums[0]] = true;

    for(int r=1; r<n; r++){
        for(int c=1; c<=target; c++){
            DP[r][c] = DP[r-1][c] | ((nums[r]<=c) ? DP[r-1][c-nums[r]] : false);
        }
    }
    int miniDiff = totalSum;
    for(int k = target ; k>=0 ; k--){
        if(DP[n-1][k] == true){
            int subsetOne = k;
            int subsetTwo = totalSum - k;
            miniDiff = min(miniDiff, abs(subsetOne - subsetTwo));
            return miniDiff;
        }
    }
    
    return miniDiff;
}