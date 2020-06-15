class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
	// high is n in case of [1,3,5,6], 7 we need to return 4 which is n, so high must start with n
        int low = 0, high = nums.size();
        
        while (low < high) {
            int mid = low + (high - low)/2;
            
            if(nums[mid] >= target)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
