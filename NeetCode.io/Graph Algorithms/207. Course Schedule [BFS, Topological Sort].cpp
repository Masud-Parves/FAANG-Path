class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        if(n == 1) return true;
        
        vector < int > graph[n];
        int inorder[n];
        memset(inorder, 0, sizeof(inorder));
        
        for(auto c : prerequisites){
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
            inorder[c[0]]++;
        }
        
        queue < int > Q;
        for(int i=0; i<n; i++){
            if(inorder[i] == 0) Q.push(i);
        }
        int numOfNode = 0;
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            
            numOfNode++;
            for(int i=0; i<graph[u].size(); i++){
                int v = graph[u][i];
                inorder[v]--;
                if(inorder[v] == 0) Q.push(v);
            }
        }
        return n==numOfNode ? true : false;
    }
};