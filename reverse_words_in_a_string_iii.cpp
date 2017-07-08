class Solution {
public:
    string reverseWords(string s) {
        int len = s.size(), i = 0, begin = 0;
        string result = s;
        while (i < len) {
            while (i < len && s[i] != ' ') i++;
            
            reverse(result, begin, i-1);
            
            i++;
            begin = i;
        }
        return result;
    }

private:
    void reverse(string& result, int left, int right) {
        while (left < right) {
            swap(result[left], result[right]);
            left++; right--;
        }
    }
};
