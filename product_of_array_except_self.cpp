class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int begin = 1, end = 1;
        
        vector<int> result(len, 1);
        
        for (int i = 0; i < len ; ++i) {
            result[i] *= begin;
            begin *= nums[i];
            result[len-1 -i] *= end;
            end *= nums[len-1 -i];
        }
        return result;
    }
};
