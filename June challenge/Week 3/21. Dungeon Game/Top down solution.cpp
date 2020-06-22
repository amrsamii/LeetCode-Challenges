class Solution {
public:
    int n, m;
    
    int minHealth(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>>& mem) {    
        // if reached princess, just return the min health you need to stay alive in its cell
        if (i == n - 1 && j == m - 1) 
            return max(1, -dungeon[i][j] + 1);
        
        int &ret = mem[i][j];
        
        if (ret != -1)
            return ret;
        
        ret = 1e7;
            
        // try right if you aren't on last column
        if (j < m - 1) {
            // get the min health from right and subtract from it the current cell
            int right = minHealth(i, j + 1, dungeon, mem) - dungeon[i][j];
            // if the subtraction is -ve or 0, this means you need only 1 hp, because dungeon[i][j] is greater
            // than min health of right, and your health cannot be 0, so make it 1. in case of 0, the two are equal so only
            // 1 is enough
            if (right <= 0)
                right = 1;
            ret = min(ret, right);
        }
        
        // try bottom
        if (i < n - 1) {
            int bottom = minHealth(i + 1, j, dungeon, mem) - dungeon[i][j];
            if (bottom <= 0)
                bottom = 1;
            // if both bottom and right are +ve, take the min of them
            ret = min(ret, bottom);
        }
        
        return ret;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();
        
        vector<vector<int>> mem(n, vector<int>(m, -1));
        
        return minHealth(0, 0, dungeon, mem);
    }
};
