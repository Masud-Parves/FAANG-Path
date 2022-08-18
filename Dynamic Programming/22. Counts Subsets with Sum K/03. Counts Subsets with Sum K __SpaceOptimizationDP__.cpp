/*
    Problems Link : https://leetcode.com/problems/target-sum/
    TC - O(n*target)
    SC - O(target)
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for(auto val : nums){
            totalSum += val;
        }

        int amount = totalSum - target;
        if(amount< 0 || amount%2 != 0) return 0;
        amount = (totalSum-target)/2;
        vector<int>previousRow(amount+1, 0), currentRow(amount+1, 0);
        
        previousRow[0] = 1 + (nums[0] == 0);
        if(nums[0] != 0 && nums[0]<=amount) previousRow[nums[0]] = 1;      
        
        for(int idx = 1; idx<n ; idx++){
            for(int t = 0; t<=amount ; t++){
                currentRow[t] =  previousRow[t];
                if(nums[idx]<=t) {
                    currentRow[t] += previousRow[t-nums[idx]];
                }
            }
            previousRow = currentRow;
        }
        return previousRow[amount];
    }
};