class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int cnt[26] = {0};
        // count how many times a character appears
        for(char c : s){
            cnt[c-'a'] ++;
        }
        
	// loop again to preserve order and also get the index
        for(int i=0;i<s.length();i++){
            if(cnt[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
