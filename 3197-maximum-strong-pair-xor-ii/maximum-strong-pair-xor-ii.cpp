struct Node {
    Node* links[2];
    int cnt;

    Node() {
        links[0] = nullptr;
        links[1] = nullptr;
        cnt = 0;
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

        node->cnt++;
    }
}

void erase(int num) {
    Node* node = root;

    for (int i = 30; i >= 0; i--) {
        int bit = (num >> i) & 1;

        node = node->links[bit];

        node->cnt--;
    }
}

int getMaxXOR(int num) {
    Node* node = root;
    int ans = 0;

    for (int i = 30; i >= 0; i--) {
        int bit = (num >> i) & 1;
        int opposite = 1 - bit;

        if (node->links[opposite] != nullptr &&
            node->links[opposite]->cnt > 0) {

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
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        BinaryTrie T;
        T.insert(nums[0]);
        int i=0,j=1;
        long long ans=0;
        int l=0,h=1;
        for(int i=0;i<nums.size();i++)
        {
             while(l<i && ((abs(nums[l]-nums[i]))>min(nums[l],nums[i])))
             {
                T.erase(nums[l]);
             l++;
             }
             while(h<nums.size() && ((abs(nums[h]-nums[i]))<=min(nums[h],nums[i])))
             {
                T.insert(nums[h]);
                h++;
             }
             int temp=T.getMaxXOR(nums[i]);
             if(temp>ans)
             ans=temp;
        }
        return ans;
    }
};