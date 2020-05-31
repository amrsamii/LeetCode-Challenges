class Solution {
public:
    int sz;
    
    bool valid(int i) {
        return i < sz && i >= 0;
    }
    int singleNonDuplicate(vector<int>& nums) {
        sz = nums.size();
        int low = 0;
        int high = sz-1;
        int mid;
        
        while(low <= high) {
            mid = low + (high - low)/2;
            
            if(valid(mid-1) && nums[mid] == nums[mid - 1]) {
                
                if((sz-mid-1) % 2 == 0 && (mid - 1) % 2 != 0)
                    high = mid - 2;
                
                else
                    low = mid + 1;
                
            }else if(valid(mid+1) && nums[mid] == nums[mid +1]) {
                
                if((sz-mid-2) % 2 == 0 && mid % 2 != 0)
                    high = mid - 1;
                
                else
                    low = mid + 2;
                
            }else
                return nums[mid];
        }
                
        return -1;
        
    }
};
