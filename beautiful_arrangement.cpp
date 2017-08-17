class Solution {
public:
    int countArrangement(int N) {
        vector<int> visited(N+1, 0);
        int pos = 1, count = 0;
        dfs(N, pos, visited, count);
        return count;
    }

private:
    void dfs(int N, int pos, vector<int>& visited, int& count) {
        if (pos > N) count++;
        
        for (int i = 1; i <= N; ++i) {
            if (!visited[i] && (i%pos == 0 || pos%i == 0)) {
                visited[i] = true;
                dfs(N, pos+1, visited, count);
                visited[i] = false;
            }
        }
    }
};


// swap
class Solution {
public:
    int countArrangement(int N) {
        vector<int> nums;
        for (int i = 0; i < N; ++i) nums.push_back(i+1);
        return dfs(N, nums);
    }

private:
    int dfs(int end, vector<int>& nums) {
        if (end <= 0) return 1;
        
        int result = 0;
        for (int i = 0; i < end; ++i) {
            if (nums[i] % end == 0 || end % nums[i] == 0) {
                swap(nums[i], nums[end-1]);
                result += dfs(end-1, nums);
                swap(nums[i], nums[end-1]);
            }
        }
        return result;
    }
};
