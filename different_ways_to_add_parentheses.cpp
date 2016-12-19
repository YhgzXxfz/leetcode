class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for (int i = 0; i < input.size(); ++i) {
            char c = input[i];
            if (ispunct(c)) {
                string left_input = input.substr(0,i);
                auto left = mp.find(left_input) == mp.end() ? diffWaysToCompute(left_input) : mp[left_input];
                
                string right_input = input.substr(i+1);
                auto right = mp.find(right_input) == mp.end() ? diffWaysToCompute(right_input) : mp[right_input];
                
                for (int a : left) {
                    for (int b : right) {
                        result.push_back(c == '+' ? a+b : c == '-' ? a-b : a*b);
                    }
                }
            }
        }
        
        if (result.size() == 0) result.emplace_back(stoi(input));
        mp[input] = result;
        return result;
    }
    
private:
    unordered_map<string, vector<int>> mp;
};
