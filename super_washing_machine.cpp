class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int len = machines.size(), sum = accumulate(machines.begin(), machines.end(), 0);
        if (sum % len) return -1;
        
        int ave = sum/len;
        int count = 0, result = 0;
        for (auto dress : machines) {
            count += dress-ave;
            result = max(max(result, abs(count)), dress-ave);
        }
        return result;
    }
};
