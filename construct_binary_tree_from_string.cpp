/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty()) return nullptr;
        
        int index = s.find_first_of('(');
        if (index == string::npos) return new TreeNode(stoi(s));
        
        auto root = new TreeNode(stoi(s.substr(0, index)));
        
        int len = s.size(), l_begin = index+1, l_end = getLeftEnd(s, index);
        root->left = str2tree(s.substr(l_begin, l_end - l_begin));
        int r_begin = l_end+2;
        root->right = l_end == len-1 ? nullptr : str2tree(s.substr(r_begin, len-1 - r_begin));
        return root;
    }

private:
    int getLeftEnd(string s, int first_left_paren) {
        int len = s.size(), i, left = 0, right = 0;
        for (i = first_left_paren; i < len; ++i) {
            if (s[i] == '(') left++;
            else if (s[i] == ')') right++;
            
            if (left == right) break;
        }
        return i;
    }
};
