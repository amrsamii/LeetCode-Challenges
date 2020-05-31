class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
        long long currentTwoDouble = 1;
        
        if (num == 0)
            return {0};
        
        ans[1] = 1;
        
        for (int i = 2; i <= num; i++) {
            if (i == currentTwoDouble * 2) {
                ans[i] = 1;
                currentTwoDouble*= 2;
            }
            
            ans[i] = 1 + ans[i - currentTwoDouble];
        }
        return ans;
    }
};
