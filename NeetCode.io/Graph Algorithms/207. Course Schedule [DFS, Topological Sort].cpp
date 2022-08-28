class Solution {
private:
	bool dfs(int node, vector<vector<int>>& graph, vector<bool>&done, vector<bool>todo){
        if(todo[node]) return false;
        if(done[node]) return true;
        
        todo[node] = done[node] = true;
        
        for(auto v : graph[node]){
            if(!dfs(v, graph, done, todo)) return false;
        }
        todo[node] = false;
        return true;
        
    }
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        for(auto prerequisite : prerequisites){
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }
        
        vector<bool>todo(n, false);
        vector<bool>done(n, false);
        
        for(int i=0; i<n ; i++){
            if(!done[i] && !dfs(i, graph, done, todo)){
                return false;
            }
        }
        return true;
    }
};