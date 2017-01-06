class NumArray {
public:
    NumArray(vector<int> &nums) {
        int len = nums.size();
        data.resize(len+1);
        for (int i = 1; i <= len; ++i) {
            data[i] = data[i-1]+nums[i-1];
        }
    }

    int sumRange(int i, int j) {
        return data[j+1]-data[i];
    }

private:
    vector<int> data;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
