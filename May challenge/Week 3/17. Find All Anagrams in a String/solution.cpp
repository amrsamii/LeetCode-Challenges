class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int psize = p.length();
        int ssize = s.length();
        
        if(psize > ssize)
            return vector<int>();
        
        vector<int> ans;
        
        vector<int> cntp(26,0);
        vector<int> cntc(26,0);
        
        for(char c : p)
            cntp[c-'a']++;
        
        for(int i = 0; i < ssize ; i++) {
            
            cntc[s[i]-'a']++;
            
            if (cntc == cntp)
                ans.push_back(i - psize + 1);

            if ((i+1) >= psize)
              cntc[s[i - psize+1] - 'a'] --;
            
        }
        
        return ans;
    }
};
