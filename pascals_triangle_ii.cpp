class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // t-O(N^2), m-O(1)
        if (rowIndex == 0) return {1};
        
        int len = rowIndex+1;
        vector<int> curr(len);
        curr[0] = curr[len-1] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = len-2; j >= 1; --j) {
                curr[j] = curr[j-1]+curr[j];
            }
        }
        return curr;
        
        // t-O(N^2), m-O(N)
        /*
        vector<int> prev, curr(1,1);
        if (rowIndex == 0) return curr;
        
        for (int i = 1; i <= rowIndex; ++i) {
            prev = curr;
            
            int len = i+1;
            curr.resize(len);
            curr[0] = curr[len-1] = 1;
            for (int j = 1; j < len-1; ++j) {
                curr[j] = prev[j-1]+prev[j];
            }
        }
        return curr;
        */
    }
};
