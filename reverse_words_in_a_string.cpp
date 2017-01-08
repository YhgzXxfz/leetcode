class Solution {
public:
    void reverseWords(string &s) {
        int i = 0, len = s.size(), word = 0, trimed_size = 0, begin = 0;
        while (true) {
            while (i < len && s[i] == ' ') i++;
            if (i == len) break;
            
            if (word) s[trimed_size++] = ' ';
            
            begin = trimed_size;
            while (i < len && s[i] != ' ') {
                s[trimed_size++] = s[i++];
            }
            reverse(s, begin, trimed_size-1);
            word++;
        }
        
        s.resize(trimed_size);
        reverse(s, 0, trimed_size-1);
    }

private:
    void reverse(string& s, int left, int right) {
        while (left < right) {
            swap(s[left], s[right]);
            left++; right--;
        }
    }
};
