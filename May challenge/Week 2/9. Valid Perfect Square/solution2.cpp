// find a number where low * low = num
// low < high because we want to stop if low = high
// +1 becuase without it, infinite loop occurs

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 1, high = num,mid;
        while(low < high) {
            mid = low + (high - low + 1)/2;
            if(mid * mid <= num)
                low = mid;
            else
                high = mid - 1;
        }
        return low * low == num; 
    }
};
