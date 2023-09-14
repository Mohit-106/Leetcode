class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& s) {

        int n = pos.size();
        vector<pair<int,int>>v;
        for(int i=0; i<n; i++){
            v.push_back(make_pair(pos[i],s[i]));
        }
        sort(v.begin(),v.end());

        double time=0;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            //cout<<v[i].first<<" "<<v[i].second<<endl;
            double p =  target-v[i].first;
            double sp = v[i].second;
            double ctime = (p/sp);
            //cout<<time<<" "<<ctime<<endl;
            if(time<ctime){
                time = ctime;
                ans++;
            }
        }
        return ans;


        
    }
};