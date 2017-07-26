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

