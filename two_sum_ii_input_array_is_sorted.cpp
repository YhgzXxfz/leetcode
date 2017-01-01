class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int left = 0, right = numbers.size()-1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                result.emplace_back(left+1);
                result.emplace_back(right+1);
                return result;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};
