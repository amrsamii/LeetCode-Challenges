class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<pair<bool,int>> people(N+1,{true,0});
        
        for(auto i : trust) {
            people[i[1]].second++;
            people[i[0]].first = false;
        }
        
        for(int i = 1; i <= N; i++) {
            if(people[i].first && people[i].second == N-1)
                return i;
        }
        return -1;
        
    }
};