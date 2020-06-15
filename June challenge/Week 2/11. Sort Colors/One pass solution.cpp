class Solution {
public:
    void sortColors(vector<int>& nums) {
        size_t n = nums.size();
        int low = 0, high = n-1, mid = 0;
        
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }else if (nums[mid] == 2) {
                swap(nums[mid],nums[high]);
                high--;
            }else {
                mid++;
            }
        }
    }
};
