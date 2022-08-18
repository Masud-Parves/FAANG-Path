/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954
    TC - O(n*target)
    SC - O(target)
*/

bool subsetSumToK(int n, int k, vector<int> &nums) {
    if(n == 1) return k == nums[0];
    vector<bool> previousRow(k+1, false), currentRow(k+1, false);
    
    previousRow[0] = currentRow[0] = tru
    previousRow[nums[0]] = true;
    
    for(int r = 1; r<n ; r++){
        for(int c=1 ; c<=k ; c++){
            currentRow[c] = previousRow[c] | ((nums[r]<=c) ? previousRow[c-nums[r]] : false);
        }
        previousRow = currentRow;
    }
    return previousRow[k];
}