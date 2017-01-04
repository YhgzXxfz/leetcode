class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        
        int min_radius = 0;
        for (auto house : houses) {
            auto larger = lower_bound(heaters.begin(), heaters.end(), house);
            int curr = INT_MAX;
            if (larger != heaters.end()) curr = *larger-house;
            if (larger != heaters.begin()) curr = min(curr, house- *(larger-1));
            min_radius = max(min_radius, curr);
        }
        return min_radius;
    }
};
