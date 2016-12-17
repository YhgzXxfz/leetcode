class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();

        vector<int> T(len, 0);
        vector<int> parent(len, 0);

        int m = 0, mi = 0;

        for(int i = len - 1; i >= 0; --i) {
            for(int j = i; j < len; ++j) {
                if(nums[j] % nums[i] == 0 && T[i] < 1 + T[j]) {
                    T[i] = 1 + T[j];
                    parent[i] = j;

                    if(T[i] > m) {
                        m = T[i];
                        mi = i;
                    }
                }
            }
        }

        vector<int> result;
        for(int i = 0; i < m; ++i) {
            result.push_back(nums[mi]);
            mi = parent[mi];
        }

        return result;
    }
};
