class Solution {
public:
    bool isLongPressedName(string name, string typed) {

        if(name.size() > typed.size()) return false;

        int j = 0;
        int i = 0;
        while(i<name.size()){

            if(name[i]!=typed[j]) return false;
            int l = i+1;

            int cnt=0;
            while(l<name.size() && name[i]==name[l]){
                l++;
                cnt++;
            }

            int k = j+1;
            int cnt2=0;
            while(k<typed.size() && typed[k]==typed[j]){
                k++;
                cnt2++;
            }
            if(cnt2<cnt) return false;
            j = k;
            i = l;


        }

          
        if(j<typed.size()) return false;

        return true;



    }
};