/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?leftPanelTab=0
    TC - O(cut*capacity)
    SC - O(capacity)
*/

int cutRod(vector<int> &price, int n)
{
    vector<int>previousRow(n+1, INT_MIN), currentRow(n+1, INT_MIN);
    for(int capacity = 0; capacity<=n; capacity++){
        previousRow[capacity] = price[0]*capacity;
    }

    for(int cut = 1; cut<n ; cut++){
        for(int capacity = 0; capacity<=n; capacity++){
            int way1 = previousRow[capacity], way2 = INT_MIN;
            if(capacity>=cut+1){
                way2 = price[cut] + currentRow[capacity-cut-1];
            }
            currentRow[capacity] = max(way1,way2);
        }
        previousRow = currentRow;
    }
    return previousRow[n];
}
