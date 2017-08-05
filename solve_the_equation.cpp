class Solution {
public:
    string solveEquation(string equation) {
        int pos = equation.find_first_of("=");
        auto left = eval(equation.substr(0, pos)), right = eval(equation.substr(pos+1));
        int nom = right.second - left.second, denom = left.first - right.first;
        
        if (nom == 0 && denom == 0) return "Infinite solutions";
        if (denom == 0) return "No solution";
        return "x=" + to_string(nom/denom);
    }

private:
    pair<int, int> eval(string expr) {
        int denom = 0, nom = 0, i = 0, begin = 0, len = expr.size();
        auto vec = stringToVector(expr);
        for (auto s : vec) {
            if (s.find("x") != string::npos) {
                string temp = s.substr(0, s.size()-1);
                if (temp.find_first_of("0123456789") != string::npos) denom += stoi(temp);
                else {
                    if (temp.empty() || temp == "+") denom++;
                    if (temp == "-") denom--;
                }
            } else {
                nom += stoi(s);
            }
        }
        return make_pair(denom, nom);
    }
    
    vector<string> stringToVector(string s) {
        vector<string> vec;
        int begin = 0, i = 0, len = s.size();
        while (i < len) {
            int pos = s.find_first_of("+-", i);
            if (pos != string::npos) {
                if (pos != begin) vec.push_back(s.substr(begin, pos-begin));
                i = pos+1;
                begin = pos;
            } else {
                vec.push_back(s.substr(begin));
                break;
            }
        }
        return vec;
    }
};
