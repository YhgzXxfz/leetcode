/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        auto comp = [](const Interval& i1, const Interval& i2) { return i1.start < i2.start; };
        sort(intervals.begin(), intervals.end(), comp);
        
        int count = 0, prev = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[prev].end) {
                count++;
                if (intervals[i].end < intervals[prev].end) prev = i;
            }
            else prev = i;
        }
        return count;
    }
};
