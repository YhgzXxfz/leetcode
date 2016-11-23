/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 // 1 Reconstruct all the intervals each time
 /*
class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        nums.insert(val);
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> result;
        vector<int> candidates(nums.begin(), nums.end());
        int len = candidates.size();
        for (int i = 0; i < len; ++i) {
            int start = candidates[i], end = candidates[i];
            while (i < len && (candidates[i+1] == candidates[i]+1)) {
                i++;
                end = candidates[i];
            }
            result.push_back(Interval(start, end));
        }
        return result;
    }
    
private:
    set<int> nums;
};
*/

// 2 Merge
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        int start = val, end = start;
        auto it = nums.lower_bound(Interval(val, val));
        
        if (it != nums.begin() && (--it)->end +1 < val) it++;
        while (it != nums.end() && val-1 <= it->end && val+1 >= (it)->start) {
            start = min(start, it->start);
            end = max(end, it->end);
            it = nums.erase(it);
        }
        nums.insert(it, Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> result;
        for (auto val : nums) result.push_back(val);
        return result;
    }
    
private:
    struct Cmp {
        bool operator() (Interval a, Interval b) { return a.start < b.start;}
    };
    set<Interval, Cmp> nums;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
