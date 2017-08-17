class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        
        int sum = 0, curr_max = -1;
        for (auto t : timeSeries) {
            if (t > curr_max) {
                sum += duration;
            } else {
                sum += (t+duration-1 - curr_max);
            }
            curr_max = max(curr_max, t+duration-1);
        }
        return sum;
    }
};

// TLE
/*
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        
        int len = timeSeries.size();
        vector<int> poison(timeSeries[len-1]+duration, 0);
        for (auto t : timeSeries) {
            for (int i = 0; i < duration; ++i) {
                poison[t+i] = 1;
            }
        }
        return count(poison.begin(), poison.end(), 1);
    }
};
*/
