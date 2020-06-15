// Brian Kernighan’s Algorithm
// Time complexity: O(number of sit bets in n)
// Space complexity: O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0)
            return false;
        
        int cnt = 0;
        while(n) {
            cnt ++;
            n = n & (n-1);
        }
        return cnt == 1;
    }
};
