// O(Nlog(max-min))
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double left = INT_MIN, right = INT_MAX;
        while (right -left > 0.000004) {
            double mid = left + (right-left)/2;
            cout << mid << ' ';
            if (isValid(nums, k, mid)) left = mid;
            else right = mid;
        }
        return right;
    }
    
private:
    bool isValid(vector<int>& nums, int k, double x) {
        int len = nums.size();
        vector<double> cums(len);
        for (int i = 0; i < len; ++i) {
            cums[i] = nums[i]-x;
        }
        
        double curr = 0, last = 0;
        for (int i = 0; i < k; ++i) {
            curr += cums[i];
        }
        if (curr >= 0) return true;
        
        for (int i = k; i < len; ++i) {
            curr += cums[i];
            last += cums[i-k];
            if (last < 0) {
                curr -= last;
                last = 0;
            }
            
            if (curr >= 0) return true;
        }
        return false;
    }
};



// O(N^2)
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
