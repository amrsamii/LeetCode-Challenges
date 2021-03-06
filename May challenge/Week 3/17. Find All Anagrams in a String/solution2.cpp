class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sv(26, 0);
        vector<int> pv(26, 0);
        vector<int> res;
        
        for (auto c : p)
            pv[c - 'a']++;
        
        for (int i = 0; i < s.size(); i++) {
            sv[s[i] - 'a']++;
            if (i >= p.size())
                sv[s[i - p.size()] - 'a']--;
            if (sv == pv)
                res.push_back(i - p.size() + 1);
        }
        
        return res;
    }
};
