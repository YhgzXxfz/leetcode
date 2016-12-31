class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplet;
        int len = nums.size();
        if (len < 3) return triplet;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < len-2; ++i) {
            if (i == 0 || i > 0 && nums[i] != nums[i-1]) {
                int left = i+1, right = len-1;
                while (left < right) {
                    int sum = nums[i]+nums[left]+nums[right];
                    if (sum == 0) {
                        triplet.emplace_back(vector<int>({nums[i], nums[left], nums[right]}));
                        
                        while (left < right && nums[left] == nums[left+1]) left++;
                        while (right > left && nums[right] == nums[right-1]) right--;
                        
                        left++; right--;
                    } else if (sum < 0) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return triplet;
    }
};
