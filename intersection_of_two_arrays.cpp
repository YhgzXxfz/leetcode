class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 1 brute search O(N*N)
        /*
        vector<int> result;
        if (nums1.empty() || nums2.empty()) return result;
        
        for (auto candidate : nums1) {
            if (find(result.begin(), result.end(), candidate) == result.end()
                && find(nums2.begin(), nums2.end(), candidate) != nums2.end()) {
                    result.push_back(candidate);
                }
        }
        return result;
        */
        
        // 2 sort + two pointers O(NlogN)
        /*
        vector<int> result;
        if (nums1.empty() || nums2.empty()) return result;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        unordered_set<int> nums;
        auto p1 = nums1.begin(), p2 = nums2.begin();
        while (p1 != nums1.end() && p2 != nums2.end()) {
            if (*p1 == *p2) {
                nums.insert(*p1);
                p1++; p2++;
            }
            else if (*p1 < *p2) p1++;
            else p2++;
        }
        
        for (auto num : nums) result.push_back(num);
        return result;
        */
        
        // 3 set
        vector<int> result;
        if (nums1.empty() || nums2.empty()) return result;
        
        unordered_set<int> nums(nums1.begin(), nums1.end());
        for (auto candidate : nums2) {
            if (nums.count(candidate)) {
                result.push_back(candidate);
                nums.erase(candidate);
            }
        }
        return result;
    }
};
