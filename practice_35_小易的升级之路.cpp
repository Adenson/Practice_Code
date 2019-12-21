题目ID：36487-小易的升级之路 
链接：https://www.nowcoder.com/practice/fe6c73cb899c4fe1bdd773f8d3b42c3d?tpId=49&&tqId=293 29&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Getnumber(int& a, int& b)
{
	int min = a;
	int max = b;
	if (min > max)
	{
		min = b;
		max = a;
	}
	while (min)
	{
		int tmp = min;
		min = max % min;
		max = tmp;
	}
	return max;
}
int main()
{
	int n = 0;//怪物数量
	int a = 0;//初始化能力值
	vector<int> v;
	while (cin >> n >> a)
	{
		v.clear();
		v.resize(n);
		for (size_t i = 0; i < v.size(); ++i)
		{
			cin >> v[i];
		}
		reverse(v.begin(), v.end());
		while (v.size())
		{
			if (a >= v.back())
			{
				a = a + v.back();
				v.pop_back();
			}
			if (v.size() != 0 && a < v.back())
			{
				a = a + Getnumber(a, v.back());
				v.pop_back();
			}
		}
		cout << a << endl;
	}
	return 0;
}
