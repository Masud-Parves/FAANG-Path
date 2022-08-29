class Solution {
private:
    TreeNode* construct(int start, int end, int& idx, vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& seen){
        if(start>end){
            return NULL;
        }
        
        int rootVal = preorder[idx];
        idx++;
        TreeNode* root = new TreeNode(rootVal);
        int getIdx = seen[rootVal];
        
        root->left = construct(start, getIdx-1, idx, preorder, inorder, seen);
        root->right = construct(getIdx+1, end, idx, preorder, inorder, seen);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) {
            return NULL;
        }
        int n = inorder.size();
        unordered_map<int, int>seen;
        for(int i=0; i<n; i++){
            seen[inorder[i]] = i;
        }
        int take = 0;
        TreeNode* root = construct(0, n-1, take, preorder, inorder, seen);
        return root;
    }
};