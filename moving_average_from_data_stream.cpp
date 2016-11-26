// 1 t-O(1), m-O(n)
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size):_size(size) {
        
    }
    
    double next(int val) {
        data.push_back(val);
        sum += val;
        if (data.size() > _size) {
            sum -= data.front();
            data.pop_front();
        }
        return sum / data.size();
    }

private:
    int _size;
    double sum;
    list<int> data;
};

// 2 t-O(n), m-O(n)
/*
class MovingAverage {
public:
    /** Initialize your data structure here. */
    /*
    MovingAverage(int size):_size(size) {
        
    }
    
    double next(int val) {
        data.push_back(val);
        if (data.size() > _size) data.pop_front();
        return double(accumulate(data.begin(), data.end(), 0)) / double(data.size());
    }

private:
    int _size;
    list<int> data;
};
*/

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
