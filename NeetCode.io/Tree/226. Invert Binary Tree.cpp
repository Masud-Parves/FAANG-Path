class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()){
            TreeNode* node = stack.top();
            stack.pop();
            
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if(node->right != NULL){
                stack.push(node->right);
            }
            if(node->left != NULL){
                stack.push(node->left);
            }
        }

        return root;
    }
};