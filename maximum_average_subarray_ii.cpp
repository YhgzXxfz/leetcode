class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_ave = 0, sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        max_ave = sum/k;
    
        double ave = max_ave;
        int len = k;
        for (int i = k; i < nums.size(); ++i) {
            ++len;
            sum += nums[i];
            ave = sum/len;
            
            double temp_sum = sum, temp_ave = ave;
            for (int j = len -1; j >= k; --j) {
                temp_sum -= nums[i-j];
                temp_ave = temp_sum /j;
                if (temp_ave >= ave) {
                    ave = temp_ave;
                    sum = temp_sum;
                    len = j;
                }
            }
            
            max_ave = max(max_ave, ave);
        }
        return max_ave;
    }
};
