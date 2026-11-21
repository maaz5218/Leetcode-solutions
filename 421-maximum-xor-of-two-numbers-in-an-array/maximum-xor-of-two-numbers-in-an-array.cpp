struct Node {
    Node* links[2];

    Node() {
        links[0] = nullptr;
        links[1] = nullptr;
    }
};

class BinaryTrie {
private:
    Node* root;

public:
    BinaryTrie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;

        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (node->links[bit] == nullptr) {
                node->links[bit] = new Node();
            }

            node = node->links[bit];
        }
    }

    int getMaxXOR(int num) {
        Node* node = root;

        int ans = 0;

        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;

            if (node->links[opposite] != nullptr) {
                ans |= (1 << i);
                node = node->links[opposite];
            }
            else {
                node = node->links[bit];
            }
        }

        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        BinaryTrie T;
        T.insert(nums[0]);
        int ans = 0;

    for (int i = 1; i < nums.size(); i++) {
        ans = max(ans, T.getMaxXOR(nums[i]));

        T.insert(nums[i]);
    }
    return ans;
    }
};