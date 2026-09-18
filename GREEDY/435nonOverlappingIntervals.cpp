// Greedy approach:
// 1. Sort intervals by END time.
// 2. Keep the interval that ends earliest.
// 3. If current start >= last selected end,
//    select the current interval.
// 4. Count how many we keep.
// 5. Answer = total intervals - kept intervals.

class Solution {
public:

    // Sort according to END time
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // Sort by ending time
        sort(intervals.begin(), intervals.end(), compare);

        // Keep the first interval
        int cnt = 1;

        // End time of last selected interval
        int lastEndTime = intervals[0][1];

        for(int i = 1; i < n; i++) {

            // No overlap → select this interval
            if(intervals[i][0] >= lastEndTime) {
                cnt++;

                // Update last ending time
                lastEndTime = intervals[i][1];
            }
        }

        // Remove the intervals we couldn't keep
        return n - cnt;
    }
};
