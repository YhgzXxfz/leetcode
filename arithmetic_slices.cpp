class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int result = 0, curr = 0;
	for (int i = 2; i < A.size(); ++i) {
		if (A[i]-A[i-1] == A[i-1]-A[i-2]) {
			curr++;
			result += curr;
		} else {
			curr = 0;
		}
	}
	return result;
    }
};
