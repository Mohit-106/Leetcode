class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int n  = nums.size();
        vector<int>flag(n,0);

        for(int i=0; i<n; i++){
            if(nums[i]%2==1){
                flag[i]=1;
            }
        }

        unordered_map<int,int>mp;
        int ans=0;
        int psum=0;
        for(int i=0; i<n; i++){
           psum+=flag[i];
           if(psum==k){
               ans++;
           }
           ans+=mp[psum-k];
           mp[psum]++;
        }
        return ans;
    }
};