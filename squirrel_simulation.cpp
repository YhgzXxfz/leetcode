class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        vector<int> tree_nuts, squirrel_nuts;
        for (auto nut : nuts) {
            tree_nuts.push_back(manhattan(nut, tree));
            squirrel_nuts.push_back(manhattan(nut, squirrel));
        }
        int max_diff = INT_MIN;
        for (int i = 0; i < nuts.size(); ++i) {
            max_diff = max(max_diff, tree_nuts[i]-squirrel_nuts[i]);
        }
        
        return 2*accumulate(tree_nuts.begin(), tree_nuts.end(), 0) - max_diff;
    }

private:
    int manhattan(vector<int>& nut, vector<int>& obj) {
        return abs(nut[0]-obj[0]) + abs(nut[1]-obj[1]);
    }
};
