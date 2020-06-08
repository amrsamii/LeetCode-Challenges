// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
	int n = costs.size();
        // sort by difference between a and b to make the difference max, hence you can definitely take cost of a in the first half
	// and since there will be always a solution, you can take cost of b in the second half
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] - a[0] > b[1] - b[0];
        });
        
        int ans = 0;
        int i;
	// loop till the half, take cost of a in the first half (i) and take cost of b in second half (i+n/2)
        for (i = 0; 2 * i < n; i++)
            ans += costs[i][0] + costs[i+n/2][1];    
        
        return ans;
    }
};
