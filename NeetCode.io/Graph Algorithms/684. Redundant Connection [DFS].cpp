class Solution {
private:
    bool dfs(int u, int dest, vector<vector<int>>& graph, set<int>& seen){
        if(seen.find(u) == seen.end()){
            seen.insert(u);
            if(u == dest) return true;
            for(auto& v : graph[u]){
                if(dfs(v, dest, graph, seen)) return true; 
            }
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n+1);
        
        set<int>seen;
        for(auto& edge : edges){
            seen.clear();
            if(!graph[edge[0]].empty() && !graph[edge[1]].empty() &&
              dfs(edge[0], edge[1], graph, seen)){
                return edge;
            }
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return {-1, -1};
    }
};