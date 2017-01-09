class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels({'a','e','o','i','u','A','E','O','I','U'});
        
        int left = 0, right = s.size()-1;
        while (left < right) {
            while (left < right && !vowels.count(s[left])) left++;
            if (left >= right) break;
            
            while (right > left && !vowels.count(s[right])) right--;
            if (right <= left) break;
            
            swap(s[left], s[right]);
            left++; right--;
        }
        return s;
    }
};
