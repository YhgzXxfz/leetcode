class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        row_begin = vec2d.begin();
        row_end = vec2d.end();
        while (row_begin != row_end && row_begin->empty()) ++row_begin;
        if (row_begin != row_end) col = row_begin->begin();
    }

    int next() {
        int value = *col;
        col++;
        if (col == row_begin->end()) {
            row_begin++;
            while (row_begin != row_end && row_begin->empty()) ++row_begin;
            if (row_begin != row_end) col = row_begin->begin();
        }
        return value;
    }

    bool hasNext() {
        return row_begin != row_end;
    }

private:
    vector<int>::iterator col;
    vector<vector<int>>::iterator row_begin, row_end;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
