// priority queue (insert sort)
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int len = nums.size();
        priority_queue<pair<int,int> > pq;
        for (int i = 0; i < len; ++i) {
            pq.push(make_pair(nums[i],i));
        }
        
        vector<string> result(len);
        int rank = 1;
        for (int i = 0; i < len; ++i) {
            result[pq.top().second] = (rank <= 3) ? getTopThree(rank) : to_string(rank);
            rank++;
            pq.pop();
        }
        return result;
    }

private:
    string getTopThree(int rank) {
        return 1 == rank ? "Gold Medal" : 2 == rank ? "Silver Medal" : "Bronze Medal";
    }
};



// sort
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < len; ++i) {
            mp[nums[i]] = i;
        }
        
        sort(nums.begin(), nums.end());
        vector<string> result(len);
        for (int i = 0; i < len; ++i) {
            int rank = len-i;
            result[mp[nums[i]]] = rank <= 3 ? getTopThree(rank) : to_string(rank);
        }
        return result;
    }

private:
    string getTopThree(int rank) {
        return 1 == rank ? "Gold Medal" : 2 == rank ? "Silver Medal" : "Bronze Medal";
    }
};
