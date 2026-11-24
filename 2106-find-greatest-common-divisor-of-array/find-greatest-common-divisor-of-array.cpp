class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mi=INT_MAX;
        int mx=INT_MIN;
        for(const auto& r:nums)
        {
            if(r>mx)
            mx=r;
            if(r<mi)
            mi=r;
        }
        return gcd(mi,mx);
    }
};