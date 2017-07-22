// use next_permutation in c++ stl
class Solution {
public:
    int nextGreaterElement(int n) {
        auto s = convertToArray(n);
	bool has_next = next_permutation(s.begin(), s.end());
        return has_next ? convertToInteger(s) : -1;
    }

private:
    vector<int> convertToArray(int n) {
	vector<int> s;
	while (n) {
            s.insert(s.begin(), n%10);
            n /= 10;
	}
	return s;
    }

    int convertToInteger(vector<int>& s) {
	long next = 0;
	reverse(s.begin(), s.end());
	while (!s.empty()) {
	    next = next*10 + s.back();
	    s.pop_back();

	    if (next > INT_MAX || next < INT_MIN) return -1;
	}
	return next;
    }
};


// implement next_permutation
class Solution {
public:
    int nextGreaterElement(int n) {
        auto s = convertToArray(n);
        bool has_next = findNextPermutation(s);
        return has_next ? convertToInteger(s) : -1;
    }

private:
    vector<int> convertToArray(int n) {
        vector<int> s;
        while (n) {
            s.insert(s.begin(), n%10);
            n /= 10;
        }
        return s;
    }
    
    bool findNextPermutation(vector<int>& s) {
        int len = s.size();
        int i = len-1;
        for (; i > 0; --i) {
            if (s[i-1] < s[i]) break;           // find a pair which s[i-1] < s[i]
        }
        if (i == 0) return false;
        
        int j = i;
        for (; j < len; ++j) {
            if (s[j] <= s[i-1]) break;          // find a number in s[i:end] just larger than s[i-1], then swap them
        }
        swap(s[i-1], s[j-1]);
        reverse(s.begin()+i, s.end());          // reverse s[i:end] to have the smallest next permutation
        return true;
    }
    
    int convertToInteger(vector<int>& s) {
        long next = 0;
        reverse(s.begin(), s.end());
        while (!s.empty()) {
            next = next*10 + s.back();
            s.pop_back();
            
            if (next > INT_MAX || next < INT_MIN) return -1;
        }
        return next;
    }
};
