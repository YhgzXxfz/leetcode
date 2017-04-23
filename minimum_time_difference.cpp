class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        unordered_map<int, int> mp;
        if (checkDuplicates(timePoints, mp)) return 0;
        
        set<int> buckets;
        constructBuckets(timePoints, buckets);
        return calculateMinDiff(buckets);
    }
    
private:
    int convertTimeToMinutes(string time) {
        return stoi(time.substr(0, 2))*60 + stoi(time.substr(3));
    }
    
    bool checkDuplicates(vector<string>& timePoints, unordered_map<int, int>& mp) {
        for (const auto& time : timePoints) {
            mp[convertTimeToMinutes(time)]++;
        }
        
        for (const auto& entry : mp) {
            if (entry.second > 1) return true;
        }
        return false;
    }

    void constructBuckets(vector<string>& timePoints, set<int>& buckets) {
        for (const auto& time : timePoints) {
            buckets.insert(convertTimeToMinutes(time));
        }
    }
    
    int calculateMinDiff(set<int>& buckets) {
        int diff = INT_MAX;
        for (auto it = buckets.begin(); it != buckets.end(); ++it) {
            if (it == prev(buckets.end())) break;
            
            diff = min(diff, *next(it)-*it);
        }
        diff = min(diff, *buckets.begin()+24*60 -*prev(buckets.end()));
        return diff;
    }
};
