class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
	if ((m+n) &1)
            return getKth(nums1,nums2, (m+n)/2 +1);
        else
            return (getKth(nums1,nums2, (m+n)/2) + getKth(nums1,nums2, (m+n)/2 +1)) / 2.0;
    }
    
private:
    int getKth(const vector<int>& A, const vector<int>& B, int k) {
        int m = A.size(), n = B.size();

        // Make sure m is the smaller one.
        if (m > n) return getKth(B, A, k);

        int left = 0, right = m;
        // Find a partition of A and B
        // where min left s.t. A[left] >= B[k-1 - left]. Thus left is the (k+1)-th element.
        while (left < right) {
            int mid = left + (right-left) / 2;
            if (0 <= k-1 - mid && k-1 - mid < n && A[mid] >= B[k-1 - mid]) right = mid;
            else left = mid + 1;
        }

        int Ai_minus_1 = left-1 >= 0 ? A[left-1] : INT_MIN;
        int Bj = k-1 - left >= 0 ? B[k-1 - left] : INT_MIN;

        // kth element would be A[left-1] or B[k-1 - left].
        return max(Ai_minus_1, Bj);
    }
};
