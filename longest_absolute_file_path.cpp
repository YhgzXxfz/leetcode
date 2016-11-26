class Solution {
public:
    int lengthLongestPath(string input) {
        int max_length = 0, count = 0, depth = 0;
        vector<int> dirs;
        bool is_file = false;
        
        input += "\n";
        for (char c: input) {
            if (c == '\n') {
                if (is_file) {
                    max_length = max(max_length, (depth > 0 ? dirs[depth-1] : 0) + count);
                } else {
                    if (depth >= dirs.size()) dirs.push_back(0);
                    dirs[depth] = (depth > 0 ? dirs[depth-1] : 0) + count + 1;
                }
                is_file = false;
                count = 0;
                depth = 0;
            } else if (c == '\t') {
                ++depth;
            } else {
                ++count;
                if (c == '.') is_file = true;
            }
        }
        return max_length;
    }
};
