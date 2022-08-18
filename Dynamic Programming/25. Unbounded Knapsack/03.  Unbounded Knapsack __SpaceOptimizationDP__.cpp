#include<bits/stdc++.h>

/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?leftPanelTab=0
    TC - O(n*weight)
    SC - O(weight)
*/

int unboundedKnapsack(int n, int maxCapacity, vector<int> &profit, vector<int> &weight)
{
    vector<int>previousRow(maxCapacity+1, 0) , currentRow(maxCapacity+1, 0);
    for(int c=0; c<=maxCapacity; c++){
        if(c>=weight[0]){
            previousRow[c] = profit[0]*(c/weight[0]);
        }
    }
    
    for(int idx=1; idx<n ; idx++){
        for(int c=0; c<=maxCapacity; c++){
            int way1 = previousRow[c], way2 = INT_MIN;
            if(weight[idx]<=c) {
                way2 = profit[idx] + currentRow[c-weight[idx]];
            }
            currentRow[c] = max(way1, way2);
        }
        previousRow = currentRow;
    }
    return previousRow[maxCapacity];
}