class Solution {
public:
    
    int minDistance(string word1, string word2) {
        int sz1 = word1.length();
        int sz2 = word2.length();
	// Create a table to store results of subproblems
        vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1));

	// If second string is empty, only option is to
        // remove all characters of second string 
        for (int i = 1;i<=sz1;i++)
            dp[i][0] = i;

	// If first string is empty, only option is to
	// insert all characters of second string
        for (int j = 1;j<=sz2;j++)
            dp[0][j] = j;

	// Fill the table using bottom up approach
        for (int i = 1; i <= sz1; i++) {
            for (int j = 1; j <= sz2; j++) {
		// If same character in both strings, no new operation will be made, so copy the value from previous position
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
		// If they are different, consider all possibilities and store the min + 1
                else
                    dp[i][j] = 1 + min({dp[i - 1][j - 1], // Replace
                                        dp[i][j - 1], // Insert
                                        dp[i - 1][j]}); // Remove
            }
        }
        return dp[sz1][sz2];
    }
};
