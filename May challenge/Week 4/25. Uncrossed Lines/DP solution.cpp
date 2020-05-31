class Solution {
public:
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int aSize = A.size();
        int bSize = B.size();
        
        vector<vector<int>> dp(aSize+1,vector<int>(bSize+1,0));
        
        for (int i = 1; i <= aSize; i++) {
            for (int j = 1; j <= bSize; j++) {
                
                if (A[i-1] == B[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[aSize][bSize];
    }
};
