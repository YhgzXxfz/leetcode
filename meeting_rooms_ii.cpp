/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 // 1 t-O(NlogN), m-O(N)
 /*
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        auto comp = [](const Interval& i1, const Interval& i2) { return i1.start < i2.start; };
        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval> rooms;
        for (auto& interval : intervals) {
            // non-overlapping intervals found means they can share one room
            int index = findNonOverlapping(rooms, interval);
            if (rooms.empty() || index == -1) rooms.emplace_back(interval);
            else rooms[index] = interval;
        }
        return rooms.size();
    }

private:
    int findNonOverlapping(vector<Interval> rooms, Interval interval) {
        for (int i = 0; i < rooms.size(); ++i) {
            if (interval.start >= rooms[i].end) return i;
        }
        return -1;
    }
};
*/

// 2 t-O(NlogN), m-O(N)
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mp;
        for (auto& interval : intervals) {
            mp[interval.start]++;
            mp[interval.end]--;
        }
        
        // max_count means the max meetings held at the same time => max rooms needed
        int count = 0, max_count = 0;
        for (auto entry : mp) {
            count += entry.second;
            max_count = max(max_count, count);
        }
        return max_count;
    }
};
