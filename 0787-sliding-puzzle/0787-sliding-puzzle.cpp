class Solution {
public:

   int getZerosIndex(string &s){
       for(int i=0; i<s.size(); i++){
           if(s[i]=='0'){
               return i;
           }
       }
       return -1;
   }

   void Swap(string &s, int i, int j){
       char ch = s[i];
       s[i] = s[j];
       s[j] = ch;
   }



    int slidingPuzzle(vector<vector<int>>& board) {

        vector<vector<int>>dir = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        string dst = "123450";
        unordered_set<string>s;

        string src="";
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                src+=to_string(board[i][j]);
            }
        }

        queue<pair<string,int>>q;
        q.push(make_pair(src,0));

        while(q.size()>0){

            pair<string,int> front = q.front();
            q.pop();

            if(s.find(front.first)!=s.end()){
                continue;
            }

            s.insert(front.first);


            if(front.first == dst){
                return front.second;
            } 

            // get zero index 
            int idx = getZerosIndex(front.first);

            // swap with all possible indexes and add to queue

            vector<int>&v = dir[idx];
            for(int i=0; i<v.size(); i++){
                string pdst = front.first;
                Swap(pdst,idx,v[i]);
                if(s.find(pdst)==s.end()){
                    q.push(make_pair(pdst,front.second+1));
                }
            }
        }

        return -1;



        
    }
};