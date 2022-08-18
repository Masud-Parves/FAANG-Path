/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954
    TC - O(n*target)
    SC - O(n*target)
*/

bool subsetSumToK(int n, int k, vector<int> &nums) {
    if(n == 1) return k == nums[0];
    vector<vector<bool>> DP(n, vector<bool>(k+1, false));

    for(int i = 0; i<n ; i++){
        DP[i][0] = true;
    }
    DP[0][nums[0]] = true;
    
    for(int i = 1; i<n ; i++){
        for(int target=1 ; target<=k ; target++){
            DP[i][target] = DP[i-1][target] | ((nums[i]<=target) ? DP[i-1][target-nums[i]] : false);
        }
    }
    return DP[n-1][k];
}