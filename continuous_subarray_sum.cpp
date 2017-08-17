// hashmap
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int mod = k == 0 ? sum : sum%k;
            
            if (mp.find(mod) != mp.end()) {
                if (i - mp[mod] >= 2) return true;
            }
            else mp[mod] = i;
        }
        return false;
    }
};


// hashset
/*
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0, prev = 0;
        unordered_set<int> st;
        for (auto num : nums) {
            sum += num;
            int mod = k == 0 ? sum : sum%k;
            if (st.count(mod)) return true;
            
            st.insert(prev);
            prev = mod;
        }
        return false;
    }
};
*/
