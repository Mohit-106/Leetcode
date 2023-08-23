class Solution {
public:
    
    bool bfs(vector<vector<char>>&b,string &s,int idx, vector<vector<int>>&vis,int i, int j){

        if(i<0 || j<0 || i==b.size() || j==b[0].size() || vis[i][j]==1 || s[idx]!=b[i][j]){
            return false;
        }

        if(idx == s.size()-1){
            return true;
        }

        vis[i][j]=1;

        int ans =  bfs(b,s,idx+1,vis,i+1,j) || bfs(b,s,idx+1,vis,i,j+1) || bfs(b,s,idx+1,vis,i-1,j) || bfs(b,s,idx+1,vis,i,j-1);

        vis[i][j] = 0;
        return ans;

    }


    bool exist(vector<vector<char>>& b, string s) {

        int n = b.size();
        int m = b[0].size();
        int ch = s[0];
        vector<vector<int>>vis(n,vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(b[i][j] == ch && bfs(b,s,0,vis,i,j)){
                    return true;
                }
            }
        }

        return false;
        
    }
};