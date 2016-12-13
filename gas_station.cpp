class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_sum = 0, curr_sum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total_sum += gas[i]-cost[i];
            curr_sum += gas[i]-cost[i];
            if (curr_sum < 0) {
                curr_sum = 0;
                start = i+1;
            }
        }
        
        return total_sum >= 0 ? start : -1;
    }
};
