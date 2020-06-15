// Time complexity: O(logn)
// Space complexity: O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        while (n > 1) {
            if (n % 2)
                return false;
            n /= 2;
        }
        
        return n == 1; 
    }
};
