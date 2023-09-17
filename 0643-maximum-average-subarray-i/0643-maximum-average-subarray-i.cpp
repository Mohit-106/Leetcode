class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        
        int n = nums.size();
        double ans=INT_MIN;
        double sum=0;

        int i=-1;
        int j=-1;

        // acquire a k len window
        while(i<k-1){
            i++;
            sum+=nums[i];
        }
        ans=max(ans,sum/k);
        cout<<i<<" "<<sum<<endl;

        while(i<n-1 && j<n-1){

            j++;
            i++;
            sum-=nums[j];
            sum+=nums[i];
            ans=max(ans,sum/k);

        }


        return ans;

        
    }
};