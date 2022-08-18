#include<bits/stdc++.h>

/*
    Problem Name : Jump with K Distance
    Problem Link : https://atcoder.jp/contests/dp/tasks/dp_b
    TC - O(n*k)
    SC - (n)
*/

using namespace std;

int frogJumpV2(int n, vector<int> &heights, int k){
    vector<int> DP(n+1, 0);

    for(int i=n-2; i>=0 ; i--){
        DP[i] = INT_MAX;
        for(int j=1; j<=k; j++){
            if(i+j<n){
                DP[i] = min(DP[i], abs(heights[i]-heights[i+j]) + DP[i+j]);
            }
        }
    }

    return DP[0];
}