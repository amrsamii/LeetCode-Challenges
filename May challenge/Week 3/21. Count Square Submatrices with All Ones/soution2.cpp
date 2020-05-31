class Solution {
public:
    int sumRange(int i,int j,int k, int l,vector<vector<int>>& S) {
        //cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
        if(!i && !j)
            return S[k][l];
        
        if(!i)
            return S[k][l] - S[k][j-1];
        
        if(!j)
            return S[k][l] - S[i-1][l];
        
        return S[k][l] - S[i-1][l] - S[k][j-1] + S[i-1][j-1];
    }
        
    int countSquares(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int n = matrix.size();    // rows
        int m = matrix[0].size(); // columns
        int maxSubSquare = min(n,m);
        long long ans = 0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                matrix[i][j] = (j==0)? matrix[i][j] : matrix[i][j] + matrix[i][j-1];
        
        for(int j=0;j<m;j++)
            for(int i=0;i<n;i++)
                matrix[i][j] = (i==0)? matrix[i][j] : matrix[i][j] + matrix[i-1][j];
        
        
        for(int startRow=0; startRow<n; startRow++) {
            
            for(int startColumn=0; startColumn<m; startColumn++) {
                
                for(int k=0; k<maxSubSquare; k++) {
                    
                    int endRow = startRow + k;
                    int endColumn = startColumn + k;
                    
                    if(endRow < n && endColumn < m &&
                       sumRange(startRow, startColumn, endRow, endColumn,matrix) == 
                       (endRow-startRow+1)*(endColumn-startColumn+1) )
                            ans++;
                }
            }
        }
        return ans;
    }
};
