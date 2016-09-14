class Solution {
public:
    Solution(vector<int> nums) {
        data = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return data;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result = data;
        int len = data.size();
        for (int i = 0; i < len; ++i) {
            int index = i+rand() % (len-i);
            swap(result[i], result[index]);
        }
        return result;
    }
    
private:
    vector<int> data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
