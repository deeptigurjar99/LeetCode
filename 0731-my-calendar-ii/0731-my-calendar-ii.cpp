#include <vector>
using namespace std;

class MyCalendarTwo {
private:
    vector<pair<int, int>> events;  // to store all events
    vector<pair<int, int>> overlaps;  // to store overlaps (double bookings)
    
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        // Check if the new event causes a triple booking by overlapping with any interval in overlaps
        for (auto& [overlap_start, overlap_end] : overlaps) {
            if (max(start, overlap_start) < min(end, overlap_end)) {
                // Triple booking would happen, reject this booking
                return false;
            }
        }
        
        // Now check for new overlaps and add them to the overlaps list
        for (auto& [event_start, event_end] : events) {
            int overlap_start = max(start, event_start);
            int overlap_end = min(end, event_end);
            if (overlap_start < overlap_end) {
                // There is an overlap, add this overlap to the overlaps list
                overlaps.push_back({overlap_start, overlap_end});
            }
        }
        
        // Add the new event to the events list
        events.push_back({start, end});
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
