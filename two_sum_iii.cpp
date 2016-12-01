class TwoSum {
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    mp[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (auto entry : mp) {
	        int key = value - entry.first;
	        if (mp.find(key) != mp.end()) {
	            if (entry.first != key) return true;
	            else if (mp[key] >= 2) return true;
	        }
	    }
	    return false;
	}
	
private:
    unordered_map<int, int> mp;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
