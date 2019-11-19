58541-进制转换 
链接：https://www.nowcoder.com/practice/ac61207721a34b74b06597fe6eb67c52?tpId=85&&tqId=29862&r%20p=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

我的代码虽然通过了，但是比较笨，不容易被其他人接受）：
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int M, N;
	cin >> M >> N;
	vector<char> v;
	int flag = 0;
	if (M < 0)
	{
		M = (0 - M);
		flag = 1;
	}
	while (M)
	{
		if (M%N == 10)
		{
			v.push_back('A');
		}
		if (M%N == 11)
		{
			v.push_back('B');
		}
		if (M%N == 12)
		{
			v.push_back('C');
		}
		if (M%N == 13)
		{
			v.push_back('D');
		}
		if (M%N == 14)
		{
			v.push_back('E');
		}
		if (M%N == 15)
		{
			v.push_back('F');
		}
		if (M%N >= 0 && M%N <= 9)
		{
			v.push_back((M%N) + '0');
		}
		M = M / N;
	}
	if (flag == 1)
	{
		v.push_back('-');
	}
	auto it = v.rbegin();
	while (it != v.rend())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	return 0;
}


优秀代码(这个方法比较巧妙)：
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string buf = "0123456789ABCDEF";
    string tmp;
    int M,N;
    cin >> M >> N;
    int flag = 1;
    if(M < 0)
    {
        M = 0 - M;
        flag = 0;
    }
    while(M)
    {
        tmp += buf[M%N];
        M = M / N;
    }
    if(flag == 0)
    {
        tmp += '-';
    }
    reverse(tmp.begin(),tmp.end());
    cout << tmp << endl;
    return 0;
}


