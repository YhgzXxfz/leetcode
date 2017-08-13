class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        for (int i = 0; i < sentences.size(); ++i) {
            dict[sentences[i]] += times[i];
        }
        data.clear();
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            dict[data]++;
            data.clear();
            return {};
        }
        
        data += c;
        auto comp = [&](pair<string, int> p1, pair<string, int> p2) {
            if (p1.second == p2.second) return p1.first < p2.first;
            return p1.second > p2.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(comp);
        
        for (auto entry : dict) {
            bool match = true;
            for (int i = 0; i < data.size(); ++i) {
                if (data[i] != entry.first[i]) {
                    match = false;
                    break;
                }
            }
            
            if (match) {
                pq.push(entry);
                if (pq.size() > 3) pq.pop();
            }
        }
        
        vector<string> result(pq.size());
        for (int i = pq.size() - 1; i >= 0; i--) {
            result[i] = pq.top().first;
            pq.pop();
        }
        return result;
    }
    
private:
    unordered_map<string, int> dict;
    string data;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */
