class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        return (len*(len+1)/2 - accumulate(nums.begin(), nums.end(), 0));
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	int result = nums.size();
	for (int i = 0; i < nums.size(); ++i) {
		result ^= i;
		result ^= nums[i];
	}
	return result;
    }
};
