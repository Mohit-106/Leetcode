class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int ans=INT_MIN;
        int CurrSum=0;

        for(int i=0; i<n; i++){
            CurrSum+=nums[i];
            if(nums[i]>CurrSum){
                CurrSum=nums[i];
            }
            ans=max(ans,CurrSum);
        }

        return ans;
        
    }
};