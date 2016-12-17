class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        int size = (int) A.size();
        for (int i = 0; i < size - 1; i++) {
            A[i] = A[i+1] - A[i];
        }
        A.resize(size-1);
        size--;
        
        int result = 0;
        int len = 1;
        for (int i = 1; i < size; i++) {
            if (A[i] != A[i-1]) {
                result += len*(len-1) / 2;
                len = 1;
            } else {
                len++;
            }
        }
        if (len > 1) result += len*(len-1) / 2;
        return result;
    }
};
