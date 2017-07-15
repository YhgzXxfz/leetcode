class LogSystem {
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        mp[timestamp].insert(id);
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        vector<int> result;
        for (auto entry : mp) {
            string timestamp = entry.first;
	    int index;

            if (gra == "Year") index = 4;
            else if (gra == "Month") index = 7;
            else if (gra == "Day") index = 10;
            else if (gra == "Hour") index = 13;
            else if (gra == "Minute") index = 16;
            else if (gra == "Second") index = 19;

            string start = s, end = e, t = timestamp;
            if (t >= start && t <= end) {
                for (auto id : entry.second) result.push_back(id);
            }
        }
        return result;
    }

private:
    unordered_map<string, unordered_set<int>> mp;
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
