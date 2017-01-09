class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> rows(numRows);
        int i = 0;
        bool flag = true;
        for (auto c : s) {
            rows[i] += c;
            
            if (flag) i++;
            else i--;
            if (i == 0 || i == numRows-1) flag = !flag;
        }
        
        string result = "";
        for (auto& row : rows) {
            result += row;
        }
        return result;
    }
};
