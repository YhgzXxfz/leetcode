// O(1)
class LRUCache {
public:
    LRUCache(int capacity):_capacity(capacity){}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        
        hit(it);
        
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) hit(it);
        
        else {
            if (cache.size() >= _capacity) {
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        
        cache[key] = make_pair(value, used.begin());
    }

private:
    int _capacity;
    list<int> used;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    
    
    void hit(unordered_map<int, pair<int, list<int>::iterator>>::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
};


// O(N)
class LRUCache {
public:
	LRUCache(int capacity) : _capacity(capacity) {}

	int get(int key) {
		auto it = cache.find(key);
		if (it == cache.end()) return -1;

		hit(it);
		return it->second;
	}

	void put(int key, int value) {
		auto it = cache.find(key);
		if (it != cache.end()) hit(it);
		else {
			if (cache.size() >= _capacity) {
				cache.erase(used.back());
				used.pop_back();
			}
			used.push_front(key);
		}
		cache[key] = value;
	}

private:
	void hit(unordered_map<int, int>::iterator it) {
		used.remove(it->first); // O(N)
		used.push_front(it->first);
	}

	int _capacity;
	list<int> used;
	unordered_map<int, int> cache;
};
