class Solution {
public:
    int maxLength(vector<int>& nums) {
        int mx=1;
        for(int i=0;i<nums.size();i++)
        {
            long long temp=nums[i];
            long long l=nums[i];
            long long g=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                    temp*=nums[j];
                    if(temp>151200)
                    break;
                    l=lcm(l,nums[j]);
                    g=gcd(g,nums[j]);
                if(temp==l*g)
                {
                    if((j-i+1)>mx)
                       mx=j-i+1;
                }
            }
        }
        return mx;
    }
};