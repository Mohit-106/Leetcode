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
   string s="";
   void helper(TreeNode * root,vector<string>&ans){

       if(root==NULL) return;

       if(root->left==NULL && root->right==NULL){
           s+=(to_string(root->val));
           ans.push_back(s);
           if(abs(root->val)<=9){
           s.pop_back();
       }else if(abs(root->val)<=99){
           s.pop_back();
           s.pop_back();
       }else{
           s.pop_back();
           s.pop_back();
           s.pop_back();
       }

           if(root->val<0){
               s.pop_back();
           }
       }
       s+=(to_string(root->val)+"->");
       helper(root->left,ans);
       helper(root->right,ans);

       if(abs(root->val)<=9){
           s.pop_back();
       }else if(abs(root->val)<=99){
           s.pop_back();
           s.pop_back();
       }else{
           s.pop_back();
           s.pop_back();
           s.pop_back();
       }
       s.pop_back();
       s.pop_back();
       if(root->val<0){
           s.pop_back();
       }

   }

    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string>ans;
        if(root==NULL){
            return ans;   
        }

        helper(root,ans);
        return ans;

    }
};