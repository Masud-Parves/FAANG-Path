/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?leftPanelTab=0
    TC - O(n*weight)
    SC - O(n*weight) + O(n) Recursion Stack Memory
*/

int calculateMaxProfit(int idx, vector<int> weight, vector<int> value, int n, int maxWeight, vector<vector<int>>& DP){
	if(idx == n-1){
		if(weight[idx]<=maxWeight){
			return value[idx];
		}
		return 0;
	}

	if(maxWeight == 0) return 0;
	int& cache = DP[idx][maxWeight];
	if(cache != -1){
		return cache;
	}

	int way1 = 0, way2 = INT_MIN;
	way1 = calculateMaxProfit(idx+1, weight, value, n, maxWeight, DP);
	if(weight[idx]<=maxWeight){
		way2 = value[idx] + calculateMaxProfit(idx+1, weight, value, n, maxWeight-weight[idx], DP);
	}
	return cache = max(way1 , way2);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> DP(n, vector<int>(maxWeight+1, -1));
	return calculateMaxProfit(0, weight, value, n, maxWeight, DP);
}