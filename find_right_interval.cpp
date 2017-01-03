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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> mp;
        int len = intervals.size();
        for (int i = 0; i < len; ++i) {
            mp[intervals[i].start] = i;
        }
        
        vector<int> result;
        for (auto& interval : intervals) {
            auto it = mp.lower_bound(interval.end);
            if (it == mp.end()) result.emplace_back(-1);
            else result.emplace_back(it->second);
        }
        return result;
    }
};
