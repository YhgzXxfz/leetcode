class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> st(J.begin(), J.end());
        int count = 0;
        for (auto c : S) {
            if (st.count(c)) ++count;
        }
        return count;
    }
};
