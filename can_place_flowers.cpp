class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        auto allones = constructAllOnes(flowerbed);
        return computeCountByAllOnes(allones) >= n;
    }

private:
    vector<int> constructAllOnes(vector<int>& flowerbed) {
        vector<int> allones;
        int len = flowerbed.size();
        for (int i = 0; i < len; ++i) {
            if (flowerbed[i] == 1) allones.push_back(i);
        }
        
        allones.insert(allones.begin(), -2);
        allones.push_back(len+1);
        return allones;
    }
    
    int computeCountByAllOnes(vector<int>& allones) {
        int count = 0;
        for (int i = 0; i < allones.size()-1; ++i) {
            count += max((allones[i+1]-allones[i])/2-1, 0);
        }
        return count;
    }
};
