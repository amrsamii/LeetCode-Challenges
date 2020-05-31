class Solution {
public:
    
    bool BFS(vector<vector<int>>& graph,vector<bool>& vis,int N, int node) {
        queue<pair<int,int>> q;
        vector<int> zeroOneColor(N,-1);  
        
        q.push({node,1});
        vis[node] = 1;
        zeroOneColor[node] = 0;
        
        while(!q.empty()) {
            pair<int,int> p = q.front(); q.pop();
            
            for(auto child : graph[p.first]) {
                if(!vis[child]) {
                    vis[child] = 1;
                    zeroOneColor[child] = p.second;
		    // push alternate color
                    q.push({child,!p.second}); // or q.push({child, 1 - p.second}); just don't use ~p.second because ~1 is -2 not 0
                    
                }else {
                    if (zeroOneColor[child] != p.second)
                        return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<bool> vis(N,0);
        vector<vector<int>> graph(N);
        bool ans = 1;
        
        for (auto dislike : dislikes) {
            graph[dislike[0] - 1].push_back(dislike[1] - 1);
            graph[dislike[1] - 1].push_back(dislike[0] - 1);
        }
        
        for (int i = 0; i < N; i++) if(!vis[i]) {
            if(!BFS(graph,vis,N,i))
                return false;
        }
        return true;
    }
};
