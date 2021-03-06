class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> result;
        for (int i = max(k-n, 0); i <= min(k, m); ++i) {
            result = max(result, merge(maxArray(nums1, i), maxArray(nums2, k-i)));
        }
        return result;
    }

private:
    vector<int> maxArray(vector<int> nums, int k) {
        int drop = nums.size()-k;
        vector<int> out;
        for (int num : nums) {
            while (drop > 0 && !out.empty() && out.back() < num) {
                out.pop_back();
                drop--;
            }
            out.push_back(num);
        }
        out.resize(k);
        return out;
    }

    vector<int> merge(vector<int> nums1, vector<int> nums2) {
        vector<int> out;
        while (nums1.size() > 0 || nums2.size() > 0) {
            vector<int>& now = nums1 > nums2 ? nums1 : nums2;
            out.push_back(now[0]);
            now.erase(now.begin());
        }
        return out;
    }
};


class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> result(k, 0);
        for (int i = max(0, k-n); i <= m && i <= k; ++i) {
            vector<int> candidate = merge(maxArray(nums1, i), maxArray(nums2, k-i), k);
            if (greater(candidate, 0, result, 0)) result = candidate;
        }
        return result;
    }
    
private:
    vector<int> merge(vector<int> nums1, vector<int> nums2, int k) {
        vector<int> result (k, 0);
        int i = 0, j = 0;
        for (int r = 0; r < k; ++r) {
            if (greater(nums1, i, nums2, j)) result[r] = nums1[i++];
            else result[r] = nums2[j++];
        }
        return result;
    }
    
    bool greater(vector<int> nums1, int i, vector<int> nums2, int j) {
        int m = nums1.size(), n = nums2.size();
        while (i < m && j < n && nums1[i] == nums2[j]) {
            ++i; ++j;
        }
        return j == n || (i < m && nums1[i] > nums2[j]);
    }
    
    vector<int> maxArray(vector<int> nums, int k) {
        int len = nums.size(), left = 0;
        vector<int> result (k, 0);
        for (int i = 0; i < len; ++i) {
            while (len-i +left > k && left > 0 && result[left-1] < nums[i]) --left;
            if (left < k) result[left++] = nums[i];
        }
        return result;
    }
};
