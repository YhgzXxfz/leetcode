class Solution {
public:
    vector<int> n;

    Solution(vector<int> nums) {
        n = nums;
    }

    int pick(int target) {
        int count = 0, result = -1;
        for (int i = 0; i < n.size(); ++i) {
            if(n[i] != target) continue;
            
            count++;
            if(count == 1) result = i;
            else if(!(rand()%count)) result = i;
        }
        return result;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
