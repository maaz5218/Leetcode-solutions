class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
           unordered_map<int,int>temp;
           for(int i=0;i<nums.size();i++)
           {
            int f=target-nums[i];
            if(temp.find(f)!=temp.end())
            return {temp[f],i};

            temp[nums[i]]=i;
           }
           return {0,0};
    }
};