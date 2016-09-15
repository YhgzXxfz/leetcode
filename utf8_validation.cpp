class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int len = data.size();
        int i = 0;
        
        while (i < len) {
            if (!flag) return false;
            if ((data[i] & mask[4]) == mask[3] && i+3 < len) {
                checkRest(data, i, 3);
            } else if ((data[i] & mask[3]) == mask[2] && i+2 < len) {
                checkRest(data, i, 2);
            } else if ((data[i] & mask[2]) == mask[1] && i+1 < len) {
                checkRest(data, i, 1);
            } else if ((data[i] & mask[0]) == 0) {
                i++;
            } else {
                return false;
            }
        }
        return true;
    }
    
private:
    void checkRest(vector<int> & data, int & first, int last) {
        for (int i = 1; i <= last; ++i) {
            if ((data[first+i] & mask[1]) != mask[0]) {
                flag = false;
                return;
            }
        }
        first += last+1;
    }
    
    bool flag = true;
    vector<int> mask = {128, 192, 224, 240, 248};
};
