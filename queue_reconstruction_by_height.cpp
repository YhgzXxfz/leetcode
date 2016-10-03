class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int len = people.size();
        vector<pair<int, int>> result;
        if (len == 0) return result;
        
        sort(people.begin(), people.end(), comp);
        
        for (int i = 0; i < len; ++i) {
            result.insert(result.begin()+people[i].second, people[i]);
        }
        return result;
    }

private:
    static bool comp(pair<int, int> & a, pair<int, int> & b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};
