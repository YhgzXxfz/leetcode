class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        long long prev = (long long)lower-1;
        vector<string> result;
        for (int i = 0; i <= nums.size(); ++i) {
            long long curr = nums.size() == i ? (long long)upper+1 : nums[i];
            if (curr-prev >= 2) result.emplace_back(getRange(prev+1, curr-1));
            
            prev = curr;
        }
        return result;
    }

private:
    string getRange(int from, int to) {
        return from == to ? to_string(from) : to_string(from)+"->"+to_string(to);
    }
};
