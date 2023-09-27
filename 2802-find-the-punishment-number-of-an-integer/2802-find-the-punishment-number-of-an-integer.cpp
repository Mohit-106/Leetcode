class Solution {
public:
    
    bool valid(int n, string s, int sum){

        if(s=="") if(sum==n) return true;


        for(int i=1; i<=s.size();i++){
            int x = stoi(s.substr(0,i));
            if(valid(n, s.substr(i), sum+x)) return true;
        }
        return false;

    }
    
    int punishmentNumber(int n) {
        
        int ans=0;
        for(int i=1; i<=n; i++){
            string s = to_string(i*i);
            if(valid(i,s,0)) ans+=i*i;
           
        }
        return ans;
        
    }
};