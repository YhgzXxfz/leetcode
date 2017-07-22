class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> s;
        while (n) {
            s.insert(s.begin(), n%10);
            n /= 10;
        }
        bool has_next = next_permutation(s.begin(), s.end());
        if (!has_next) return -1;
        
        reverse(s.begin(), s.end());
        long next = 0;
        while (!s.empty()) {
            next = next*10 + s.back();
            s.pop_back();
            
            if (next > INT_MAX || next < INT_MIN) return -1;
        }
        return next;
    }
};
