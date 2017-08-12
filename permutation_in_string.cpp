class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        if (len1 > len2) return false;
        
        int count[26] = {};
        for (int i = 0; i < len1; ++i) {
            count[s1[i]- 'a']++;
            count[s2[i]- 'a']--;
        }
        if (isZero(count)) return true;
        
        for (int i = len1; i < len2; ++i) {
            count[s2[i-len1]- 'a']++;
            count[s2[i]- 'a']--;
            if (isZero(count)) return true;
        }
        return false;
    }

private:
    bool isZero(int* count) {
        for (int i = 0; i < 26; ++i) {
            if (count[i]) return false;
        }
        return true;
    }
};
