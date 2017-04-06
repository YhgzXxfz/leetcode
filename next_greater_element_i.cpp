class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> mp;
        generateNextGreaterElements(nums, mp);
        
        vector<int> result;
        for (auto num : findNums) {
            result.emplace_back(mp.count(num) ? mp[num] : -1);
        }
        return result;
    }

private:
    void generateNextGreaterElements(vector<int>& nums, unordered_map<int, int>& mp) {
        stack<int> s;
        for (auto num : nums) {
            while (!s.empty() && s.top() < num) {
                mp[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
    }
};


// O(N^2)
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
