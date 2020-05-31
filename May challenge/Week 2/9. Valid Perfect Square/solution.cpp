// number is perfect square IFF number of divisors is odd

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i;
        long long ans = 0;
        for(i = 1; i*i < num; i++){
            if(num % i == 0)
                ans += 2;
        }
        
        if(i*i == num)
            ans ++;
        
        return ans % 2 == 1;
    }
};
