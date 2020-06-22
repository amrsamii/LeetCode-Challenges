class Solution {
public:
    int n, m;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    
    bool valid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    bool validGroup (int i, int j, vector<vector<char>>& board, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        
        bool ret = true;
        
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            ret = false;
        
        for (int k = 0; k < 4; k++) {
            int r = i + dr[k];
            int c = j + dc[k];
            
            if (valid(r, c) && !vis[r][c] && board[r][c] != 'X')
                if (!validGroup(r, c, board, vis))
                    ret = false;
        }
        return ret;
    }
    
    void change(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& vis2) {
        vis2[i][j] = true;
        board[i][j] = 'X';
        
        for (int k = 0; k < 4; k++) {
            int r = i + dr[k];
            int c = j + dc[k];
            
            if (valid(r, c) && !vis2[r][c] && board[r][c] != 'X')
                change(r, c, board, vis2);
        }
        
        
    }
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        
        n = board.size();
        m = board[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m));
        vector<vector<bool>> vis2(n, vector<bool>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    if (validGroup(i, j, board, vis))
                        change(i, j, board, vis2);
                }
            }
        }
    }
};
