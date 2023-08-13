class Solution {
public:
    string removeDuplicateLetters(string s) {

        unordered_map<char,int>mp;
        for(char &ch : s){
            mp[ch]++;
        }
        unordered_set<char>alreadythere;
        stack<char>st;
        st.push(s[0]);
        alreadythere.insert(s[0]);
        mp[s[0]]--;

        for(int i=1; i<s.size();i++){
            char ch = s[i];
            if(alreadythere.find(ch)==alreadythere.end()){
                while(st.size()>0 && ch<=st.top() && mp[st.top()]>0){
                cout<<st.top()<<" "<<ch<<endl;
                alreadythere.erase(st.top());
                st.pop();
               }
               alreadythere.insert(ch);
               st.push(ch);
            }
            mp[ch]--;
        }

        string ans="";
        while(st.size()>0){
            ans = st.top()+ans;
            st.pop();
        }
        return ans;

    }
};