class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);

        vector<int> fact(n + 1, 1);
        string ans;
        for (int i = 1; i <= n; i++)
            fact[i] = i * fact[i - 1];
        
        for (int i = n; i > 0; i--) {
            int p = k / fact[i-1];
            
            ans += v[p] + '0';
            v.erase(v.begin() + p);
            
            k = k % fact[i-1];
        }
        
        return ans;
    }
};
