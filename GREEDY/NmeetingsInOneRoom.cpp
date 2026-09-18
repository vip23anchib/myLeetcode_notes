//We need to schedule as many meetings as possible in a single room without overlaps. 
//The key observation is that once we choose a meeting that ends earliest, it leaves the room available for more potential meetings afterward. 

//This naturally leads to a greedy approach, where instead of testing all possible combinations we pick meetings in an order that maximizes 
//free time for future meetings.
//The greedy choice is to always select the meeting that finishes earliest among the available ones.

class Solution {
public:

    // Our own data structure for storing a meeting
    struct Meeting {
        int start;
        int end;
        int pos;

        // Constructor to initialize the values
        Meeting(int s, int e, int p) {
            start = s;
            end = e;
            pos = p;
        }
    };


    // Comparator function
    // We want to sort meetings according to their END TIME
    static bool compare(Meeting a, Meeting b) {
        return a.end < b.end;
    }


    int maxMeetings(vector<int>& start, vector<int>& end) {

        int n = start.size();

        vector<Meeting> arr;

        // Create Meeting objects
        // and store start, end and original position
        for(int i = 0; i < n; i++) {
            arr.push_back(Meeting(start[i], end[i], i + 1));
        }


        // Sort meetings based on END TIME
        sort(arr.begin(), arr.end(), compare);


        // freeTime = time at which the room becomes free
        int freeTime = -1;

        // Number of meetings we can attend
        int count = 0;


        // Go through meetings in increasing end-time order
        for(int i = 0; i < n; i++) {

            // If this meeting starts after the room becomes free,
            // we can attend this meeting
            if(arr[i].start > freeTime) {

                count++;

                // After attending this meeting,
                // the room will be free at its end time
                freeTime = arr[i].end;
            }
        }

        return count;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Another Approach


#include <bits/stdc++.h>
using namespace std;

// Class to hold solution logic
class Solution {
public:
    // Function to get all meetings that can be scheduled
    vector<int> maxMeetings(vector<int>& start, vector<int>& end) {
        // Store meetings as (end_time, start_time, original_index)
        vector<tuple<int, int, int>> meetings;
        for (int i = 0; i < start.size(); i++) {
            // i+1 for 1-based indexing
            meetings.push_back({end[i], start[i], i + 1}); 
           
        }

        // Sort by end time
        sort(meetings.begin(), meetings.end());

        vector<int> result; // To store meeting indices
        int lastEnd = -1;

        // Traverse sorted meetings
        for (auto& m : meetings) {
            int e = get<0>(m);
            int s = get<1>(m);
            int idx = get<2>(m);

            // If meeting starts after last one ends
            if (s > lastEnd) {
                // Store index
                result.push_back(idx); 
                // Update last end time
                lastEnd = e; 
            }
        }
        return result;
    }
};

// Main driver code
int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    Solution sol;
    vector<int> res = sol.maxMeetings(start, end);

    for (int idx : res) cout << idx << " ";
}
