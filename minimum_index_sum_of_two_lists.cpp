class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_set<string> st1(list1.begin(), list1.end()), st2(list2.begin(), list2.end());
        vector<string> commons;
        for (auto choice : st1) {
            if (st2.count(choice)) commons.push_back(choice);
        }
        
        unordered_map<string, int> mp;
        int min_sum = INT_MAX;
        for (auto choice : commons) {
            int id1 = find(list1.begin(), list1.end(), choice) - list1.begin();
            int id2 = find(list2.begin(), list2.end(), choice) - list2.begin();
            int id_sum = id1+id2;
            
            mp[choice] = id_sum;
            min_sum = min(min_sum, id_sum);
        }
        
        vector<string> result;
        for (auto entry : mp) {
            if (entry.second == min_sum) result.push_back(entry.first);
        }
        return result;
    }
};
