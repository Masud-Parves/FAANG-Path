class Solution {
private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& cache){
        if(node == NULL) return NULL;
        
        if(cache.find(node) != cache.end()){
            return cache[node];
        }   

        Node* currNode = new Node(node->val, vector<Node*>{});
        cache[node] = currNode; 
        
        for(auto* child : node->neighbors){
            cache[node]->neighbors.push_back(dfs(child, cache));
        }
        return currNode;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        unordered_map<Node*, Node*> cache;
        
        Node* root = new Node(node->val, vector<Node*>{});
        cache[node] = dfs(node, cache);
        
        return cache[node];
    }
};