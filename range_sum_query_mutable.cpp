class SegmentTreeNode {
public:
    int start, end, sum;
    SegmentTreeNode* left, *right;
    SegmentTreeNode (int start, int end, int sum) {
        this->start = start;
        this->end = end;
        this->sum = sum;
        this->left = this->right = nullptr;
    }
};

class NumArray {
private:
    SegmentTreeNode* root;
    
    SegmentTreeNode* buildTree(vector<int>& A, int start, int end) {
        if (start > end) return nullptr;
        
        SegmentTreeNode* root = new SegmentTreeNode(start, end, 0);
        
        if (start == end) {
            root->sum = A[start];
            return root;
        }
        
        int mid = start + (end-start)/2;
        root->left = buildTree(A, start, mid);
        root->right = buildTree(A, mid +1, end);
        
        int left_sum = root->left ? root->left->sum : 0;
        int right_sum = root->right ? root->right->sum : 0;
        root->sum = left_sum + right_sum;
        
        return root;
    }
    
    int query(SegmentTreeNode* root, int start, int end) {
        if (!root || start > root->end || end < root->start) return 0;
        
        if (start == root->start && end == root->end) return root->sum;
        
        int mid = root->start + (root->end-root->start)/2;
        if (end <= mid) return query(root->left, start, end);
        else if (start > mid) return query(root->right, start, end);
        return query(root->left, start, mid) + query(root->right, mid+1, end);
    }
    
    void modify(SegmentTreeNode* root, int index, int value) {
        if (!root || root->start > index || root->end < index) return;
        
        if (root->start == index && root->end == index) {
            root->sum = value;
            return ;
        }
        
        modify(root->left, index, value);
        modify(root->right, index, value);
        
        int left_sum = root->left ? root->left->sum : 0;
        int right_sum = root->right ? root->right->sum : 0;
        root->sum = left_sum + right_sum;
    }
    
public:
    NumArray(vector<int> &nums) {
        int len = nums.size();
        root = buildTree(nums, 0, len-1);
    }

    void update(int i, int val) {
        modify(root, i, val);
    }

    int sumRange(int i, int j) {
        return query(root, i, j);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
