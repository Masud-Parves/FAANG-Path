class Solution {
public:
    // we can slve the problem using BFS, DFS, DSU, Just check the graph is connected and not contain any circle.
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n==1) return true;
        
        vector<vector<int>> graph(n);
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        map<int, int>par;
        par[0] = -1;
        queue<int>Q;
        Q.push(0);
        
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            
            for(auto& v : graph[u]){
                if(par[u] == v) continue;
                if(par.find(v) != par.end()) return false;
                Q.push(v);
                par[v] = u;
            }
        }
        return par.size() == n;
    }
};