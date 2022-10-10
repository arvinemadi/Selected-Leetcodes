lass Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        length = nums.size();
        int offset = 10000;
        vector<int> result;
        for (int index = length - 1; index >= 0; index--)
        {
            update(0, 0, 20000, nums[index] + offset);
            result.push_back(getValue(0, 0, 20000, 0, nums[index] - 1 + offset));

        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    int length;
    unordered_map<int, int> segment_tree;
    
    void update(int node_index, int node_left, int node_right, int value)
    {
        if (value < node_left || value > node_right)    return;
        segment_tree[node_index]++;
        int mid = (node_left + node_right) / 2;
        if (mid != node_right && mid + 1 != node_left)
        {
            update(node_index * 2 + 1, node_left, mid, value);
            update(node_index * 2 + 2, mid + 1, node_right, value);
        }
    }
    
    int getValue(int node_index, int node_left, int node_right, int left, int right)
    {
        if (left > node_right || right < node_left)     return 0;
        if (left <= node_left && right >= node_right)   return segment_tree[node_index];
        int mid = (node_left + node_right) / 2;
        return getValue(node_index * 2 + 1, node_left, mid, left, right) + getValue(node_index * 2 + 2, mid + 1, node_right, left, right);
    }
    
};