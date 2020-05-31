class Solution {
public:
    int sz1;
    int sz2;
    string s1;
    string s2;
    int mem[1000][1000];
    
    int dp(int i, int j) {
        if (i == sz1 && j == sz2)
            return 0;

        int &ret = mem[i][j];

        if (ret != -1)
            return ret;

        if (i == sz1 && j < sz2)
            return ret = sz2 - j;

        if (i < sz1 && j == sz2)
            return ret = sz1 - i;

        if (s1[i] == s2[j])
            return ret = dp(i + 1, j + 1);
        else
            // Try Replace, Insert, and Remove
            return ret = 1 + min({dp(i + 1, j + 1), dp(i, j + 1), dp(i + 1, j)});
    }
    
    int minDistance(string word1, string word2) {
        s1 = word1;
        s2 = word2;
        sz1 = word1.length();
        sz2 = word2.length();
        memset(mem,-1,sizeof mem);
        
        return dp(0,0);
    }
};
