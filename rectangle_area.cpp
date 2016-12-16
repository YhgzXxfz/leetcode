class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int areaABCD = (C-A)*(D-B);
        int areaEFGH = (G-E)*(H-F);
        int areaIntersect = 0;
        
        int left = max(A,E);
        int right = min(C,G);
        int upper = min(D,H);
        int below = max(B,F);
        
        if (left >= right || below >= upper) {
            areaIntersect = 0;
        } else {
            areaIntersect = (right-left) * (upper-below);
        }
        return areaABCD + areaEFGH - areaIntersect;
    }
};
