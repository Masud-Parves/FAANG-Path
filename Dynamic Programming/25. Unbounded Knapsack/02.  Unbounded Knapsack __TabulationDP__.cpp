#include<bits/stdc++.h>

/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?leftPanelTab=0
    TC - O(n*weight)
    SC - O(n*weight)
*/

int unboundedKnapsack(int n, int maxCapacity, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>>DP(n, vector<int>(maxCapacity+1, 0));
    for(int c=0; c<=maxCapacity; c++){
        if(c>=weight[0]){
            DP[0][c] = profit[0]*(c/weight[0]);
        }
    }
    
    for(int idx=1; idx<n ; idx++){
        for(int c=0; c<=maxCapacity; c++){
            int way1 = DP[idx-1][c], way2 = INT_MIN;
            if(weight[idx]<=c) {
                way2 = profit[idx] + DP[idx][c-weight[idx]];
            }
            DP[idx][c] = max(way1, way2);
        }
    }
    return DP[n-1][maxCapacity];
}
