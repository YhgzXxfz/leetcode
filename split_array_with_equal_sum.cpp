
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> cums(len, 0);
        cums[0] = nums[0];
        for (int i = 1; i < len; ++i) {
            cums[i] = cums[i-1]+nums[i];
        }
        
        for (int j = 3; j < len-3; ++j) {
            unordered_set<int> st;
            for (int i = 1; i < j-1; ++i) {
                if (cums[i-1] == cums[j-1]-cums[i]) st.insert(cums[i-1]);
            }
            
            for (int k = j+2; k < len-1; ++k) {
                if (cums[k-1]-cums[j] == cums[len-1]-cums[k] && st.count(cums[k-1]-cums[j])) return true;
            }
        }
        return false;
    }
};
