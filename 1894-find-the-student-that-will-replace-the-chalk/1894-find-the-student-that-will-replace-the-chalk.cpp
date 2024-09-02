#include <vector>

class Solution {
public:
    int chalkReplacer(std::vector<int>& chalk, int k) {
        long long total_chalk_sum = 0;

        // Calculate the total chalk used in one complete round.
        for (int i = 0; i < chalk.size(); i++) {
            total_chalk_sum += chalk[i];
        }

        // Reduce k by the total chalk sum modulo
        k = k % total_chalk_sum;

        // Find the student who will replace the chalk
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }

        // In case no student found (this case won't happen as per problem statement)
        return -1;
    }
};

