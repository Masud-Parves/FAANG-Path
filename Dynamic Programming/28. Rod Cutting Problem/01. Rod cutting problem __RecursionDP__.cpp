/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?leftPanelTab=0
    TC - O(cut*capacity)
    SC - O(cut*capacity) + O(capacity) Recursion Stack Memory
*/


int getMaximumProfit(int cut, int capacity, vector<int>& price, vector<vector<int>>& DP){
    if(cut == 0){
        return capacity*price[cut];
    }
    
    int& cache = DP[cut][capacity];
    if(cache != -1){
        return cache;
    }
    
    int way1 = 0, way2 = INT_MIN;
    way1 = getMaximumProfit(cut-1, capacity, price, DP);
    if(capacity>=cut+1){
        way2 = price[cut] + getMaximumProfit(cut, capacity-cut-1, price, DP);
    }
    return cache = max(way1, way2);
}


int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> DP(n, vector<int>(n+1, -1));
    return getMaximumProfit(n-1, n, price, DP);
}
