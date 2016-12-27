class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if (s.empty()) return result;
        
        vector<string> solution;
        getPartition(result, s, 0, solution);
        return result;
    }
    
    void getPartition(vector<vector<string>>& result, string s, int index, vector<string>& solution) {
        if (index == s.size()) {
            result.emplace_back(solution);
            return;
        }
        
        for (int i = index; i < s.size(); ++i) {
            if (isPalindrome(s, index, i)) {
                solution.emplace_back(s.substr(index, i+1 - index));
                getPartition(result, s, i+1, solution);
                solution.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left; --right;
        }
        return true;
    }
};
