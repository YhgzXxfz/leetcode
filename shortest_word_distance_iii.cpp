class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int min_dist = INT_MAX, index1 = -1, index2 = -1;
        for (int i = 0; i < words.size(); ++i) {
            if (word1 == word2) {
                if (words[i] == word1) {
                    if (index1 > index2) index2 = i;
                    else index1 = i;
                }
            } else {
                if (words[i] == word1) index1 = i;
                if (words[i] == word2) index2 = i;
            }
            if (index1 != -1 && index2 != -1) min_dist = min(min_dist, abs(index1-index2));
        }
        return min_dist;
    }
};
