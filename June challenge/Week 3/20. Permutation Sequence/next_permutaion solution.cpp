class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);

        int i = 0;
        do {
            i++;
            if (i == k) {
                string ans;
                for (auto j : v)
                    ans += j + '0';
                return ans;
            }
        } while (next_permutation(v.begin(), v.end()));
        
        return "";
    }
};
