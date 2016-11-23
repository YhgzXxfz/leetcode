class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> p_sum;
        int result = 0, i; 
        long long left, right, sum = 0;
        for (i = 0, p_sum.insert(0); i < nums.size(); ++i) {
            sum += nums[i];
            result += std::distance(p_sum.lower_bound(sum-upper), p_sum.upper_bound(sum-lower));
            p_sum.insert(sum);
        }
        return result;
    }
};
