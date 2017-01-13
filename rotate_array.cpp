// 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        vector<int> result = nums;
        result.insert(result.end(), nums.begin(), nums.end());
        nums = vector<int>(result.begin()+len-k, result.begin()+len+len-k);
    }
};

// O(N)
/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        vector<int> result;
        for (int i = len-k; i < len; ++i) {
            result.emplace_back(nums[i]);
        }
        
        for (int i = 0; i < len-k; ++i) {
            result.emplace_back(nums[i]);
        }
        nums = result;
    }
};
*/

// O(logN)
/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        reverse(nums, 0, len-1-k);
        reverse(nums, len-k, len-1);
        reverse(nums, 0, len-1);
    }

private:
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
};
*/
