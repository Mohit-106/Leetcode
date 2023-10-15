class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // find the potential row first

        int n = matrix.size();
        int m = matrix[0].size();

        int lo = 0;
        int hi = n-1;
        int prow=-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(matrix[mid][0]<=target && matrix[mid][m-1]>=target){
                prow = mid;
                break;
            }else if(target > matrix[mid][m-1]){
                lo = mid+1;
            }else if(target < matrix[mid][0]){
                hi=mid-1;
            }
        }
        cout<<prow<<endl;
        if(prow == -1){
            return false;
        }

        lo = 0;
        hi = m-1;

        while(lo<=hi){
            int mid = (lo+hi)/2;

            if(target==matrix[prow][mid]){
                return true;
            }else if(target<matrix[prow][mid]){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        return false;
        
    }
};