题目ID：45844 --两种排序方法 
链接：https://www.nowcoder.com/practice/839f681bf36c486fbcc5fcb977ﬀe432?tpId=85&& tqId=29844&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<string> v;
    v.resize(N);
    for (size_t i = 0; i < v.size(); ++i)
    {
        cin >> v[i];
    }
 
    int flag1 = 0;
    for (size_t i = 0; i < v.size() - 1; ++i)
    {
        if (v[i] <= v[i + 1])
        {
            flag1 = 1;
        }
        else
        {
            flag1 = 0;
            break;
        }
    }
 
    int flag2 = 0;
    for (size_t i = 0; i < v.size() - 1; ++i)
    {
        if (v[i].size() <= v[i + 1].size())
        {
            flag2 = 1;
        }
        else
        {
            flag2 = 0;
            break;
        }
    }
     
    if(flag1 == 1)
    {
        if(flag2 == 1)
        {
            cout << "both";
        }
        if(flag2 == 0)
        {
            cout << "lexicographically";
        }
    }
     
    if(flag1 == 0)
    {
        if(flag2 == 1)
        {
            cout << "lengths";
        }
        if(flag2 == 0)
        {
            cout << "none";
        }
    }
    return 0;
}
