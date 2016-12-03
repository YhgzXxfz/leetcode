class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool is_exist = (mp.find(val) != mp.end() && !mp[val].empty());
        mp[val].emplace_back(data.size());
        data.emplace_back(make_pair(val, mp[val].size()-1));
        
        return !is_exist;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool is_exist = (mp.find(val) != mp.end() && !mp[val].empty());
        if (is_exist) {
            auto last = data.back();
            mp[last.first][last.second] = mp[val].back();
            data[mp[val].back()] = last;
            mp[val].pop_back();
            if (mp[val].empty()) mp.erase(val);
            data.pop_back();
        }
        return is_exist;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return data[rand() % data.size()].first;
    }
    
private:
    unordered_map<int, vector<int>> mp;
    vector<pair<int, int>> data;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
