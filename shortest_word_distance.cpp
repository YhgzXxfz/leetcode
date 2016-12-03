class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int min_dist = INT_MAX, index1 = -1, index2 = -1;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) index1 = i;
            if (words[i] == word2) index2 = i;
            if (index1 != -1 && index2 != -1) min_dist = min(min_dist, abs(index1-index2));
        }
        return min_dist;
    }
};
