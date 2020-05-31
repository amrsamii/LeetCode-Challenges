class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        vector<vector<int>> ans;
        for (auto a: A) {
            for (auto b: B) {
                
                 if(a[1] < b[0])
                    break;
                
                int c1 = max(a[0],b[0]);
                int c2 = min(a[1],b[1]);
                
                if(c1 <= c2)
                    ans.push_back({c1,c2});
            }
        }
        
        return ans;
    }
};
