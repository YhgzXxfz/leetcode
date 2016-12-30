class Solution {
public:
    string reverseString(string s) {
        // 1
        /*
        reverse(s.begin(), s.end());
        return s;
        */
        
        // 2
        int left = 0, right = s.size()-1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
        return s;
    }
};
