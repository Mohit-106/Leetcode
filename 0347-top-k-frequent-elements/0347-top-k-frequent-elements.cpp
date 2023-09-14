class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(auto &val : mp){
            //cout<<val.first<<" "<<val.second<<endl;
            if(pq.size()<k){
                pq.push(make_pair(val.second,val.first));
            }else{
                if(val.second > pq.top().first){
                    pq.pop();
                    pq.push(make_pair(val.second,val.first));
                }
            }
        }

        vector<int>ans;

        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};