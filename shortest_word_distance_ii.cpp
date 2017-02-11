class WordDistance {
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); ++i) {
            mp[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        auto indexes1 = mp[word1], indexes2 = mp[word2];
        int min_dist = INT_MAX;
        int p1 = 0, p2 = 0, len1 = indexes1.size(), len2 = indexes2.size();
        while (p1 < len1 && p2 < len2) {
            min_dist = min(min_dist, abs(indexes1[p1] - indexes2[p2]));
            if (indexes1[p1] < indexes2[p2]) p1++;
            else p2++;
        }
        return min_dist;
    }

private:
    unordered_map<string, vector<int>> mp;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
