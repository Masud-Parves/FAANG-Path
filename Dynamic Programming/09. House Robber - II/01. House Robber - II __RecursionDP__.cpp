/*
    Problems Link : https://leetcode.com/problems/house-robber-ii/
    TC - O(n)
    SC - O(n) + O(n) Recursion Stack Memory
    N.B : This is maily 2 pass DP.
    Time Complexity will be 2*n but we ignore constant
*/

class Solution {
private:
    int rob_I(int idx, vector<int>& nums, vector<int>& DP, int n){
        if(idx == n-1){
            return nums[idx];
        }
        int& cache = DP[idx];
        if(cache != -1){
            return cache;
        }
        
        int way1, way2;
        way1 = rob_I(idx+1, nums, DP, n);
        way2 = nums[idx];
        if(idx+2<n) way2 += rob_I(idx+2, nums, DP, n);
        return cache = max(way1 , way2);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> DP(n, -1);
        int result = rob_I(0, nums, DP, n-1);
        fill(DP.begin(), DP.end(), -1);
        result = max(result, rob_I(1, nums, DP, n));
        return result;
    }
};