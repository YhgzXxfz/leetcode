class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> result(len);
        stack<int> s;
        for (int i = len-1; i >= 0; --i) {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) s.pop();
            
            result[i] = s.empty() ? 0 : s.top()-i;
            s.push(i);
        }
        return result;
    }
};
