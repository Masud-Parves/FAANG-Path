class Solution {
private:
    bool dfs(int u, int p, vector<vector<int>>& graph, vector<bool>& visited){
        if(visited[u] == true) return false;
        
        visited[u] = true;
        
        for(auto& v:graph[u]){
            if(v != p){
                if(dfs(v, u, graph, visited) == false){
                    return false;
                }
            }
        }
        return true;
    }
public:
    // we can slve the problem using BFS, DFS, DSU, Just check the graph is connected and not contain any circle.
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n==1) return true;
        
        vector<vector<int>> graph(n);
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        int ret = dfs(0, -1, graph, visited);
        if(ret == false) return false;
        for(int i=0; i<n; i++){
            if(visited[i] == false) return false;
        }
        return true;
    }
};