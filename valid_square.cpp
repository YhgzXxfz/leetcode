class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        int index = farthestToP1(points);
        switch (index) {
            case 2: return isPerpendicular(p1, p2, p3, p4) && isPerpendicular(p1, p3, p1, p4) && isPerpendicular(p2, p3, p2, p4);
            case 3: return isPerpendicular(p1, p3, p2, p4) && isPerpendicular(p1, p2, p1, p4) && isPerpendicular(p3, p2, p3, p4);
            case 4: return isPerpendicular(p1, p4, p2, p3) && isPerpendicular(p1, p2, p1, p3) && isPerpendicular(p4, p2, p4, p3);
        }
        return false;
    }

private:
    int farthestToP1(vector<vector<int>>& points) {
        vector<int> distances, p1 = points[0];
        for (auto p : points) {
            auto v = vector<int> { p[0]-p1[0], p[1]-p1[1] };
            distances.push_back(length(v));
        }
        int max_dis = *max_element(distances.begin(), distances.end());
        for (int i = 0; i < 4; ++i) {
            if (distances[i] == max_dis) return i+1;
        }
    }
    
    int length(vector<int>& v) {
        int x = v[0], y = v[1];
        return x*x + y*y;
    } 
    
    bool isPerpendicular(vector<int>& v1_s, vector<int>& v1_e, vector<int>& v2_s, vector<int>& v2_e) {
        auto v1 = vector<int> { v1_s[0]-v1_e[0], v1_s[1]-v1_e[1] };
        auto v2 = vector<int> { v2_s[0]-v2_e[0], v2_s[1]-v2_e[1] };
        if (length(v1) == 0 || length(v2) == 0) return false;
        int dotproduct = v1[0]*v2[0] + v1[1]*v2[1];
        return dotproduct == 0;
    }
};
