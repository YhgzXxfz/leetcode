class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size(), area = 0;
        stack<int> s;
        for (int i = 0; i <= len; ++i) {
            int h = (i == len) ? 0 : heights[i];
            if (s.empty() || h >= heights[s.top()]) s.push(i);
            else {
                int tp = s.top();
                s.pop();
                area = max(area, heights[tp] * (s.empty() ? i : i-1 - s.top()));
                i--;
            }
        }
        return area;
    }
};


/*
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.emplace_back(0);
        int len = height.size(), area = 0;
        stack<int> indexes;
        
        for (int i = 0; i < len; i++) {
            while (!indexes.empty() && height[indexes.top()] > height[i]) {
                int h = height[indexes.top()]; 
                indexes.pop();
                int left = indexes.empty() ? -1 : indexes.top();
                area = max(area, h * (i - left - 1));
            }
            indexes.push(i);
        }
        return area; 
    }
};
*/
