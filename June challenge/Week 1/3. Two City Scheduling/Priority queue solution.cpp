class Solution {
public:
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
	    int n = costs.size();
        
        priority_queue<pair<int,int>> pq;
        
        for (int i = 0; i < n; i++)
            pq.push({costs[i][1] - costs[i][0], i});
        
        int ans = 0;
        int i;
        for (i = 0; 2 * i < n; i++) {
            ans += costs[pq.top().second][0];
            pq.pop();
        }
        
        for (; i < n; i++) {
            ans += costs[pq.top().second][1];
            pq.pop();
        }
        
        return ans;
    }
};
