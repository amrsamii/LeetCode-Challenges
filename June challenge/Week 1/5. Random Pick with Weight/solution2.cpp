class Solution {
public:
    vector<int> w_sum;
    
    Solution(vector<int>& w) {
        w_sum = vector<int>(w.size());
        
        for (int i=0;i<w.size();i++)
            w_sum[i] += i == 0? w[i] : w[i] + w_sum[i-1];
    }
    
    int pickIndex() {
        int randomNumber = rand() % w_sum[w_sum.size() - 1];
        
       return upper_bound(w_sum.begin(),w_sum.end(), randomNumber) - w_sum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
