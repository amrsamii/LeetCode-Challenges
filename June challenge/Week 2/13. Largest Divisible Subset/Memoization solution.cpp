class Solution {
public:
    int n;
    
    int maxSubset(int i, vector<int>& nums, vector<vector<int>>& mem, int prev) {
        if (i == n) {
            return 0;
        }
        
        int &ret = mem[i][prev];
        
        if(ret != -1)
            return ret;
        
        ret = maxSubset(i+1, nums, mem, prev);
        
        if (prev == n || nums[i] % nums[prev] == 0)
            ret = max(ret, 1 + maxSubset(i+1, nums, mem, i));
        
        return ret;
    }
    
    vector<int> output;
    
    void buildOutput(int i, vector<int>& nums, vector<vector<int>>& mem, int prev) {
        if (i == n) {
            return;
        }
        
        int choice1 = maxSubset(i+1, nums, mem, prev);
        int choice2 = 0;
        
        if (prev == n || nums[i] % nums[prev] == 0)
            choice2 =  1 + maxSubset(i+1, nums, mem, i);
        
        int optimal = maxSubset(i, nums, mem, prev);
        
        if (optimal == choice1) {
            buildOutput(i+1, nums, mem, prev);
        }else {
            output.push_back(nums[i]);
            buildOutput(i+1, nums, mem, i);
        }
        
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> mem(n,vector<int>(n + 1,-1));
        
        buildOutput(0, nums, mem, n);
        return output;
    }
};
