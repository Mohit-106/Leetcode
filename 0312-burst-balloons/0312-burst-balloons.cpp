class Solution {
public:
    int maxCoins(vector<int>& nums) {

        int n = nums.size();
        int dp[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j]=0;
            }
        }

        for(int gap=0; gap<n; gap++){

            for(int i=0,j=gap; j<n; j++,i++){

                int val = INT_MIN;

                for(int k=i; k<=j; k++){

                    int l = k==i?0:dp[i][k-1];
                    int r = k==n-1?0:dp[k+1][j];

                    int cval = nums[k];
                    if(i>0) cval*=nums[i-1];
                    if(j<n-1) cval*=nums[j+1];
                    cval+=(l+r);
                    val = max(cval,val);
                }
                dp[i][j] = val;

            }

        }

        return dp[0][n-1];



        
    }
};