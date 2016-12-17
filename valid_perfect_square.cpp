class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 0) return false;
        int root = mySqrt(num);
        return root * root == num;
    }

private:
    int mySqrt(int num) {
        if (num <= 0) return 0;
        long long target = num, left = 1, right = num;
        while (left <= right) {
            long long mid = left + (right-left)/2;
            if (mid*mid <= target && (mid+1)*(mid+1) > target) return mid;
            
            if (mid*mid < target) left = mid+1;
            else right = mid-1;
        }
        return 0;
    }
};
