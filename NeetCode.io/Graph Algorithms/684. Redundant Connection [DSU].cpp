class Union_Find{
public:
    Union_Find(int sz): root(sz), rank(sz){
        for(int i=0; i<sz; i++){
            rank[i] = 1;
            root[i] = i;
        }
    }
    
    int Find(int x){
        if(x == root[x]) return x;
        return root[x] = Find(root[x]);
    }
    
    void Union(int x, int y){
        int rootX = Find(x);
        int rootY = Find(y);
        
        if(rootX == rootY){
            // take the edge;
            ans = {x, y};
        } else {
            if(rank[rootX]<rank[rootY]){
                root[rootX] = rootY;
            } else if(rank[rootX]>rank[rootY]){
                root[rootY] = rootX;
            } else {
                root[rootX] = rootY;
                rank[rootY] += 1;
            }
        }
    }
    
    vector<int> getEdge(){
        return ans;
    }    
private:
    vector<int>root;
    vector<int>rank;
    vector<int>ans;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        
        Union_Find dsu(N+1);
        
        for(auto edge : edges){
            dsu.Union(edge[0], edge[1]);
        }
        return dsu.getEdge();
    }
};