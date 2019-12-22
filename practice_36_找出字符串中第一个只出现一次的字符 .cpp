题目ID:36883-找出字符串中第一个只出现一次的字符 
链接：https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&&tqId=21 282&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		vector<int> v;
		v.resize(256);
		for (size_t i = 0; i < s.size(); ++i)
		{
			++v[s[i]];
		}
		int j = 0;
		for (j = 0; j < s.size(); ++j)
		{
			if (v[s[j]] == 1)
			{
				cout << s[j] << endl;//此处已经保证了第一个出现的第一次字符
				break;
			}
		}
		if (j >= s.size())
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
