// 1 sort
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return 0;
        
        auto copy = nums;
        sort(nums.begin(), nums.end());
        int left = 0, right = len-1;
        while (left < len && nums[left] == copy[left]) left++;
        while (right >= 0 && nums[right] == copy[right]) right--;
        return right > left ? right-left+1 : 0;
    }
};


// 2 stack
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1) return 0;

		stack<int> s;
		int left = len-1, right = 0;
		for (int i = 0; i < len; ++i) {
			while (!s.empty() && nums[i] < nums[s.top()]) {
				left = min(left, s.top());
				s.pop();
			}
			s.push(i);
		}

		s = stack<int>();
		for (int i = len-1; i >= 0; --i) {
			while (!s.empty() && nums[i] > nums[s.top()]) {
				right = max(right, s.top());
				s.pop();
			}
			s.push(i);
		}
		return right > left ? right-left+1 : 0;
	}
};

// 3 four passes
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
		if (len <= 1) return 0;

		int min_num = INT_MAX, max_num = INT_MIN;
		bool flag = false;
		for (int i = 1; i < len; ++i) {
			if (nums[i-1] > nums[i]) flag = true;
			if (flag) min_num = min(min_num, nums[i]);
		}

        flag = false;
		for (int i = len-2; i >= 0; --i) {
			if (nums[i] > nums[i+1]) flag = true;
			if (flag) max_num = max(max_num, nums[i]);
		}

		int left, right;
		for (left = 0; left < len; ++left) {
			if (min_num < nums[left]) break;
		}

		for (right = len-1; right >= 0; --right) {
			if (max_num > nums[right]) break;
		}
		return right > left ? right-left+1 : 0;
    }
};
