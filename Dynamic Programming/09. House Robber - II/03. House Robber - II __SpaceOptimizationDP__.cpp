/*
    Problems Link : https://leetcode.com/problems/house-robber-ii/
    TC - O(n)
    SC - O(1)
*/

class Solution {
private:
    int rob_I(vector<int>& nums, int start) {
        int n = nums.size();
        int next, nextOfNext, current=0;

        next = nums[n-1-(start==0)];
        for(int idx = n-2-(start==0); idx>=start; idx--){
            current = nums[idx];
            if(idx+2<n-(start==0)){
                current += nextOfNext;
            }
            current = max(current, next);
            nextOfNext = next;
            next = current;
        }
        return next;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        return max(rob_I(nums, 0), rob_I(nums, 1));
    }
};