/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    void solver(TreeNode * root, int &low, int &high){

        if(root==NULL){
            return;
        }
        
        if(root->val >= low && root->val <= high){
            solver(root->left,low,high);
            ans+=root->val;
            solver(root->right,low,high);
        }else if(root->val < low){
            solver(root->right,low,high);
        }else{
            solver(root->left,low,high);
        }

    }
    int rangeSumBST(TreeNode* root, int low, int high) {

        if(root==NULL) return 0;
        solver(root,low,high);
        return ans;
      
        
    }
};