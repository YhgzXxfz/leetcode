class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (bitCount(h) + bitCount(m) == num) {
                    string hour = to_string(h), minute = m < 10 ? "0"+to_string(m) : to_string(m);
                    result.push_back(hour + ":" + minute);
                }
            }
        }
        return result;
    }

private:
    int bitCount(int num) {
        int digits = 0;
        for (int i = 0; i < 32; ++i) {
            digits += (num & 1);
            num >>= 1;
        }
        return digits;
    }
};
