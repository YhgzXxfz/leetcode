class Solution {
public:
    	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    		if (t < 0) return false;

		unordered_map<long, long> mp;
		long w = (long)t +1;
		for (int i = 0; i < nums.size(); ++i) {
			long id = getId(nums[i], w);

			if (mp.count(id)) return true;
			if (mp.count(id-1) && abs(mp[id-1]-nums[i]) <= t) return true;
			if (mp.count[id+1) && abs(mp[id+1]-nums[i]) <= t) return true;

			mp[id] = (long) nums[i];
			if (mp.size() > k) mp.erase(getId(nums[i-k], w));
		}
		return false;
	}

private:
	long getId(int num, int width) {
		return num < 0 ? (num+1)/width -1 : num/width;
	}
};
