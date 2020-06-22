class Solution {
public:
    int n, m;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    
    bool valid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    void excludeBoundary (int i, int j, vector<vector<char>>& board, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        
        for (int k = 0; k < 4; k++) {
            int r = i + dr[k];
            int c = j + dc[k];
            
            if (valid(r, c) && !vis[r][c] && board[r][c] != 'X')
                excludeBoundary(r, c, board, vis);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        
        n = board.size();
        m = board[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m));

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0])
                excludeBoundary(i, 0, board, vis);
            
            
            if (board[i][m-1] == 'O' && !vis[i][m-1])
                excludeBoundary(i, m-1, board, vis);
        }
        
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !vis[0][j])
                excludeBoundary(0, j, board, vis);
            
            
            if (board[n-1][j] == 'O' && !vis[n-1][j])
                excludeBoundary(n-1, j, board, vis);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                   board[i][j] = 'X';
                }
            }
        }
    }
};
