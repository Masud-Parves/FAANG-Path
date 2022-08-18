/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?leftPanelTab=0
    TC - O(n*weight)
    SC - O(n*weight)
*/

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> DP(n, vector<int>(maxWeight+1, 0));
    for(int w=weight[n-1] ;w<=maxWeight; w++){
        DP[n-1][w] = value[n-1];
    }

    for(int i=n-2; i>=0 ; i--){
        for(int w=1; w<=maxWeight; w++){
            int way1 = DP[i+1][w], way2 = INT_MIN;
            if(weight[i]<=w){
                way2 = value[i] + DP[i+1][w-weight[i]];
            }
            DP[i][w] = max(way1, way2);
        }
    }
    return DP[0][maxWeight];
}