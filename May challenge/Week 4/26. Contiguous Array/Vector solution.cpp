// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int cnt = 0, maxx = 0;
        int sz = nums.size();
        
        vector<int> mem(2*sz+1,-2);
        mem[sz] = -1;
        
        for (int i = 0; i < sz;i++) {
            cnt += (nums[i])? 1 : -1;
            if(mem[cnt+sz] != -2) {
                maxx = max(maxx, i - mem[cnt+sz]);
            }else
                mem[cnt+sz] = i;
        }
        
        return maxx;
    }
};
