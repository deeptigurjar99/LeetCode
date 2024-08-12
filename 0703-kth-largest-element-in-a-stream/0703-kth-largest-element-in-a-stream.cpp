#include <vector>
#include <queue>
#include <algorithm> // For std::make_heap and std::pop_heap

class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) : k(k) {
        // Initialize the min-heap with the first k elements or all elements if less than k
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        // Add new value to the heap
        minHeap.push(val);
        
        // If heap exceeds size k, remove the smallest element
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        
        // The root of the heap is the kth largest element
        return minHeap.top();
    }

private:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Min-heap
};

