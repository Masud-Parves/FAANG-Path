#include<bits/stdc++.h>

/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?leftPanelTab=0
    TC - O(n*weight)
    SC - O(n*weight) + O(n) Recursion Stack Memory
*/


int calculateMaxProfit(int idx, int capacity, vector<int> &profit, vector<int> &weight, vector<vector<int>>& DP){
	if(idx < 0 || capacity < 0){
		return 0;
	}
	
	int &cache = DP[idx][capacity];
	if(cache != -1){
		return cache;
	}
	
	int way1 , way2 = INT_MIN;;
	way1 = calculateMaxProfit(idx-1, capacity, profit, weight, DP);
	if(weight[idx]<=capacity){
		way2 = profit[idx] + calculateMaxProfit(idx, capacity-weight[idx], profit, weight, DP);
	}
	return cache = max(way2 , way1);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>>DP(n, vector<int>(w+1, -1));
	int result = calculateMaxProfit(n-1, w, profit, weight, DP);
	return result;
}
