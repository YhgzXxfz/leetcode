class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return true;
        int sum = (1+maxChoosableInteger)*maxChoosableInteger/2;
        if (sum < desiredTotal) return false;
        
        unordered_map<int, bool> mp;
        vector<int> used(maxChoosableInteger+1);
        return dfs(mp, used, desiredTotal);
    }

private:
    bool dfs(unordered_map<int, bool>& mp, vector<int>& used, int target) {
        if (target <= 0) return false;
        
        int key = form(used);
        if (mp.find(key) == mp.end()) {
            for (int i = 1; i < used.size(); ++i) {
                if (!used[i]) {
                    used[i] = true;
                    if (!dfs(mp, used, target-i)) {
                        mp[key] = true;
                        used[i] = false;
                        return true;
                    }
                    used[i] = false;
                }
            }
            mp[key] = false;
        }
        return mp[key];
    }
    
    int form(vector<int>& used) {
        int result = 0;
        for (auto i : used) {
            result <<= 1;
            result |= i;
        }
        return result;
    }
};
