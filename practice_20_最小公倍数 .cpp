题目ID：36932-求最小公倍数 
链接：https://www.nowcoder.com/practice/22948c2cad484e0291350abad86136c3?tpId=37 &&tqId=21331&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

方法一：
#include<iostream>
using namespace std;
int main()
{
    int A, B;
    cin >> A >> B;
    int min = A;
    int max = B;
    if (min > max)
    {
        max = A;
        min = B;
    }
    int i = 1;
    while (A*i % B != 0)
    {
 
        ++i;
    }
    cout << A*i;
    return 0;
}

方法二：
#include<iostream>
using namespace std;
int gcd(int a, int b)
 { 
 int r; while(r = a%b)
 { 
  a = b;
  b = r;
 }
  return b;
} 
int main()
 { 
 int a,b;
 while(cin >> a >> b)
 { 
  cout << a*b/gcd(a,b) <<endl;
  }
  return 0;
 } 
