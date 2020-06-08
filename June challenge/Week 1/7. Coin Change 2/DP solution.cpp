class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        
	// if you have amount 0 and no coins, there is only one way to change coin, that is, without any coins, so don't forget to start from 0
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i-1][j];
                
                if (j - coins[i-1] >= 0)
                    dp[i][j] += dp[i][j - coins[i-1]];
            }
        }
        
        return dp[n][amount];
    }
};
