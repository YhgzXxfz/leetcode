class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int h = min(height[left], height[right]);
            water = max(water, (right-left) * h);
            
            while (height[left] <= h && left < right) left++;
            while (height[right] <= h && left < right) right--;
        }
        return water;
    }
};
