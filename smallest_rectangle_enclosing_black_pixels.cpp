class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        matrix = image;
        int m = matrix.size(), n = matrix[0].size();
        int top = search(0, x, 0, n, true, true);
        int bottom = search(x+1, m, 0, n, false, true);
        int left = search(0, y, top, bottom, true, false);
        int right = search(y+1, n, top, bottom, false, false);
        return (right-left)*(bottom-top);
    }

private:
    int search(int i, int j, int low, int high, bool opt, bool is_row) {
        while (i < j) {
            int k = low, mid = (i+j)>>1;
            while (k < high && isWhite(mid, k, is_row)) k++;
            if (k < high == opt) j = mid;
            else i = mid+1;
        }
        return i;
    }
    
    bool isWhite(int mid, int k, bool is_row) {
        return (is_row ? matrix[mid][k] : matrix[k][mid]) == '0';
    }
    vector<vector<char>> matrix;
};
