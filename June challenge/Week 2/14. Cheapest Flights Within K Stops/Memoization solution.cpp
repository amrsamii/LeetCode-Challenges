class Solution {
public:
    const int OO = 1e9;
    vector<vector<pair<int,int>>> graph;
    
    int minCost(int node, int dst, vector<vector<int>>& mem, int k) {
        
        if (node == dst && k >= 0) {
            return 0;
        }
        
        if (k <= 0)
            return OO;
        
     
        int &ret = mem[node][k];
        
        if (ret != -1)
            return ret;
        
        ret = OO;
        
        
        for (auto child : graph[node]) {
            ret = min(ret, child.second + minCost(child.first, dst, mem, k-1));
        }
        return ret;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        graph = vector<vector<pair<int,int>>>(n);
        
        for(auto edge : flights) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
        }
        vector<vector<int>> mem(graph.size(), vector<int>(graph.size()+1, -1));
        
        int ans = minCost(src, dst, mem, K+1);
        return ans == OO ? -1 : ans;
    }
};
