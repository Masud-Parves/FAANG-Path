#include<bits/stdc++.h>

/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0
    TC - O(n)
    SC - O(n)
*/

int frogJump(int n, vector<int> &heights)
{
    vector<int>DP(n+1, 0);
    for(int i=n-2; i>=0; i--){
        DP[i] = abs(heights[i]-heights[i+1]) + DP[i+1];
        if(i+2<n){
            DP[i] = min(DP[i], abs(heights[i]-heights[i+2]) + DP[i+2]);
        }
    }
    return DP[0];
}