class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, blue = 0, white = 0;
        
        for(auto color : nums) {
            switch (color) {
                case 0:
                    red++;
                    break;
                case 1:
                    white++;
                    break;
                case 2:
                    blue++;
                    break;
            }
        }
        
        int i = 0;
        
        for(; red > 0; i++, red--)
            nums[i] = 0;
        
        for(; white > 0; i++, white--)
            nums[i] = 1;
        
        for(; blue > 0; i++, blue--)
            nums[i] = 2;
    }
};
