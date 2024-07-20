class NumArray {
    class SegmentTreeNode {
        public:
            int start, end;
            SegmentTreeNode* left;
            SegmentTreeNode* right;
            int sum;

            SegmentTreeNode(int start, int end) {
                this->start = start;
                this->end = end;
                this->left = nullptr;
                this->right = nullptr;
                this->sum = 0;
            }
    };

    SegmentTreeNode* root = nullptr;

private:
    SegmentTreeNode* buildTree(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        SegmentTreeNode* node = new SegmentTreeNode(start, end);
        if (start == end) {
            node->sum = nums[start];
        } else {
            int mid = start + (end - start) / 2;
            node->left = buildTree(nums, start, mid);
            node->right = buildTree(nums, mid + 1, end);
            node->sum = node->left->sum + node->right->sum;
        }
        return node;
    }

public:
    NumArray(vector<int>& nums) {
        root = buildTree(nums, 0, nums.size() - 1);
    }
    
    void updateHelper(SegmentTreeNode* node, int i, int val) {
        if (node->start == node->end) {
            node->sum = val;
        } else {
            int mid = node->start + (node->end - node->start) / 2;
            if (i <= mid) {
                updateHelper(node->left, i, val);
            } else {
                updateHelper(node->right, i, val);
            }
            node->sum = node->left->sum + node->right->sum;
        }
    }

    void update(int index, int val) {
        updateHelper(root, index, val);
    }

    int sumRangeHelper(SegmentTreeNode* node, int start, int end) {
        if (node->start == start && node->end == end) {
            return node->sum;
        } else {
            int mid = node->start + (node->end - node->start) / 2;
            if (end <= mid) {
                return sumRangeHelper(node->left, start, end);
            } else if (start >= mid + 1) {
                return sumRangeHelper(node->right, start, end);
            } else {
                return sumRangeHelper(node->left, start, mid) + sumRangeHelper(node->right, mid + 1, end);
            }
        }
    }
    
    int sumRange(int left, int right) {
        return sumRangeHelper(root, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
