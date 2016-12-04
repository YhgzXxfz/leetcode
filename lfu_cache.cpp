class LFUCache {
public:
    LFUCache(int capacity):_capacity(capacity), size(0) {
        
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        
        int value = cache[key].first, frequency = cache[key].second;
        f[frequency].erase(iter[key]);
        
        frequency++;
        cache[key].second = frequency;
        f[frequency].push_back(key);
        iter[key] = --f[frequency].end();
        
        if (f[min_freq].size() == 0) min_freq = frequency;
        
        return value;
    }
    
    void set(int key, int value) {
        if (_capacity <= 0) return;
        
        
        if (get(key) != -1) {
            cache[key].first = value;
            return ;
        }
        
        if (size >= _capacity) {
            cache.erase(f[min_freq].front());
            iter.erase(f[min_freq].front());
            f[min_freq].pop_front();
            size--;
        }
        
        cache[key] = make_pair(value, 1);
        f[1].push_back(key);
        iter[key] = --f[1].end();
        min_freq = 1;
        size++;
    }

private:
    int _capacity, size, min_freq;
    unordered_map<int, pair<int, int>> cache;
    unordered_map<int, list<int>> f;
    unordered_map<int, list<int>::iterator> iter;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.set(key,value);
 */
