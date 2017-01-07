class Solution {
public:
    int numWays(int n, int k) {
	if (n == 0) return 0;
	if (n == 1) return k;

	int same = k, diff = k*(k-1);
	for (int i = 2; i < n; ++i) {
		int temp = diff;
		diff = (k-1)*(same+diff);
		same = temp*1;
	}
	return same+diff;
    }
};
