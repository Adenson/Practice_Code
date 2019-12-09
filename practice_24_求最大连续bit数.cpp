题目ID：36910-求最大连续bit数 
链接：https://www.nowcoder.com/practice/4b1658fd8ﬀb4217bc3b7e85a38cfaf2?tpId=37& &tqId=21309&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int a;
	while (cin >> a)
	{
		vector<int> v;
		while (a != 0)
		{
			v.push_back(a % 2);
			a /= 2;
		}
		int sum = 0;
		int count = 0;
		for (size_t i = 0; i < v.size(); i++)
		{
			if (v[i] == 1)
			{
				sum++;
			}
			if (sum > count)
			{
				count = sum;
			}
			if (v[i] == 0)
			{
				sum = 0;
			}
		}
		cout << count << endl;
	}
	return 0;
}