class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int firstLen = s1.length();
        vector<int> firstChar(26,0);
        vector<int> secondChar(26,0);
        
        for(char c : s1)
            firstChar[c-'a']++;
        
        for(int i = 0; i < s2.length(); i++) {
            
            secondChar[s2[i]-'a']++;
            
            if(firstChar == secondChar)
                return true;
            
            if( (i+1) >= firstLen)
                secondChar[s2[i+1-firstLen]-'a']--;
        }
        
        return false;
    }
};
