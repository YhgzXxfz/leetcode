class Solution {
public:
    string rearrangeString(string str, int k) {
        if (k == 0) return str;
        int length = (int)str.size(); 
        
        string result;
        unordered_map<char, int> dict;
        priority_queue<pair<int, char>> pq;
        
        for (char ch : str) dict[ch]++;
        for (auto& entry : dict) {
            pq.push(make_pair(entry.second, entry.first));
        }
        
        while (!pq.empty()) {
            vector<pair<int, char>> cache; //store used char during one while loop
            int count = min(k, length); //count: how many steps in a while loop
            for (int i = 0; i < count; i++) {
                if (pq.empty()) return "";
                auto tmp = pq.top();
                pq.pop();
                result.push_back(tmp.second);
                if(--tmp.first > 0) cache.push_back(tmp);
                length--;
            }
            for (auto p : cache) pq.push(p);
        }
        return result;
    }
};
