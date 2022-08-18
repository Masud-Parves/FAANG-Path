/*
    Problems Link : https://leetcode.com/problems/maximum-subarray/
    TC - O(n^2)
    SC - O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxiSum = INT_MIN;

        for(int i=0; i<n; i++){
            int currSubSum = 0;
            for(int j=i; j<n; j++){
                currSubSum += nums[j];

                maxiSum = max(maxiSum, currSubSum);
            }
        }
        return maxiSum;
    }
};