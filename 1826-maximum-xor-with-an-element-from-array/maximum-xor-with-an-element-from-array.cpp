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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<tuple<int,int,int>>temp;
        BinaryTrie trie;
        vector<pair<int,int>>out;
        for(int i=0;i<queries.size();i++)
        {
            temp.push_back({queries[i][1],queries[i][0],i});
        }
        sort(temp.begin(),temp.end());
        int j=0;
        while(nums[0]>get<0>(temp[j]))
        {
            out.push_back({get<2>(temp[j]),-1});
            j++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(j>=temp.size())
            break;
            if(nums[i]<=get<0>(temp[j]))
             trie.insert(nums[i]);
            else
             {
                out.push_back({get<2>(temp[j]),trie.getMaxXOR(get<1>(temp[j]))});
                j++;
                i--;
             }
        }
        while(j<temp.size())
        {
            out.push_back({get<2>(temp[j]),trie.getMaxXOR(get<1>(temp[j]))});
            j++;
        }
        sort(out.begin(),out.end());
        vector<int>ans(out.size());
        for(int i=0;i<out.size();i++)
        {
            ans[i]=out[i].second;
        }
        return ans;
    }
};