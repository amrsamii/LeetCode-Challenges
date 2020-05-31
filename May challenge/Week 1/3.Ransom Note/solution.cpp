class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::ios_base::sync_with_stdio(false);
        
        vector<int> charsCount(26,0);
        for(char i : magazine)
            charsCount[i-'a']++;
        
        for(char i : ransomNote){
            if(--charsCount[i-'a'] < 0)
                return false;
        }
        return true;
    }
};
