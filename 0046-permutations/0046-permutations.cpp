class Solution {
public:

   vector<vector<int>>res;

   void solver(vector<int>&nums,int n, int i, vector<int>&vis,vector<int>&v){


       if(i==n){
           res.push_back(v);
           return;
       }


       for(int j=0; j<n; j++){
           if(vis[j]==0){
               vis[j]=1;
               v.push_back(nums[j]);
               solver(nums,n,i+1,vis,v);
               vis[j]=0;
               v.pop_back();
            }
       }
   }

    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();
        vector<int>vis(n);
        vector<int>v;
        solver(nums,n,0,vis,v);
        return res;

        
    }
};