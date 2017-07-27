// brute force
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size(), count = 0;
        for (int size = 1; size <= len; ++size) {
            for (int i = 0; i+size-1 < len; ++i) {
                string candidate = s.substr(i,size);
                if (isPalindrome(candidate)) count++;
            }
        }
        return count;
    }

private:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++; right--;
        }
        return true;
    }
};


// 2
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size(), count = 0;
		for (int i = 0; i < len; ++i) {
			for (int j = 0; i-j >= 0 && i+j < len && s[i-j] == s[i+j]; ++j) count++;
			for (int j = 0; i-1-j >= 0 && i+j < len && s[i-1-j] == s[i+j]; ++j) count++;
		}
		return count;
    }
};
