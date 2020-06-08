// Time complexity: O(n^3)
// Space complexity: O(n^3)
class Solution {
public:
    const int OO = 1e6;
    int n;
    vector<vector<int>> arr;
    int mem[109][109][109];
    
    int minCost(int i,int a, int b) {
        if (i == n) {
            // done
            if (a == b && a + a == n)
                return 0;
            // invalid case
            return OO;
        }
        int &ret = mem[i][a][b];
        
        if (ret != -1)
            return ret;
        
        ret = OO;
        
        // go to city A IFF number of a is smaller than half of n, otherwise, it is invalid case, don't waste time in it
        if (2 * a < n)
            ret = min(ret, arr[i][0] + minCost(i+1, a+1, b));
        
        // go to city B IFF number of b is smaller than half of n, otherwise, it is invalid case, don't waste time in it
        if (2 * b < n)
        ret = min(ret, arr[i][1] + minCost(i+1, a, b+1));
        
        return ret;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        n = costs.size();
        arr = costs;
        
        memset(mem,-1,sizeof mem);
        
        return minCost(0,0,0);
    }
};
