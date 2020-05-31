class Solution {
public:
        
    string frequencySort(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int count[128] = {0};
        
        for(char c : s)
            count[c]++;
        
        vector<pair<int,char>> freq;
        
        for(int i=0;i<128;i++) {
            if(count[i])
                freq.emplace_back(count[i],i);
        }
        
        sort(freq.rbegin(),freq.rend());
        
        string ans;
        for(auto i : freq)
            ans.append(i.first,i.second);
        
        return ans;
    }
};
