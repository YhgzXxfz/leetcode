class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.empty()) return true;
        
        stack<int> s;
        int low = INT_MIN;
        for (auto curr : preorder) {
            if (curr < low) return false;
            
            while (!s.empty() && s.top() < curr) {
                low = s.top();
                s.pop();
            }
            s.push(curr);
        }
        return true;
    }
};
