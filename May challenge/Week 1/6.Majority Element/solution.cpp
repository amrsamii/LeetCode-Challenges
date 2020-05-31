class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = 0, counter = 0;
        for(int i = 0; i < nums.size(); i++){
            if(counter == 0)
                num = nums[i];
            counter += num == nums[i] ? 1 : -1;
        }
        return num;
    }
};
