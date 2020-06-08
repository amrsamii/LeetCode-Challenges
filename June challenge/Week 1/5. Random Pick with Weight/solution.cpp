class Solution {
public:
    vector<int> w_sum;
    
    Solution(vector<int>& w) {
        w_sum = vector<int>(w.size());
        
	// cumulate sum of w in w_sum 
        for (int i=0;i<w.size();i++)
            w_sum[i] += i == 0? w[i] : w[i] + w_sum[i-1];
    }
    
    int pickIndex() {
	// generate rarndom number in range [0,sum of w[])
        int randomNumber = rand() % w_sum[w_sum.size() - 1];
        
        int low = 0, high = w_sum.size() - 1;
        
	// find the index of first number greater than randomNumber (upper bound)
        while (low < high) {
            int mid = low + (high - low)/2;
            
            if (w_sum[mid] <= randomNumber)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
