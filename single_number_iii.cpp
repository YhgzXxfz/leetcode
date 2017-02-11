class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) {
            sum ^= num;
        }
        int index = findFirstDiff(sum);
        int num1 = sum, num2 = sum;
        for (auto num : nums) {
            if ((num>>index) & 1) num1 ^= num;
            else num2 ^= num;
        }
        return {num1, num2};
    }

private:
    int findFirstDiff(int n) {
        for (int i = 31; i >= 0; --i) {
            if ((n>>i) & 1) return i;
        }
        return 0;
    }
};
