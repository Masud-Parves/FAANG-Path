/*
    Problems Link : https://leetcode.com/problems/maximum-subarray/
    TC - O(n^3)
    SC - O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxiSum = INT_MIN;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                
                int currSubSum = 0;
                for(int k=i; k<=j; k++){
                    currSubSum += nums[k];
                }

                maxiSum = max(maxiSum, currSubSum);
            }
        }
        return maxiSum;
    }
};