// two multisets
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        multiset<int> lo, hi;
    
        for (int i = 0; i < nums.size(); ++i) {
            //remove outgoing element
            if (i >= k) {
                if (nums[i-k] <= *lo.rbegin()) lo.erase(lo.find(nums[i-k]));
                else hi.erase(hi.find(nums[i-k]));
            }
    
            // insert incoming element
            lo.insert(nums[i]);
    
            // balance the sets
            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));
    
            if (lo.size() < hi.size()) {
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }
    
            // get median
            if (i >= k - 1) {
                medians.push_back(k & 1 ? *lo.rbegin() : ((double)(*lo.rbegin()) + (double)(*hi.begin())) * 0.5);
            }
        }
    
        return medians;
    }
};


// one multiset
/*
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        vector<double> medians;
        for (int i = k; ; i++) {
    
            // Push the current median.
            medians.push_back((double(*mid) + *next(mid, k%2 - 1)) / 2);
    
            // If all done, return.
            if (i == nums.size()) return medians;
                
            // Insert nums[i].
            window.insert(nums[i]);
            if (nums[i] < *mid) mid--;
    
            // Erase nums[i-k].
            if (nums[i-k] <= *mid) mid++;
            window.erase(window.lower_bound(nums[i-k]));
        }
    }
};
*/
