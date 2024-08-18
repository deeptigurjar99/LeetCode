#include <queue>
#include <unordered_set>

class Solution {
public:
    int nthUglyNumber(int n) {
        std::priority_queue<long, std::vector<long>, std::greater<long>> minHeap;
        std::unordered_set<long> seen;
        
        // Start with the first ugly number
        minHeap.push(1);
        seen.insert(1);
        
        long ugly = 1;
        
        for (int i = 0; i < n; ++i) {
            // Get the smallest number from the heap
            ugly = minHeap.top();
            minHeap.pop();
            
            // Generate next numbers and push them into the heap if not seen
            if (seen.find(ugly * 2) == seen.end()) {
                minHeap.push(ugly * 2);
                seen.insert(ugly * 2);
            }
            if (seen.find(ugly * 3) == seen.end()) {
                minHeap.push(ugly * 3);
                seen.insert(ugly * 3);
            }
            if (seen.find(ugly * 5) == seen.end()) {
                minHeap.push(ugly * 5);
                seen.insert(ugly * 5);
            }
        }
        
        return ugly;
    }
};
