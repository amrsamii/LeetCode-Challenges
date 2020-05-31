class Solution {
public:
    int dp[500][500];
    int aSize, bSize;
    
    int  lcs(vector<int>& A, vector<int>& B, int i, int j) {
        if(i >= aSize || j >= bSize)
            return 0;
        
        int& ret = dp[i][j];
        
        if(ret != -1)
            return ret;
        
        if(A[i] == B[j])
            return ret = 1 + lcs(A,B,i+1,j+1);
        
        else
            return ret = max(lcs(A,B,i+1,j),lcs(A,B,i,j+1));
    }
    
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        aSize = A.size();
        bSize = B.size();
        memset(dp,-1, sizeof dp);
        
        return lcs(A,B,0,0);
    }
};
