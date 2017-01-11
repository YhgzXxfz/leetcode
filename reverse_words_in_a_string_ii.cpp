class Solution {
public:
    void reverseWords(string &s) {
        int len = s.size(), i = 0, trimmed_size = 0, word = 0, begin = 0;
        while (true) {
            while (i < len && s[i] == ' ') i++;
            if (i == len) break;
            
            if (word) s[trimmed_size++] = ' ';
            
            begin = trimmed_size;
            while (i < len && s[i] != ' ') {
                s[trimmed_size++] = s[i++];
            }
            reverse(s, begin, trimmed_size-1);
            word++;
        }
        
        s.resize(trimmed_size);
        reverse(s, 0, s.size()-1);
    }

private:
    void reverse(string& s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};
