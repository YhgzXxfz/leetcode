class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (strmap.find(key) == strmap.end()) {
            if (matrix.empty() || matrix.back().val != 1) {
                auto newrow = matrix.emplace(matrix.end(), key, 1);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            }
            else {
                auto newrow = --matrix.end();
                newrow->strs.push_front(key);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            }
        }
        else {
            auto row = strmap[key].first;
            auto col = strmap[key].second;
            auto lastrow = row;
            --lastrow;
            if (lastrow == matrix.end() || lastrow->val != row->val + 1) {
                auto newrow = matrix.emplace(row, key, row->val + 1);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            }
            else {
                auto newrow = lastrow;
                newrow->strs.push_front(key);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            }
            row->strs.erase(col);
            if (row->strs.empty()) matrix.erase(row);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (strmap.find(key) == strmap.end()) {
            return;
        }
        else {
            auto row = strmap[key].first;
            auto col = strmap[key].second;
            if (row->val == 1) {
                row->strs.erase(col);
                if (row->strs.empty()) matrix.erase(row);
                strmap.erase(key);
                return;
            }
            auto nextrow = row;
            ++nextrow;
            if (nextrow == matrix.end() || nextrow->val != row->val - 1) {
                auto newrow = matrix.emplace(nextrow, key, row->val - 1);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            }
            else {
                auto newrow = nextrow;
                newrow->strs.push_front(key);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            }
            row->strs.erase(col);
            if (row->strs.empty()) matrix.erase(row);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return matrix.empty() ?  "" : matrix.front().strs.front();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return matrix.empty() ?  "" : matrix.back().strs.front();
    }
    
private:
    struct Row {
        list<string> strs;
        int val;
        Row(const string &s, int x) : strs({s}), val(x) {}
    };

    unordered_map<string, pair<list<Row>::iterator, list<string>::iterator>> strmap;
    list<Row> matrix;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
