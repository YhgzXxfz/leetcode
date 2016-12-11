class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // 1 brute search
        /*
        vector<int> result;
        if (nums1.empty() || nums2.empty()) return result;
        
        for (auto candidate : nums1) {
            auto is_exist = find(nums2.begin(), nums2.end(), candidate);
            if (is_exist != nums2.end()) {
                result.push_back(candidate);
                nums2.erase(is_exist);
            }
        }
        return result;
        */
        
        // sort + two pointers
        vector<int> result;
        if (nums1.empty() || nums2.empty()) return result;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        auto p1 = nums1.begin(), p2 = nums2.begin();
        while (p1 != nums1.end() && p2 != nums2.end()) {
            if (*p1 == *p2) {
                result.push_back(*p1);
                p1++; p2++;
            } else if (*p1 < *p2) {
                p1++;
            } else {
                p2++;
            }
        }
        return result;
    }
};
