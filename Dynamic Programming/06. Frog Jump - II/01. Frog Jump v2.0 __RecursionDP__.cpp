#include<bits/stdc++.h>

/*
    Problem Name : Jump with K Distance
    Problem Link : https://atcoder.jp/contests/dp/tasks/dp_b
    TC - O(n*k)
    SC - (n) + O(k) Recursion Stack Memory
*/

using namespace std;


int helper(int idx, int n, vector<int>& heights, int k, vector<int>& DP){
    if(idx == n-1){
        return 0;
    }

    int& cache = DP[idx];
    if(cache != -1){
        return cache;
    }

    cache = INT_MAX;
    for(int i=1; i<=k; i++){
        if(idx+i<n){
            cache = min(cache, abs(heights[idx]-heights[idx+i]) + helper(idx+i, n, heights, k, DP));    
        }
    }
    return cache;
}

int frogJumpV2(int n, vector<int> &heights, int k){
    vector<int> DP(n+1, -1);
    return helper(0, n, heights, k);
}