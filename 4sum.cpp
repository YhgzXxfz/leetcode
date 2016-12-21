class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> result;
        if (len < 4) return result;
        
        sort(nums.begin(), nums.end());
        vector<int> quadruplet(4, 0);
        for (int i = 0; i < len-3; ++i) {
            if (i == 0 || i > 0 && nums[i] != nums[i-1]) {
                for (int j = i+1; j < len-2; ++j) {
                    if (j == i+1 || j > i+1 && nums[j] != nums[j-1]) {
                        int left = j+1, right = len-1, target2 = target - nums[i]-nums[j];
                        while (left < right) {
                            int sum = nums[left]+nums[right];
                            if (sum == target2) {
                                quadruplet[0] = nums[i];
                                quadruplet[1] = nums[j];
                                quadruplet[2] = nums[left];
                                quadruplet[3] = nums[right];
                                result.push_back(quadruplet);
                                
                                while (left < right && nums[left] == nums[left+1]) ++left;
                                while (right > left && nums[right] == nums[right-1]) --right;
                                
                                ++left; --right;
                            }
                            else if (sum < target2) ++left;
                            else --right;
                        }
                    }
                }
            }
        }
        return result;
    }
};

