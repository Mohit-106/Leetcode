class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int tar) {

        if(root==NULL) return NULL;

        root->left = removeLeafNodes(root->left,tar);
        root->right = removeLeafNodes(root->right,tar);

        if(root->val == tar && root->left==NULL && root->right==NULL){
            return NULL;
        }

        return root;
        
    }
};