class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.empty()) return false;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum &3) return false;
        
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end()); // larger first => fail first
        vector<int> sides(4,0);
        return dfs(nums, 0, sides, sum/4);
    }

private:
    bool dfs(vector<int>& nums, int start, vector<int>& sides, int edge) {
        if (start >= nums.size()) {
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }
        
        for (int i = 0; i < 4; ++i) {
            if (sides[i]+nums[start] > edge) continue; // larger first => fail first
            
            int j = i-1;
            while (j >= 0) {
                if (sides[j--] == sides[i]) break;
            }
            if (j != -1) continue;
            
            sides[i] += nums[start];
            if (dfs(nums, start+1, sides, edge)) return true;
            sides[i] -= nums[start];
        }
        return false;
    }
};
