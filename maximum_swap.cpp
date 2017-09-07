// string
class Solution {
public:
    int maximumSwap(int num) {
        string vec = to_string(num);
        swap(vec);
        return stoi(vec);
    }
    
private:
    void swap(string& vec) {
        int len = vec.size();
        int k = -1;
        for (int i = 0; i < len-1; ++i) {
            if (vec[i] < vec[i+1]) {
                k = i;
                break;
            }
        }
        if (k == -1) return ;

        char max_value = vec[k];
        int max_index = k;
        for (int i = k+1; i < len; ++i) {
            if (vec[i] >= max_value) {
                max_value = vec[i];
                max_index = i;
            }
        }
        
        for (int i = 0; i <= k; ++i) {
            if (max_value > vec[i]) {
                vec[max_index] = vec[i];
                vec[i] = max_value;
                break;
            }
        }
    }
};

// vector<int>
/*
class Solution {
public:
    int maximumSwap(int num) {
        auto vec = intToVector(num);
        swap(vec);
        return vectorToInt(vec);
    }

private:
    vector<int> intToVector(int num) {
        vector<int> result;
        while (num) {
            result.push_back(num%10);
            num /= 10;
        }
        return vector<int>(result.rbegin(), result.rend());
    }
    
    void swap(vector<int>& vec) {
        int len = vec.size();
        int k = -1;
        for (int i = 0; i < len-1; ++i) {
            if (vec[i] < vec[i+1]) {
                k = i;
                break;
            }
        }
        if (k == -1) return ;

        int max_value = vec[k], max_index = k;
        for (int i = k+1; i < len; ++i) {
            if (vec[i] >= max_value) {
                max_value = vec[i];
                max_index = i;
            }
        }
        
        for (int i = 0; i <= k; ++i) {
            if (max_value > vec[i]) {
                vec[max_index] = vec[i];
                vec[i] = max_value;
                break;
            }
        }
    }
    
    int vectorToInt(vector<int>& vec) {
        reverse(vec.begin(), vec.end());
        int num = 0;
        while (!vec.empty()) {
            num = num*10 + vec.back();
            vec.pop_back();
        }
        return num;
    }
};
*/
