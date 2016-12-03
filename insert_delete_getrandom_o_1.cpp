class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        data.emplace_back(val);
        mp[val] = data.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        int index = mp[val];
        data[index] = data[data.size()-1];
        mp[data[index]] = index;
        data.pop_back();
        mp.erase(mp.find(val));
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return data[rand() % data.size()];
    }
    
private:
    unordered_map<int, int> mp;
    vector<int> data;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
