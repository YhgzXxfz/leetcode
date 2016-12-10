class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int x, int y) {
            return to_string(x)+to_string(y) > to_string(y)+to_string(x);
        });
       
        string result;
        for (auto num : nums) {
            result += to_string(num);
        }
        while (result.size() > 1 && result[0] == '0') result.erase(0,1);
        return result;
    }
};
