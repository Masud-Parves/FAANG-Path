/*
    Problems Link : https://leetcode.com/problems/climbing-stairs/
    TC - O(n)
    SC - O(1)
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return n;
        int lastClimb = 1, secondLastClimb = 1, currentClimb = 0;
        for(int i=2; i<=n; i++){
            currentClimb = secondLastClimb + lastClimb;
            secondLastClimb = lastClimb;
            lastClimb = currentClimb;
        }
        return currentClimb;
    }
};