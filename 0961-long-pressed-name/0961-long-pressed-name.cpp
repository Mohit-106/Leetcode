class Solution {
public:
    bool isLongPressedName(string name, string typed) {


        int n = name.size();
        int m = typed.size();

        if(n>m){
            return false;
        }

        int i=0;
        int j=0;

        while(i<n && j<m){
            if(name[i]!=typed[j]) return false;
            int num = name[i];
            i++;
            int c1=1;
            while(i<n && num==name[i]){
                c1++;
                i++;
            }

            num = typed[j];
            j++;
            int c2=1;
            while(j<m && num==typed[j]){
                c2++;
                j++;
            }

            if(c1>c2){
                return false;
            }
        }

        if(j<m || i<n){
            return false;
        }

        return true;
        
    }
};