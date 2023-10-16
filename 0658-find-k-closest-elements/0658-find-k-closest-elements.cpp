class Solution {
public:

   class Props{
       public:
       int diff;
       int val;

       Props(int diff, int val){
           this->diff = diff;
           this->val = val;
       }
   };

    class comp{
        public:
        bool operator()(Props* a, Props * b){
            return a->diff < b->diff;
        }
    };

    vector<int> findClosestElements(vector<int>& nums, int k, int x) {


        int n = nums.size();
        priority_queue<Props*,vector<Props*>,comp>pq;

        // for(int i=0; i<n; i++){
        //     pq.push(new Props(abs(nums[i]-x),nums[i]));
        // }

        for(int i=0; i<n; i++){
            int diff = abs(nums[i]-x);
            if(pq.size()<k){
                pq.push(new Props(diff,nums[i]));
            }else{
               
                if(diff < pq.top()->diff){
                    pq.pop();
                    pq.push(new Props(diff,nums[i]));
                }else if(diff == pq.top()->diff && pq.top()->val > nums[i]){
                    pq.pop();
                    pq.push(new Props(diff,nums[i]));
                }
            }
        }
        vector<int>res;
        while(pq.size()>0){
            res.push_back(pq.top()->val);
            //cout<<pq.top()->diff<<" -- "<<pq.top()->val<<endl;
            pq.pop();
        }
        sort(res.begin(),res.end());
        return res;

        
    }
};