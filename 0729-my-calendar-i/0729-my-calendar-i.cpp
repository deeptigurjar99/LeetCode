#include <vector>
using namespace std;

class MyCalendar {
public:
    // Vector to store the events as pairs of start and end times
    vector<pair<int, int>> events;

    // Constructor
    MyCalendar() {
    }
    
    // Function to check if an event can be booked
    bool book(int start, int end) {
        // Iterate through all the already booked events
        for (auto event : events) {
            // If there is an overlap with an existing event, return false
            if (max(start, event.first) < min(end, event.second)) {
                return false;
            }
        }
        // If no overlap is found, add the event to the list and return true
        events.push_back({start, end});
        return true;
    }
};

