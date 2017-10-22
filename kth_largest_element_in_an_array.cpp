// O(NlogN), O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};

// O(NlogN), O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++)
            pq.pop(); 
        return pq.top();
    }
};

// O(NlogK), O(K)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto num : nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

// O(N), O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k-1) return nums[pos];
            else if (pos > k-1) right = pos-1;
            else left = pos+1;
        }
    }

private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int i = right;
        while (i >= left) {
            if (nums[i] < pivot) swap(nums[right--], nums[i--]);
            else if (nums[i] == pivot) i--;
            else swap(nums[i], nums[left++]);
        }
        return right;
    }
};

// O(N), O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k-1) return nums[pos];
            else if (pos > k-1) right = pos-1;
            else left = pos+1;
        }
    }

private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left+1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) swap(nums[l++], nums[r--]);
            else {
                if (nums[l] >= pivot) ++l;
                if (nums[r] <= pivot) --r;
            }
        }
        swap(nums[left], numr[r]);
        return r;
    }
};
