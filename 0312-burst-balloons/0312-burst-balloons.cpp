class Solution {
public:
    int maxCoins(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n));
        int m = dp.size();
        for(int gap=0; gap<m; gap++){
            for(int i=0,j=gap; j<m; i++,j++){
                int val = INT_MIN;
                for(int k=i; k<=j; k++){
                    int l = k==i?0:dp[i][k-1];
                    int r = k==j?0:dp[k+1][j];
                    int cval = nums[k];
                    if(i>0) cval*=(nums[i-1]);
                    if(j<n-1) cval*=(nums[j+1]);
                    cval+=(l+r);
                    val = max(val,cval);
                }
                dp[i][j] = val;
            }
        }
        return dp[0][m-1];
    }
};