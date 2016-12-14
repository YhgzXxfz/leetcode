class Solution {
public:
    bool isValidSerialization(string preorder) {
        int len = preorder.size();
        
        int degree = 1;
        for (int i = 0; i < len; ++i) {
            if (preorder[i] == ',') continue;
            
            --degree;
            if (degree < 0) return false;
            if (preorder[i] != '#') degree += 2;
            
            // "9,#,92,#,#", move to the last number of non-null node
            while (preorder[i] != ',' && i < len) i++;
            i--;
        }
        return 0 == degree;
    }
};
