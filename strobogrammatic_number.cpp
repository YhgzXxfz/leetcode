class Solution {
public:
    bool isStrobogrammatic(string num) {
        mp['0'] = '0';
        mp['1'] = '1';
        mp['6'] = '9';
        mp['8'] = '8';
        mp['9'] = '6';
        int left = 0, right = num.size()-1;
        while (left <= right) {
            if (mp.find(num[left]) == mp.end() 
                || mp.find(num[right]) == mp.end() 
                || mp[num[left]] != num[right]) return false;
            left++; right--;
        }
        return true;
    }

private:
    unordered_map<char, char> mp;
    
};
