class Solution {
public:
    int minChanges(string s) {
        int cnt=0;
        if(s.length()%2==1)
        return -1;
        else
        for(int i=1;i<s.length();i=i+2)
        {
            if(s[i]!=s[i-1])
            cnt++;
        }
        return cnt;
    }
};