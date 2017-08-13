class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int count = 0;
        for (auto t : tasks) {
            mp[t]++;
            count = max(count, mp[t]);
        }
        
        int result = (count-1) * (n+1);
        for (auto entry : mp) {
            if (entry.second == count) result++;
        }
        return max((int)tasks.size(), result);
    }
};
