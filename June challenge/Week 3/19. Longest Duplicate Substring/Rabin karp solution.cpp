class Solution {
public:
    typedef long long ll;
    #define D 256

    // (1e9 + 7) huge prime for avoiding hashing collisions
    const ll MOD = 1000000007;
    

    string duplicateForK(string s, int k) {
        ll p = 0;
        ll n = s.length();
        ll h = 1;

        // store indexes for the same hash to comapre the new equal hash with them
        unordered_map<ll, vector<int>> hashes;

        // calculate D^(k-1) once and store it for rolling hash
        for (int i = 1; i < k; i++) {
            h = (h * D) % MOD;
        }
        
        // compute hash for first sliding window
        for (int i = 0; i < k; i++) {
            p = (D * p + s[i]) % MOD;
        }

        // loop on all substrings with size k
        for (int i = 0; i <= n - k; i++) {
            // if this hash doesn't exit before, store it in the map with corresponding index
            if (hashes.find(p) == hashes.end())
                hashes.insert({p, {i}});
            else {
                // loop on all the indexes with the same hash
                for (int idx : hashes[p]) {
                    // if the two substrings are equal, we've found dublicated subtring with length k, return it
                    if (s.substr(i, k) == s.substr(idx, k))
                        return s.substr(i, k);
                }
                // the current index isn't the same with all indexes with same hash, so push it with them
                hashes[p].push_back(i);
            }

            // rolling hash
            if (i < n - k) {
                p = (((D * (p - s[i] * h) + s[i + k]) % MOD) + MOD) % MOD;
            }
        }
        return "";
    }

    string longestDupSubstring(string S) {
        int n = S.length();

        int low = 1, high = n - 1;
        string res;

        while (low < high) {
            int mid = low + (high - low + 1) / 2;

            string ret = duplicateForK(S, mid);

            
            if (!ret.empty()) {
                res = ret;
                low = mid;
            } else
                high = mid - 1;
        }

        return res;
    }
};
