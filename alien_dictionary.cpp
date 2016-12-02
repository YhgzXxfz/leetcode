class Solution {
public:
    string alienOrder(vector<string>& words) {
        // 1
        /*
        unordered_map<char, unordered_set<char>> suc, pre;
        unordered_set<char> chars;
        string curr;
        for (string next : words) {
            chars.insert(next.begin(), next.end());
            for (int i=0; i<min(curr.size(), next.size()); ++i) {
                char a = curr[i], b = next[i];
                if (a != b) {
                    suc[a].insert(b);
                    pre[b].insert(a);
                    break;
                } else if (i+1 <= curr.size()-1 && i+1 > next.size()-1) return "";
            }
            curr = next;
        }
        
        unordered_set<char> free = chars;
        for (auto p : pre) {
            free.erase(p.first);
        }
        
        string result;
        while (free.size()) {
            char a = *free.begin();
            free.erase(a);
            result += a;
            for (char b : suc[a]) {
                pre[b].erase(a);
                if (pre[b].empty()) free.insert(b);
            }
        }
        return result.size() == chars.size() ? result : "";
        */
        
        // 2
        unordered_map<char, unordered_set<char>> suc;
        unordered_map<char, int> indegrees;
        for (auto word : words) {
            for (char c : word) {
                indegrees[c] = 0;
            }
        }
        
        for (int i = 0; i < words.size()-1; ++i) {
            string curr = words[i], next = words[i+1];
            for (int j = 0; j < min(curr.size(), next.size()); ++j) {
                char lead = curr[j], following = next[j];
                if (lead != following) {
                    if (suc[lead].find(following) == suc[lead].end()) {
                        indegrees[following]++;
                        suc[lead].insert(following);
                    }
                    break;
                } 
                // invalid lexicographical input
                else if (j+1 <= curr.size()-1 && j+1 > next.size()-1) return "";
            }
        }
        
        queue<char> q;
        for (auto entry : indegrees) {
            if (entry.second == 0) q.push(entry.first);
        }
        
        string result = "";
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            result += c;
            if (suc.find(c) != suc.end()) {
                for (auto following : suc[c]) {
                    indegrees[following]--;
                    if (indegrees[following] == 0) q.push(following);
                }
            }
        }
        return result.size() == indegrees.size() ? result : "";
    }
};
