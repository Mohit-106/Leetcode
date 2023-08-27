class Solution {
public:
    int search(vector<int>& nums, int key) {

        int l = 0;
        int h = nums.size()-1;

        while(l<=h){   
            int mid = (l+h)/2;
            // right half is sorted
            
            if(nums[mid]==key){
                return mid;
            }

            if(l==h){
                break;
            }
            
            if(nums[mid] < nums[h]){
                if(key>=nums[mid]&&key<=nums[h]){
                    l = mid+1;
                }else{
                    h=mid-1;
                }
            }
            //left half is sorted
            else if(nums[mid > nums[h]]){
                if(key<=nums[mid]&&key>=nums[l]){
                    h = mid-1;
                }else{
                    l=mid+1;
                }
            }


            
        }
        return -1;
        
    }
};