class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& nums) {

        int n = nums.size();
        int sum =0;
        int i=0;
        int j=0;
        int res=INT_MAX;
        while(i<n && j<n){
            // bool f1=false;
            // bool f2=false;
            while(i<n && sum<tar){
                sum+=nums[i];
                i++;
               // f1=true;
            }
            if(sum>=tar) res=min(res,i-j);
            //cout<<res<<endl;
            while(j<i && sum>=tar){
                sum-=nums[j];
                j++;
                if(sum>=tar){
                    res=min(res,i-j);
                }
                //f2=true;
            }
            //cout<<res<<endl;
            // if(f1==false&&f2==false){
            //     break;
            // }
        }

        if(res==INT_MAX){
            return 0;
        }
        return res;
    }
};