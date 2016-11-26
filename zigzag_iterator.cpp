class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        begin[0] = v1.begin(); end[0] = v1.end();
        begin[1] = v2.begin(); end[1] = v2.end();
        flag = 0;
    }

    int next() {
        int value;
        if (begin[0] == end[0]) value = *begin[1]++;
        else if (begin[1] == end[1]) value = *begin[0]++;
        else {
            value = *begin[flag]++;
            flag = (flag+1)%2;
        }
        return value;
    }

    bool hasNext() {
        return begin[0] != end[0] || begin[1] != end[1];
    }

private:
    vector<int>::iterator begin[2], end[2];
    int flag;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
