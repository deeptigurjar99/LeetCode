class Solution {
public:
    int findComplement(int num) {
        // Find the number of bits in num
        unsigned int mask = ~0;  // Start with a mask of all 1s (unsigned int)
        
        // Shift mask left until it is just larger than num
        while (num & mask) {
            mask <<= 1;
        }
        
        // XOR num with the inverted mask (only relevant bits will be flipped)
        return num ^ ~mask;
    }
};

