class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < points.size(); i++)
            pq.push({-(points[i][0] * points[i][0] + points[i][1] * points[i][1]), i});

        vector<vector<int>> ans(K);
        for (int i = 0; i < K; i++) {
            ans[i] = points[pq.top().second];
            pq.pop();
        }
        
        return ans;
    }
};
