题目ID：36899-公共字串计算 
链接：https://www.nowcoder.com/practice/98dc82c094e043ccb7e0570e5342dd1b?tpId=37&&tqId=21 298&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

我的代码（通过）：
我感觉这个题有点问题，题目要求说不区分大小写，但是我没有转换大小写的时候提交之后也对了，加了之后也对了，感觉应该加上。

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		if (s1.size() > s2.size())
		{
			swap(s1, s2);
		}
		for (size_t i = 0; i < s1.size(); i++)
		{
			if (s1[i] >= 'A' && s1[i] <= 'Z')
			{
				s1[i] = s1[i] + 32;
			}
		}
		for (size_t j = 0; j < s2.size(); j++)
		{
			if (s2[j] >= 'A' && s2[j] <= 'Z')
			{
				s2[j] = s2[j] + 32;
			}
		}
		string maxlength;
		for (size_t i = 0; i < s1.size(); ++i)
		{
			for (size_t j = i; j < s2.size(); ++j)
			{
				string tmp = s1.substr(i, j - i + 1);
				if (s2.find(tmp) == -1)
				{
					break;
				}
				else if (maxlength.size() < tmp.size())
				{
					maxlength = tmp;
				}
			}
		}
		cout << maxlength.size() << endl;
	}
	return 0;
}
