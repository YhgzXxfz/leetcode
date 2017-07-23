// set + map
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
		return vector<int>{findDup(nums), findMissing(nums)};
    }

private:
    int findMissing(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int missing = 0;
        for (int i = 1; i <= nums.size(); ++i) {
			if (!st.count(i)) missing = i;
		}
        return missing;
    }
    
    int findDup(vector<int>& nums) {
        unordered_map<int, int> mp;
		for (auto num : nums) mp[num]++;
        
        int dup = 0;
		for (auto entry : mp) {
			if (entry.second > 1) dup = entry.first;
		}
        return dup;
    }
};


// index acceleration
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i = 0, len = nums.size();
		while (i < len) {
			if (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
			else i++;
		}

		for (int i = 0; i < len; ++i) {
			if (nums[i] != i+1) {
				return vector<int>{nums[i], i+1};
			}
		}
		return {0,0};
    }
};
