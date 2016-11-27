class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> strobs;
        if (n&1) strobs = {"0", "1", "8"};
        else strobs = {""};
        vector<string> base = {"00", "11", "69", "88", "96"};
        int m = base.size();
        
        while (n > 1) {
            n -= 2;
            vector<string> temp;
            for (auto str : strobs) {
                for (int i = (n < 2) ? 1 : 0; i < m; ++i) {
                    temp.emplace_back(base[i].substr(0,1) + str + base[i].substr(1));
                }
            }
            swap(temp, strobs);
        }
        return strobs;
    }
};
