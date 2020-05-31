class Solution {
public:
    int findComplement(int num) {
        
        int mask = 1;
        // construct number of ones, its number of bits exactly equal number of bits of num 
        while(mask < num)
            mask = (mask << 1) + 1;
        // xor flip the number when the second operand is all ones
        return mask ^ num;
    }
};
