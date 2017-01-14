class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        int cn1 = 0, cn2 = 0, major1, major2;
        
        for (int n : nums) {
            if (major1 == n) cn1++;
            else if (major2 == n) cn2++;
            else if (cn1 == 0) {
                major1 = n;
                cn1 = 1;
            } else if (cn2 == 0) {
                major2 = n;
                cn2 = 1;
            } else {
                --cn1;
                --cn2;
            }
        }
        
        cn1 = cn2 = 0;
        for (int n : nums) {
            if (n == major1) ++cn1;
            else if (n == major2) ++cn2;
        }
        
        vector<int> result;
        if (cn1 > len/3) result.emplace_back(major1);
        if (cn2 > len/3) result.emplace_back(major2);
        
        return result;
    }
};
