class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>res(nums.size());
        int k = nums.size()-1;
        int i = 0;
        int j = nums.size()-1;

        while(i<=j){
            int n1 = abs(nums[i]);
            int n2 = abs(nums[j]);
            int num = 0;
            if(n1>n2){
                num = n1*n1;
                i++;
            }else{
                num = n2*n2;
                j--;
            }
            res[k--] = num;
        }
        
        return res;
    }
};