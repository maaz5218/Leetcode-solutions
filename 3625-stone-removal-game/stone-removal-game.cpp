class Solution {
public:
    bool canAliceWin(int n) {
        int t=1;
        int s=10;
        while(n>=s)
        {
            n-=s;
            s--;
            t=1-t;
        }
return (t?false:true);
    }
};