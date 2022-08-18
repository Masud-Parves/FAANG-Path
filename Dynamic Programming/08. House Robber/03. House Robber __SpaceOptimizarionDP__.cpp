/*
    Problems Link : https://leetcode.com/problems/house-robber/
    TC - O(n)
    SC - O(1)
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int next, nextOfNext, current=0;

        next = nums[n-1];
        for(int idx = n-2; idx>=0; idx--){
            current = nums[idx];
            if(idx+2<n){
                current += nextOfNext;
            }
            current = max(current, next);
            nextOfNext = next;
            next = current;
        }
        return next;
    }
};