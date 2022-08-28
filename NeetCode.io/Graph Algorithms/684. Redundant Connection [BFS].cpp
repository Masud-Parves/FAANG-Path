class Solution {
private:
    bool bfs(int src, int dest, vector<vector<int>>& graph, set<int>& seen){
        queue<int> Q;
        Q.push(src);
        seen.insert(src);
        
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            if(u == dest) return true;
            for(int v : graph[u]){
                if(seen.find(v) == seen.end()){
                    Q.push(v);
                    seen.insert(v);
                }
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
              bfs(edge[0], edge[1], graph, seen)){
                return edge;
            }
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return {-1, -1};
    }
};