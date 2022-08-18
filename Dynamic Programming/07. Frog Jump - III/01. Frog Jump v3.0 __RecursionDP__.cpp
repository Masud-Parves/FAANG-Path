/*
    Problems Link : https://leetcode.com/problems/frog-jump/
    TC - O(n^2)
    SC - O(n^2) + O(n) Recursion Stack Memory
*/

/*
    Input: stones = [0,1,3,5,6,8,12,17]
    Output: true
*/

class Solution {
private:
    int helper(int idx, int prevIdx, unordered_map<int, int>& seen, vector<int>& stones, vector<vector<int>>& DP, int n){
        if(seen[stones[idx]] == n-1){
            return 1;
        }

        int& cache = DP[idx][prevIdx];
        if(cache != -1){
            return cache;
        }

        cache = 0;
        bool state = false;
        if(prevIdx-1!=0 && seen.find(stones[idx]+prevIdx-1) != seen.end()){
            state |= helper(seen[stones[idx]+prevIdx-1], prevIdx-1, seen, stones, DP, n);
            if(state) return cache = state;
        }

        if(seen.find(stones[idx]+prevIdx) != seen.end()){
            state |= helper(seen[stones[idx]+prevIdx], prevIdx, seen, stones, DP, n);
            if(state) return cache = state;
        }

        if(seen.find(stones[idx]+prevIdx+1) != seen.end()){
            state |= helper(seen[stones[idx]+prevIdx+1], prevIdx+1, seen, stones, DP, n);
            if(state) return cache = state;
        }
        return cache = state;
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if(stones[0] + 1<stones[1]) return false;
        unordered_map<int, int> seen;
        for(int i=0; i<n; i++){
            seen[stones[i]] = i;
        }

        vector<vector<int>> DP(n+1, vector<int>(n+1, -1));



        return helper(1, 1, seen, stones, DP, n);
    }
};