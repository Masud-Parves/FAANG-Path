/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?leftPanelTab=1
    TC - O(n*target)
    SC - O(n*target)
*/

int MOD = (int)(1e9+7);

int countPartitions(int n, int d, vector<int> &nums) {
    
    int totalSum = 0;
    for(auto val : nums){
        totalSum += val;
    }
    
    if((totalSum-d)<0 || (totalSum-d)%2) return 0;
    
    int target = (totalSum - d)/2;
    vector<vector<int>>DP(n, vector<int>(target+1, 0));
    
    if(nums[0] == 0) DP[0][0] = 2;
    else DP[0][0] = 1;
    if(nums[0] != 0 && nums[0]<=target) DP[0][nums[0]] = 1;
    
    for(int r=1; r<n ; r++){
        for(int c=0; c<=target; c++){
            DP[r][c] = (DP[r-1][c] + ((nums[r]<=c) ? DP[r-1][c-nums[r]] : 0))%MOD;
        }
    }
    
    return DP[n-1][target];
}