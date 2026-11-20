class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>used(nums.size(),0);
        int cnt=1;
        int mx=1;
        int i,j;
        i=0;
        j=i+1;
        int temp=-1;
        while(i<nums.size() && j<nums.size())
{
    if((nums[i]+1)==nums[j])
    {
        cnt++;
    }
    else if(nums[i]==nums[j])
    {
        nums[j]++;
        cnt++;
                temp=cnt;
        used[j]=1;
    }
    else if(nums[i]>nums[j])
          {
            nums[j]++;
            used[j]=1;
          }
    else if((nums[i]+2)==nums[j] && !used[i])
          {
            if(temp==-1)
            {
            temp=cnt;
            }
            else
            { 
            if(cnt>mx)
            {
                mx=cnt;
            }
                cnt-=temp;
                temp=cnt;
                if(cnt==0)
                cnt=1;
            }
            cnt++;
            nums[i]++;
          }
    else
    {
            if(cnt>mx)
            {
                mx=cnt;
            }
            cnt=1;
            temp=-1;

    }
                i++;
            j++;
}

return max(mx,cnt);
    }
};