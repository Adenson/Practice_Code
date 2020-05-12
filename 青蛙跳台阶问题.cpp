面试题10- II. 青蛙跳台阶问题
class Solution {
public:
    int numWays(int n) 
    {
        if(n == 0)
        {
            return 1;
        }
        if(n == 1 || n == 2)
        {
            return n;
        }
        int tmp1 = 1;
        int tmp2 = 2;
        int sum = 0;
        for(int i = 2; i < n; i++)
        {
            sum = (tmp1+tmp2)%1000000007;
            tmp1 = tmp2;
            tmp2 = sum;
        }
        return sum%1000000007;
    }

};