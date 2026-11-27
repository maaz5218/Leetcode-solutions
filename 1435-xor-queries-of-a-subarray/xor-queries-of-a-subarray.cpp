class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>out(queries.size());
        vector<int>pre(arr.size()+1,0);
        for(int i=0;i<arr.size();i++)
        {
            pre[i+1]=arr[i]^pre[i];
        }
        for(int i=0;i<queries.size();i++)
        {
            out[i]=pre[queries[i][0]]^pre[queries[i][1]+1];
        }
        return out;
    }
};
