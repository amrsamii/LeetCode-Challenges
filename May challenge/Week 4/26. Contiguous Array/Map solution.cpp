class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> mem;
        int cnt = 0;
        int maxx = 0;
        
        mem[0] = -1;
        
        for(int i = 0,sz = nums.size(); i < sz ; i++) {
            cnt += nums[i] == 1? 1 : -1;
            
            if(mem.count(cnt) != 0) {
                if(i - mem[cnt] > maxx)
                    maxx = i - mem[cnt];
            }else {
                mem[cnt] = i;
            }
        }
        
        return maxx;
    }
};
