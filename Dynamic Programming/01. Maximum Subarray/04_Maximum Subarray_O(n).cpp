/*
    Problems Link : https://leetcode.com/problems/maximum-subarray/
    TC - O(n)
    SC - O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return nums[0];

        int maxSubarraySum = nums[0];
        int maxSumEnd = nums[0];
        

        for(int i=1; i<n; i++){
            maxSumEnd = max(maxSumEnd+nums[i], nums[i]);
            maxSubarraySum = max(maxSubarraySum, maxSumEnd);
        }
        return maxSubarraySum;
    }
};