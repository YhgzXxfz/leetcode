class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (auto c : magazine) {
            mp[c]++;
        }
        
        for (auto c : ransomNote) {
            if (mp.find(c) == mp.end()) return false;
            mp[c]--;
            if (mp[c] == 0) mp.erase(c);
        }
        return true;
    }
    
private:
    unordered_map<char, int> mp;
};
