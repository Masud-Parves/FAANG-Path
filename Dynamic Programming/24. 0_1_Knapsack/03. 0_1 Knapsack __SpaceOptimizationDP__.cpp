/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?leftPanelTab=0
    TC - O(n*weight)
    SC - O(weight)
*/

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<int>previousRow(maxWeight+1, 0), currentRow(maxWeight+1, 0);
    for(int w=weight[n-1] ;w<=maxWeight; w++){
        previousRow[w] = value[n-1];
    }

    for(int i=n-2; i>=0 ; i--){
        for(int w=1; w<=maxWeight; w++){
            int way1 = previousRow[w], way2 = INT_MIN;
            if(weight[i]<=w){
                way2 = value[i] + previousRow[w-weight[i]];
            }
            currentRow[w] = max(way1, way2);
        }
        previousRow = currentRow;
    }
    return previousRow[maxWeight];
}