class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n,0);
        stack<int> s;
        int prev = 0;
        for (auto log : logs) {
            auto vec = split(log);
            int func = stoi(vec[0]), curr = stoi(vec[2]);
            string type = vec[1];
            
            if (type == "start") {
                if (!s.empty()) result[s.top()] += curr-prev;
                
                s.push(func);
                prev = curr;
            } else {
                result[s.top()] += curr-prev+1;
                s.pop();
                prev = curr+1;
            }
        }
        return result;
    }

private:
    vector<string> split(string s) {
        int first = s.find_first_of(":"), second = s.find_first_of(":", first+1);
        return {s.substr(0,first), s.substr(first+1, second-first-1), s.substr(second+1)};
    }
};
