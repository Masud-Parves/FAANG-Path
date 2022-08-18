/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTab=0
    TC - O(n*target)
    SC - O(target)
*/

int minSubsetSumDifference(vector<int>& nums, int n)
{
    if(n == 1) return nums[0];
    
    int totalSum = 0;
    for(auto num : nums){
        totalSum += num;
    }
    
    int target = totalSum/2;
    vector<bool>previousRow(target+1, false), currentRow(target+1, false);
    
    currentRow[0] = previousRow[0] = true;
    if(nums[0]<=target)
        previousRow[nums[0]] = true;

    for(int r=1; r<n; r++){
        for(int c=1; c<=target; c++){
            currentRow[c] = previousRow[c] | ((nums[r]<=c) ? previousRow[c-nums[r]] : false);
        }
        previousRow = currentRow;
    }

    int miniDiff = totalSum;
    for(int k = target ; k>=0 ; k--){
        if(previousRow[k] == true){
            int subsetOne = k;
            int subsetTwo = totalSum - k;
            miniDiff = min(miniDiff, abs(subsetOne - subsetTwo));
            return miniDiff;
        }
    }
    
    return miniDiff;
}