class Solution {
private:
    void bfs(int src, vector<bool>&visited, vector<vector<int>>&graph){
        queue<int>Q;
        Q.push(src);
        visited[src] = true;
        
        while(!Q.empty()){
            int uNode = Q.front();
            Q.pop();
            
            for(auto vNode : graph[uNode]){
                if(visited[vNode] == false){
                    Q.push(vNode);
                    visited[vNode] = true;
                }
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n, vector<int>(n));
        
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool>visited(n, false);
        int result = 0;
        for(int i=0; i<n ; i++){
            if(visited[i] == false){
                result ++;
                bfs(i, visited, graph);
            }
        }
        return result;
    }
};