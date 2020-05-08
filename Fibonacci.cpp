// class Solution {
// public:
//     int fib(int n)
//     {
//         if(n == 0)
//             return 0;
//         if(n == 1)
//             return 1;
//         return (fib(n-1) + fib(n-2))%1000000007;
//     }
// };

class Solution {
public:
    int fib(int n)
    {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        int num1 = 0;
        int num2 = 1;
        int sum = 0;
        for(int i = 2; i <= n; i++)
        {
            sum = (num1 + num2) % 1000000007;
            num1 = num2;
            num2 = sum;
        }
        return sum;
    }
};