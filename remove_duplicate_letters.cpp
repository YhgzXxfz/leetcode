class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> mp(256, 0), visited(256, 0);
        for (char c : s)
            mp[c]++;
            
        string result = "0";
        for (char c : s) {
            mp[c]--;
            if (visited[c]) continue;
            while (c < result.back() && mp[result.back()]) {
                visited[result.back()] = false;
                result.pop_back();
            }
            result += c;
            visited[c] = true;
        }
        return result.substr(1);
    }
};
