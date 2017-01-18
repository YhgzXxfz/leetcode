class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_len = 0, begin = 0, zeroes = 0, flip = 1; // flip at most k zero
        for (int i = 0; i < nums.size(); ++i) {
           
	    if (nums[i] == 0) zeroes++;

            while (zeroes > flip) {
                if (nums[begin] == 0) zeroes--;
		begin++;
            }

            max_len = max(max_len, i-begin+1);
        }                                                               
        return max_len;        
    }
};
