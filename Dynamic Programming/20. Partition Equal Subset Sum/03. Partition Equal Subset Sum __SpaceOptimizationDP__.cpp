/*
    Problems Link : https://leetcode.com/problems/partition-equal-subset-sum/
    TC - O(n*target)
    SC - O(target)
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto& num : nums){
            sum += num;
        }
        if(sum&1 || n<=1) return false;
        int target = sum/2;
        vector<bool> nextRow(target+1, false), currentRow(target+1, false);
        nextRow[0] = true;
        nextRow[nums[n-1]] = true;

        for(int i=n-2; i>=0; i--){
            for(int t=1; t<=target; t++){
                currentRow[t] = nextRow[t];
                if(t-nums[i]>=0) currentRow[t] = currentRow[t] | nextRow[t-nums[i]];
            }
            nextRow = currentRow;
        }

        return nextRow[target];
    }
};