class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {        
        vector<int>ans;
        vector<int>graph[numCourses];
        vector<int>inDegree(numCourses, 0);

        for(auto pre : prerequisites){
            graph[pre[0]].push_back(pre[1]);
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        queue<int>Q;
        for(int i=0; i<numCourses ; i++){
            if(inDegree[i] == 0) Q.push(i);
        }
        
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            ans.push_back(u);
            for(int v:graph[u]){
                inDegree[v]--;
                if(inDegree[v] == 0) Q.push(v);
            }
        }
        return ans.size() == numCourses ? ans : vector<int>();
    }
};