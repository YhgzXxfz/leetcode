// recursive
class Solution {
public:
	string decodeString(string s) {
		int i = 0;
		return decodeString(s, i);
	}

private:
	string decodeString(string s, int& i) {
		string result;
		int len = s.size();
		while (i < len && s[i] != ']') {
			if (!isdigit(s[i])) {
				result += s[i++];
			} else {
				int num = 0;
				while (i < len && isdigit(s[i])) {
					num = num*10 + s[i++]-'0';
				}

				++i;
				string nested = decodeString(s, i);
				++i;

				while (num-- > 0) {
					result += nested;
				}
			}
		}
	}
};








// iterative
class Solution {
public:
    string decodeString(string s) {
        string tmp;
        stack<int> numStack;
        stack<string> strStack;
        int n = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i]))
                n = n * 10 + s[i] - '0';
            else if (s[i] == '[') {
                numStack.push(n);
                n = 0;
                strStack.push(tmp);
                tmp.clear();
            }
            else if (s[i] == ']') {
                int k = numStack.top();
                numStack.pop();
                for (; k > 0; k--)
                    strStack.top() += tmp;
                tmp = strStack.top();
                strStack.pop();
            }
            else
                tmp += s[i];
        }
        return strStack.size() == 0 ? tmp : strStack.top();
    }
};
