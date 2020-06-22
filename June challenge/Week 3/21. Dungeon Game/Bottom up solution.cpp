class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        
        for (int i = n; i >= 1; i--) {
            for (int j = m; j >= 1; j--) {
                if (i == n && j == m)
                    dp[i][j] = max(1, -dungeon[i-1][j-1] + 1);
                
                else if (i == n)
                    dp[i][j] = max(1, dp[i][j+1] - dungeon[i-1][j-1]);
                
                else if (j == m)
                     dp[i][j] = max(1, dp[i+1][j] - dungeon[i-1][j-1]);
                
                 else
                    dp[i][j] = max(1, min(dp[i+1][j] - dungeon[i-1][j-1],
                                        dp[i][j+1] - dungeon[i-1][j-1]));
            }
        }
        return dp[1][1];
    }
};
