// Time complexity: O(amount*N)
// Space complexity: O(amount*N)
class Solution {
public:
    vector<int> arr;
    int n;
    
    vector<vector<int>> mem;
    
    int countWays(int i, int amount) {
	// any moment you have 0 amount, this means you were able to change the amount with some coins, return 1 meaning that this a possible way
	// to change the coin
        if (amount == 0)
            return 1;
        
	// any moment you have -ve amount, you have exceeded it, return 0 to invalidate this path
	// also if you finished the array and didn't pass the above condition, this means you still have some amount and you couldn't change for
	// coins, return also 0
        if (amount < 0 || i == n)
            return 0;
        
        int &ret = mem[i][amount];
        
        if (ret != -1)
            return ret;
        
        
       return ret = countWays(i, amount-arr[i]) + countWays(i+1, amount); // take it(and try to take it again), and leave it
    }
    
    int change(int amount, vector<int>& coins) {
        arr = coins;
        n = coins.size();
        
        mem = vector<vector<int>>(n, vector<int>(amount + 1, -1));
        
        return countWays(0,amount);
    }
};
