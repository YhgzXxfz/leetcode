class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < len; ++i) {
            mp[nums[i]] = i;
        }
        
        sort(nums.begin(), nums.end());
        vector<string> result(len);
        for (int i = 0; i < len; ++i) {
            int rank = len-i;
            result[mp[nums[i]]] = rank <= 3 ? getTopThree(rank) : to_string(rank);
        }
        return result;
    }

private:
    string getTopThree(int rank) {
        return 1 == rank ? "Gold Medal" : 2 == rank ? "Silver Medal" : "Bronze Medal";
    }
};
