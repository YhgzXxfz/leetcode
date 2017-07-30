class Solution {
public:
    bool isValid(string code) {
        stack<string> s;
        for (int i = 0; i < code.size(); ) {
            if (i > 0 && s.empty()) return false;
            if (code.substr(i,9) == "<![CDATA[") {
                int j = i+9;
                i = code.find("]]>", j);

                if (i == string::npos) return false;
                i += 3;
            } else if (code.substr(i,2) == "</") {
                int j = i+2;
                i = code.find('>', j);

                if (i == string::npos || i == j || i - j > 9) return false;
                for (int k = j; k < i; k++) {
                    if(code[k] < 65 || code[k] > 90) return false;
                }
                
                if (s.empty()) return false;
                auto curr = s.top();
                s.pop();
                if (curr != code.substr(j, i-j)) return false;
                i++;
            } else if (code.substr(i,1) == "<") {
                int j = i+1;
                i = code.find('>', j);
                
                if (i == string::npos || i == j || i - j > 9) return false;
                for (int k = j; k < i; k++) {
                    if (code[k] < 65 || code[k] > 90) return false;
                }

                s.push(code.substr(j, i-j));
                i++;
            } else {
                i++;
            }
        }
        return s.empty();
    }
};
