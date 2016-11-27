class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if ((nums1.size() + nums2.size())%2 == 1)
            return findKthInTwoSortedArrays(nums1,nums2, (nums1.size()+nums2.size())/2 +1);
        else
            return (findKthInTwoSortedArrays(nums1,nums2, (nums1.size()+nums2.size())/2)
                + findKthInTwoSortedArrays(nums1,nums2, (nums1.size()+nums2.size())/2 +1)) / 2.0;
    }
    
    int findKthInTwoSortedArrays
        (const vector<int>& A, const vector<int>& B, int k) {
        int m = A.size(), n = B.size();

        // Make sure m is the smaller one.
        if (m > n) return findKthInTwoSortedArrays(B, A, k);

        int left = 0;
        int right = m;
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
