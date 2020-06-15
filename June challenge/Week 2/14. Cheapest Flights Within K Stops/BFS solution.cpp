class Solution {
public:
    vector<vector<pair<int,int>>> graph;
    
    int bfs(int src, int dst, int k) {
        queue<pair<int,int>> q;
        int minn = 1e9;
        
        q.push({src,0});
        
        int depth = 0, sz = 1;
        for (; !q.empty(); depth++, sz = q.size()) {
            while (sz--) {
                pair<int,int> cur = q.front(); q.pop();
                
                if (cur.first == dst)
                    minn = min(minn, cur.second);
                
                else {
                    for (auto child : graph[cur.first]) {
			// check if depth doesn't equal k + 1 yet, if so, then we can traverse another node, check also if cost is less than min
                        if (depth - 1 < k && child.second + cur.second < minn)
                            q.push({child.first, child.second + cur.second});
                    }
                }
            }
        }
        
        if (minn == 1e9)
            return -1;
        return minn;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        graph = vector<vector<pair<int,int>>>(n);
        
        for(auto edge : flights) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
        }
        
        return bfs(src, dst, K);
    }
};
