class Solution {
public:
    int maxArea(vector<int>& h){

        int i = 0;
        int j = h.size()-1;
        int ans = 0;
        while(i<j){

            int ht = min(h[i],h[j]);
            int wt = j-i;
            int vol = ht*wt;
            ans = max(ans,vol);

            if(h[i]>h[j]){
                j--;
            }else if(h[i]<h[j]){
                i++;
            }else{
                i++;
            }

        }

        return ans;
        
        
    }
};