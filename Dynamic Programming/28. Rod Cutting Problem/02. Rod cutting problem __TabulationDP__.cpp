/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?leftPanelTab=0
    TC - O(cut*capacity)
    SC - O(cut*capacity)
*/

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> DP(n, vector<int>(n+1, INT_MIN));

	for(int capacity = 0; capacity<=n; capacity++){
		DP[0][capacity] = price[0]*capacity;
	}

	for(int cut = 1; cut<n ; cut++){
		for(int capacity = 0; capacity<=n; capacity++){
			int way1 = DP[cut-1][capacity], way2 = INT_MIN;
			if(capacity>=cut+1){
				way2 = price[cut] + DP[cut][capacity-cut-1];
			}
			DP[cut][capacity] = max(way1,way2);
		}
	}

    return DP[n-1][n];
}
