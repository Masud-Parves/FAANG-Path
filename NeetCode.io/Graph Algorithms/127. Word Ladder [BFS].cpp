class Solution {
private:
    bool isMatch(string& w1, string& w2){
        int skip = 0;
        for(int i=0; i<w1.size(); i++){
            if(w1[i] != w2[i]){
                skip++;
            }
        }
        return skip == 1;
    }
    void buildGraph(unordered_map<string, int>& m, vector<vector<int>>& graph, vector<string>& words){
       for(int i=0; i<words.size(); i++){
           for(int j=i+1; j<words.size(); j++){
               if(isMatch(words[i], words[j])){
                   int u = m[words[i]], v = m[words[j]];
                   graph[u].push_back(v);
                   graph[v].push_back(u);
               }
           }
       }
       return;
   }
    
   	int bfs(int src, int dest, vector<vector<int>>& graph, int nd){
        vector<bool>visited(nd+1, false);
        vector<int>dis(nd+1, 0);
        queue<int>Q;
        
        Q.push(src);
        visited[src] = true;
        dis[src] = 1;
        
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            
            if(u == dest){
                return dis[u];
            }

            for(int v:graph[u]){
                if(visited[v] == false){
                    visited[v] = true;
                    dis[v] = dis[u] + 1;
                    Q.push(v);
                }
            }
        }
        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int>m;
        int nd = 0;
        
        for(auto& word : wordList){
            if(m.find(word) == m.end()){
                m[word] = nd++;   
            }
        }
        
        if(m.find(beginWord) == m.end()){
            m[beginWord] = nd++;
            wordList.push_back(beginWord);
        }
        if(m.find(endWord) == m.end()){
            return 0;
        }
        vector<vector<int>>graph(nd+1);
        buildGraph(m, graph, wordList);
        int ret = bfs(m[beginWord], m[endWord], graph, nd);
        
        return ret;
    }
};