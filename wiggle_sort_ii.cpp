class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // 1 t-O(NlogN), m-O(N)
        /*
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        
        for (int i = nums.size()-1, j = 0, k = i/2+1; i >= 0; --i) {
            nums[i] = sorted[(i&1) ? k++ : j++];
        }
        */
        
        // 2 t-O(N), m-O(1);
        int n = nums.size();
    
        // Find a median.
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        // Index-rewiring.
        #define A(i) nums[(1+2*(i)) % (n|1)]
    
        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid) swap(A(i++), A(j++));
            else if (A(j) < mid) swap(A(j), A(k--));
            else j++;
        }
    }
};
