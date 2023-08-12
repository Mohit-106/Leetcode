class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int s, int d) {


        unordered_map<int,vector<int>>mp;
        int n = routes.size();
        //int m = routes[0].size();

        for(int i=0; i<n;i++){
            for(int j=0; j<routes[i].size();j++){
                if(mp.find(routes[i][j])==mp.end()){
                    mp[routes[i][j]] = vector<int>();
                }
                mp[routes[i][j]].push_back(i);
            }
        }

        queue<pair<int,int>>q;
        q.push(make_pair(s,0));

        vector<int>visited(n);
        

        while(q.size()>0){

            pair<int,int> front = q.front();
            int busStop = front.first;
            int lvl =  front.second;
            q.pop();

            if(busStop == d){
                return lvl;
            }

            //buses from busStop
            vector<int> buses = mp[busStop];
            for(int & bus : buses){
                if(visited[bus]==0){
                    visited[bus] = 1;
                    for(int &stop : routes[bus]){
                        q.push(make_pair(stop,lvl+1));
                    }
                }
            }

        }

        return -1;


        
        
    }
};
