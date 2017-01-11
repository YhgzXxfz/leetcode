class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        
        string result = "1";
        while (--n) {
            string curr = "";
            int len = result.size();
            for (int i = 0; i < len; i++) {
                int count = 1;
                 while (i < len-1 && result[i] == result[i+1]){
                    count++;    
                    i++;
                }
                curr += to_string(count) + result[i];
            }
            result = curr;
        }
        return result;
    }
};
