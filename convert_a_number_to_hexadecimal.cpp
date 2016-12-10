class Solution {
public:
    string toHex(int num) {
        if(!num) return "0";
        
        string result = "";
        int count = 0;
        while (num && count < 8) {
            int temp = num & 15;
            if (temp < 10) result.push_back('0'+ temp);
            else result.push_back('a'+temp-10);
            
            num >>= 4;
            count++;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
