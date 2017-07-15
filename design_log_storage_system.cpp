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
            if (gra == "Year") {
                string start_year = s.substr(0,4), end_year = e.substr(0,4), t = timestamp.substr(0,4);
                if (t >= start_year && t <= end_year) {
                    for (auto id : entry.second) result.push_back(id);
                }
            } else if (gra == "Month") {
                string start_month = s.substr(0,7), end_month = e.substr(0,7), t = timestamp.substr(0,7);
                if (t >= start_month && t <= end_month) {
                    for (auto id : entry.second) result.push_back(id);
                }
            } else if (gra == "Day") {
                string start_day = s.substr(0,10), end_day = e.substr(0,10), t = timestamp.substr(0,10);
                if (t >= start_day && t <= end_day) {
                    for (auto id : entry.second) result.push_back(id);
                }
            } else if (gra == "Hour") {
                string start_hour = s.substr(0,13), end_hour = e.substr(0,13), t = timestamp.substr(0,13);
                if (t >= start_hour && t <= end_hour) {
                    for (auto id : entry.second) result.push_back(id);
                }
            } else if (gra == "Minute") {
                string start_minute = s.substr(0,16), end_minute = e.substr(0,16), t = timestamp.substr(0,16);
                if (t >= start_minute && t <= end_minute) {
                    for (auto id : entry.second) result.push_back(id);
                }
            } else if (gra == "Second") {
                string start_second = s, end_second = e, t = timestamp;
                if (t >= start_second && t <= end_second) {
                    for (auto id : entry.second) result.push_back(id);
                }
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
