class Solution {
public:
    string originalDigits(string s) {
        int count[10] = {};
        for (char c : s) { 
            switch (c) {
                case 'z': count[0]++; break;
                case 'w': count[2]++; break;
                case 'u': count[4]++; break;
                case 'x': count[6]++; break;
                case 'g': count[8]++; break;
                case 'o': count[1]++; break;
                case 'r': count[3]++; break;
                case 'f': count[5]++; break;
                case 'v': count[7]++; break;
                case 'i': count[9]++; break;
            }
        }
        
        count[1] -= (count[0]+count[2]+count[4]);
        count[3] -= (count[0]+count[4]);
        count[5] -= count[4];
        count[7] -= count[5];
        count[9] -= (count[5]+count[6]+count[8]);
        
        string result = "";
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < count[i]; ++j) {
                result += ('0' + i);
            }
        }
        return result;
    }
};
