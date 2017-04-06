class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        if (a.empty()) return b;
        if (b.empty()) return a;
        
        int plus_a = a.find("+"), plus_b = b.find("+");
        int ra = stoi(a.substr(0,plus_a)), ia = stoi(a.substr(plus_a+1, a.size()-1));
        int rb = stoi(b.substr(0,plus_b)), ib = stoi(b.substr(plus_b+1, b.size()-1));
        long rc = ra*rb-ia*ib, ic = ra*ib+rb*ia;
        return to_string(rc)+"+"+to_string(ic)+"i";
    }
};
