class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();
        vector<int>v(n);
        v[n-1]=0;
        for(int i=n-2; i>=0; i--){
            v[i]=nums[i+1]+v[i+1];
        }

        int sum=0;
        for(int i=0; i<n;i++){
            if(i!=0)sum+=nums[i-1];
            if(sum==v[i]){
                return i;
            }
        }
        return -1;
        
    }
};