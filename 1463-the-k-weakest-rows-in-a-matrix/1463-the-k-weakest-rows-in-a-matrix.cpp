class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        int n = mat.size();
        int m = mat[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        
        for(int i=0; i<n; i++){

            int val=0;
            for(int j=0; j<m;j++){
                if(mat[i][j]==1){
                    val++;
                }else{
                    break;
                }
            }

            if(pq.size()<k){
                pq.push(make_pair(val,i));
            }else{
                if(pq.top().first>val){
                    pq.pop();
                    pq.push(make_pair(val,i));
                }
            }
        }

        vector<int>ans(k);
        int j=k-1;
        while(pq.size()>0){
            ans[j--]=pq.top().second;
            pq.pop();
        }
        return ans;
        
    }
};