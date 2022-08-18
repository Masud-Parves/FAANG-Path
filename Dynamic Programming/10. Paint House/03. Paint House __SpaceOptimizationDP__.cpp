/*
    Problems Link : https://leetcode.com/problems/paint-house/
    TC - O(n)
    SC - O(1) 
*/

class Solution {
public:
int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int> previous(4), current(4);

        previous[0] = min(costs[0][1], costs[0][2]);
        previous[1] = min(costs[0][0], costs[0][2]);
        previous[2] = min(costs[0][0], costs[0][1]);
        previous[3] = min(costs[0][0], min(costs[0][1], costs[0][2]));

        for(int i=1; i<n; i++){
            for(int last=0; last<4; last++){
                current[last] = INT_MAX;
                for(int k=0; k<3; k++){
                    if(last == k) continue;
                    current[last] = min(current[last], costs[i][k] + previous[k]);
                }
            }
            previous = current;
        }

        return previous[3];
    }
};