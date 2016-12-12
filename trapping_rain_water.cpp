class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int left = 0, right = height.size()-1;
        int max_left = 0, max_right = 0;
        int result = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= max_left) max_left = height[left];
                else result += max_left-height[left];
                ++left;
            } else {
                if (height[right] >= max_right) max_right = height[right];
                else result += max_right-height[right];
                --right;
            }
        }
        return result;
    }
};
