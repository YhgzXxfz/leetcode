// O(1)
class LFUCache {
public:
	LFUCache(int capacity) : _capacity(capacity), size(0), min_occur(0) {}

	int get(int key) {
		auto it = cache.find(key);
		if (it == cache.end()) return -1;

		hit(it);
		return it->second.first;
	}

	void put(int key, int value) {
		if (_capacity <= 0) return ;

		auto it = cache.find(key);
		if (it != cache.end()) {
			hit(it);
			it->second.first = value;
		} else {
			if (size >= _capacity) {
				cache.erase(freq[min_occur].front());
				iter.erase(freq[min_occur].front());
				freq[min_occur].pop_front();
				--size;
			}

			cache[key] = make_pair(value, 1);
			freq[1].push_back(key);
			iter[key] = prev(freq[1].end());
			min_occur = 1;
			++size;
		}
	}

private:
	void hit(unordered_map<int, pair<int, int>>::iterator it) {
		int key = it->first, occur = it->second.second;
		freq[occur].erase(iter[key]);
		it->second.second++;
		freq[it->second.second].push_back(key);
		iter[key] = prev(freq[it->second.second].end());

		if (freq[min_occur].size() == 0) ++min_occur;
	}

	int _capacity, size, min_occur;
	unordered_map<int, pair<int, int>> cache;
	unordered_map<int, list<int>> freq;
	unordered_map<int, list<int>::iterator> iter;
};

// O(N)
class LFUCache {
public:
	LFUCache(int capacity) : _capacity(capacity), size(0), min_occur(0) {}

	int get(int key) {
		auto it = cache.find(key);
		if (it == cache.end()) return -1;

		hit(it);
		return it->second.first;
	}

	void put(int key, int value) {
		if (_capacity <= 0) return ;
		
		auto it = cache.find(key);
		if (it != cache.end()) {
			hit(it);
			it->second.first = value;
		} else {
			if (size >= _capacity) {
				cache.erase(freq[min_occur].front());
				freq[min_occur].pop_front();
				--size;
			}

			cache[key] = make_pair(value, 1);
			freq[1].push_back(key);
			min_occur = 1;
			++size;
		}

	}

private:
	void hit(unordered_map<int, pair<int,int>>::iterator it) {
		int key = it->first, occur = it->second.second;
		freq[occur].remove(key); // O(N)
		it->second.second++;
		freq[it->second.second].push_back(key);

		if (freq[min_occur].size() == 0) ++min_occur;
	}

	int _capacity, size, min_occur;
	unordered_map<int, pair<int, int>> cache;
	unordered_map<int, list<int>> freq;
};
