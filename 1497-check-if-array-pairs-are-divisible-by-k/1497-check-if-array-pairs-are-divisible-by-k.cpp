#include <vector>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // Create a frequency array to store the remainders when dividing by k
        vector<int> remainderCount(k, 0);

        // Count the remainders of each element in the array
        for (int num : arr) {
            int rem = num % k;
            // Adjust negative remainders
            if (rem < 0) rem += k;
            remainderCount[rem]++;
        }

        // Check if we can form pairs
        for (int i = 0; i <= k / 2; ++i) {
            if (i == 0) {
                // If remainder is 0, there should be an even count of such numbers
                if (remainderCount[i] % 2 != 0) return false;
            } else {
                // The count of remainder i should match the count of remainder k - i
                if (remainderCount[i] != remainderCount[k - i]) return false;
            }
        }

        return true;
    }
};
