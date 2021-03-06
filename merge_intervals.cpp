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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.empty()) return result;
        
        sort(intervals.begin(), intervals.end(), [&](Interval a, Interval b){ return a.start < b.start; });
        
        int len = intervals.size();
        auto curr = intervals[0];
        for (int i = 1; i < len; ++i) {
            if (curr.end >= intervals[i].start) {
                curr.end = max(curr.end, intervals[i].end);
            } else {
                result.emplace_back(curr);
                curr = intervals[i];
            }
        }
        result.emplace_back(curr);
        return result;
    }
};
