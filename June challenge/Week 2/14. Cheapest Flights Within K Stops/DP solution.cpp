class Solution {
public:
    const int OO = 1e9;
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> dp(n, vector<int>(K+2, OO));
        
        
        for (int i = 0; i<= K+1; i++) {
            dp[src][i] = 0;
        }
        
        for (int i = 1; i <= K + 1; i++) {
            for (auto& flight : flights) {
                    dp[flight[1]][i] = min(dp[flight[1]][i], flight[2] + dp[flight[0]][i-1]);
            }
        }
        
        return dp[dst][K+1] == OO ? -1 : dp[dst][K+1];
    }
};
