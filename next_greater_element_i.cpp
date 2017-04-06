class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int len = findNums.size();
        vector<int> result;
        
        bool found = false;
        for (auto num : findNums) {
            auto it = find(nums.begin(), nums.end(), num);
            found = false;
            it++;
            for (; it != nums.end(); ++it) {
                if (*it > num) {
                    result.emplace_back(*it);
                    found = true;
                    break;
                }
            }
            if (!found) result.emplace_back(-1);
        }
        return result;
    }
};
