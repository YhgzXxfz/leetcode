class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> query) {
        unordered_map<string, unordered_map<string, double>> mp;
        for (int i = 0; i < values.size(); ++i) {
            mp[equations[i].first].insert(make_pair(equations[i].second, values[i]));
            if (values[i]) mp[equations[i].second].insert(make_pair(equations[i].first, 1/values[i]));
        }
        
        vector<double> result;
        for (auto i : query) {
            unordered_set<string> st;
            double quotient = evaluate(i.first, i.second, mp, st);
            if (quotient) result.push_back(quotient);
            else result.push_back(-1.0);
        }
        return result;
    }
    
private:
    double evaluate(string up, string down, unordered_map<string, unordered_map<string, double>>& mp, unordered_set<string>& st) {
        if (mp[up].find(down) != mp[up].end()) return mp[up][down];
        for (auto i : mp[up]) {
            if (st.find(i.first) == st.end()) {
                st.insert(i.first);
                double quotient = evaluate(i.first, down, mp, st);
                if (quotient) return i.second*quotient;
            }
        }
        return 0;
    }
};
