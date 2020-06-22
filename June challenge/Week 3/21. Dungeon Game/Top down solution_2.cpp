class Solution {
public:
    int n, m;
    
    int minHealth(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>>& mem) {    
        if (i == n - 1 && j == m - 1) 
            return max(1, -dungeon[i][j] + 1);
        
        if (i == n || j == m)
            return 1e7;
        
        int &ret = mem[i][j];
        
        if (ret != -1)
            return ret;
        
        return ret = max(1, min(minHealth(i, j + 1, dungeon, mem) - dungeon[i][j],
                        minHealth(i + 1, j, dungeon, mem) - dungeon[i][j]));
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();
        
        vector<vector<int>> mem(n, vector<int>(m, -1));
        
        return minHealth(0, 0, dungeon, mem);
    }
};
