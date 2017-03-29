class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.size();
        for (int i = 0; i < len; i += 2*k) {
            reverse(s, i, min(len-1, i+k-1));
        }
        return s;
    }

private:
    void reverse(string& s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};
