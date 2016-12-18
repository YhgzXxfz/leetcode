class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        long len = points.size(), prev = 0, curr;
        for (int i = 0; i < len; ++i) {
            vector<vector<int>> A;
            A.push_back({points[(i+1)%len][0]-points[i][0], points[(i+1)%len][1]-points[i][1]});
            A.push_back({points[(i+2)%len][0]-points[i][0], points[(i+2)%len][1]-points[i][1]});
            if (curr = det2(A)) {
                if (curr*prev < 0) return false; 
                else prev = curr;
            }
        }
        return true;
    }

private:
    long det2(vector<vector<int>>& A) {
        return A[0][0]*A[1][1] - A[0][1]*A[1][0];
    }
};
