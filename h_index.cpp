class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        
        int len = citations.size();
        vector<int> count(len+1, 0);
        for (auto citation : citations) {
            if (citation >= len) count[len]++;
            else count[citation]++;
        }
        
        int total = 0;
        for (int i = len; i >= 0; --i) {
            total += count[i];
            if (total >= i) return i;
        }
        return 0;
    }
};
