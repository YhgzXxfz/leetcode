class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> result;
        if (people.empty()) return result;
        
	auto comp = [&](pair<int,int> a, pair<int,int> b) {
		return a.first == b.first ? a.second < b.second : a.first > b.first;
	};
        sort(people.begin(), people.end(), comp);
        
        for (int i = 0; i < people.size(); ++i) {
            result.insert(result.begin()+people[i].second, people[i]);
        }
        return result;
    }

};
