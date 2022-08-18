/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?leftPanelTab=1
    TC - O(n*target)
    SC - O(target)
*/

int MOD = (int)(1e9+7);

int countPartitions(int n, int d, vector<int> &nums) {
    
    int totalSum = 0;
    for(auto val : nums){
        totalSum += val;
    }
    
    if((totalSum-d)<0 || (totalSum-d)%2) return 0;
    
    int target = (totalSum - d)/2;
    vector<int>previousRow(target+1, 0), currentRow(target+1, 0);
    
    if(nums[0] == 0) previousRow[0] = 2;
    else previousRow[0] = 1;
    if(nums[0] != 0 && nums[0]<=target) previousRow[nums[0]] = 1;
    
    for(int r=1; r<n ; r++){
        for(int c=0; c<=target; c++){
            currentRow[c] = (previousRow[c] + ((nums[r]<=c) ? previousRow[c-nums[r]] : 0))%MOD;
        }
        previousRow = currentRow;
    }
    
    return previousRow[target];
}