题目ID：46579 --计算糖果 
链接：https://www.nowcoder.com/practice/02d8d42b197646a5bbd0a98785bb3a34?tpId=85&&tqId=2%209857&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    
    int A = (a + c)/2;
    int C = (d - b)/2;
    int B1 = (c - a)/2;
    int B2 = (b + d)/2;
    if(B1 == B2)
    {
        cout << A << ' ' << B1 << ' ' << C;
    }
    else
    {
        cout << "No";
    }
    return 0;
}