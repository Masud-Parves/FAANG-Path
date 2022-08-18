/*
    Problems Link : https://leetcode.com/problems/paint-house/
    TC - O(n)
    SC - O(n) 
*/

class Solution {
public:
int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> DP(n, vector<int>(4));

        DP[0][0] = min(costs[0][1], costs[0][2]);
        DP[0][1] = min(costs[0][0], costs[0][2]);
        DP[0][2] = min(costs[0][0], costs[0][1]);
        DP[0][3] = min(costs[0][0], min(costs[0][1], costs[0][2]));

        for(int i=1; i<n; i++){
            for(int last=0; last<4; last++){
                DP[i][last] = INT_MAX;
                for(int k=0; k<3; k++){
                    if(last == k) continue;
                    DP[i][last] = min(DP[i][last], costs[i][k] + DP[i-1][k]);
                }
            }
        }

        return DP[n-1][3];
    }
};