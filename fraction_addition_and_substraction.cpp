class Solution {
public:
    string fractionAddition(string expression) {
        auto vec = stringToVector(expression);
        string sum = "";
        for (int i = 0; i < vec.size(); ++i) {
            sum = add(sum, vec[i]);
        }
        return sum;
    }

private:
    vector<string> stringToVector(string s) {
        int len = s.size(), i = 0, begin = 0;
        vector<string> vec;
        while (i < len) {
            if (s[i] == '+' || s[i] == '-') { begin = i; i++; }

            while (i < len && s[i] != '+' && s[i] != '-') i++;
            vec.push_back(s.substr(begin, i-begin));
        }
        return vec;
    }
    
    string add(string s1, string s2) {
        if (s1.empty()) return s2;
        
        auto p1 = stringToInt(s1), p2 = stringToInt(s2);
        
        int common = lcm(p1.second, p2.second);
        int num = common/p1.second * p1.first + common/p2.second * p2.first;
        int g = gcd(abs(num), common);
        num /= g; common /= g;
        return to_string(num) + "/" + to_string(common);
    }
    
    pair<int,int> stringToInt(string s) {
        int pos = s.find_first_of("/");
        return make_pair(stoi(s.substr(0, pos)), stoi(s.substr(pos+1)));
    }
    
    int lcm(int a, int b) {
        return a/gcd(a,b) * b;
    }
    
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a%b);
    }
};
