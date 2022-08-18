#include<bits/stdc++.h>

/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0
    TC - O(n)
    SC - O(n) + O(n) Recursion Stack Memory
*/


int helper(int idx, vector<int>& heights, vector<int>& DP){
    int n = heights.size();
    if(idx == n-1){
        return 0;
    }
    
    int& cache = DP[idx];
    if(cache != -1){
        return cache;
    }
    
    int way1, way2 = INT_MAX;
    way1 = abs(heights[idx] - heights[idx+1]) + helper(idx+1, heights, DP);
    if(idx+2<n){
        way2 = abs(heights[idx] - heights[idx+2]) + helper(idx+2, heights, DP);
    }
    return cache = min(way1, way2);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> DP(n+1, -1);
    return helper(0, heights, DP);
}