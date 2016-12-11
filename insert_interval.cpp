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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        int len = intervals.size();
        
        int id = 0;
        while (id < len && newInterval.start > intervals[id].end) {
            result.push_back(intervals[id++]);
        }
        
        while (id < len && newInterval.end >= intervals[id].start) {
            newInterval.start = min(newInterval.start, intervals[id].start);
            newInterval.end = max(newInterval.end, intervals[id].end);
            id++;
        }
        result.push_back(newInterval);
        
        while (id < len) {
            result.push_back(intervals[id++]);
        }
        return result;
    }
};
