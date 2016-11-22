class Solution {
public:
    int bulbSwitch(int n) {
        if (n <= 0) return 0;
        
        int count = 0;
        while (count*count <= n) {
            count++;
        }
        return count-1;
    }
};
