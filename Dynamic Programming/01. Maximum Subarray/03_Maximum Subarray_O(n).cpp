/*
    Problems Link : https://leetcode.com/problems/maximum-subarray/
    TC - O(n)
    SC - O(n)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return nums[0];

        int maxSubarraySum = nums[0];

        vector<int> maxSumEnd(n);
        maxSumEnd[0] = nums[0];

        for(int i=1; i<n; i++){
            maxSumEnd[i] = max(maxSumEnd[i-1]+nums[i], nums[i]);
            maxSubarraySum = max(maxSubarraySum, maxSumEnd[i]);
        }
        return maxSubarraySum;
    }
};