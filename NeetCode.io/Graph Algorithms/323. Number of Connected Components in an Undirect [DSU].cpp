class Union_Find{
public:
    Union_Find(int sz) : rank(sz), root(sz){
        for(int i=0 ; i<sz ; i++){
            root[i] = i;
            rank[i] = 1;
        }
        count = sz;
    }
    
    int Find(int x){
        if(x == root[x]) return x;
        return root[x] = Find(root[x]);
    }
       
    void Union(int x, int y){
        int rootX = Find(x);
        int rootY = Find(y);
        if(rootX != rootY) {
            if(rank[rootX] > rank[rootY]){
                root[rootY] = rootX;
            } else if(rank[rootX] < rank[rootY]){
                root[rootX] = rootY;
            } else {
                root[rootX] = rootY;
                rank[rootY] += 1;
            }
            count--;
        } 
    }
    int numberOfComponent(){
        return count;
    }    
private:
    vector<int> root;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        Union_Find dsu(n);
        for(auto v: edges){
            dsu.Union(v[0], v[1]);
        }
        return dsu.numberOfComponent();
    }
};