class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR start and goal to find the positions where bits differ
        int xorResult = start ^ goal;
        
        // Count the number of 1's in the XOR result, which gives the number of differing bits
        int count = 0;
        while (xorResult > 0) {
            // If the last bit is 1, increment the count
            count += (xorResult & 1);
            // Shift right to check the next bit
            xorResult >>= 1;
        }
        
        return count;
    }
};