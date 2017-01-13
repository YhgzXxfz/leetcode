class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) return result;
        
        vector<int> curr;
        for (auto& num : nums) {
            if (curr.empty()) curr.emplace_back(num);
            else if (curr.back()+1 == num) curr.emplace_back(num);
            else {
		addToResult(curr, result);
                curr.clear();
                curr.emplace_back(num);
            }
        }
        addToResult(curr, result);
        return result;
    }

private:
    void addToResult(vector<int>& curr, vector<string>& result) {
        string solution = curr.size() == 1 ? to_string(curr[0]) : to_string(curr[0])+"->"+to_string(curr.back());
        result.emplace_back(solution);
    }
};
