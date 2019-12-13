题目ID：36898-参数解析 
链接：https://www.nowcoder.com/practice/668603dc307e4ef4bb07bcd0615ea677?tpId=37&&tqId=21 297&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking


#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s1;
	string s2;
	vector<string> v;
	getline(cin, s1);
	int counts = 0;
	size_t start = 0;
	size_t finish = s1.size() - 1;
	while (start <= finish)
	{
		s2.clear();
		while (start <= finish && s1[start] != ' ' && s1[start] != '"')
		{
			s2.push_back(s1[start]);
			++start;
		}
		if (s2.size() != 0)
		{
			v.push_back(s2);
			++counts;
		}
		if (s1[start] == '"')
		{
			s2.clear();
			++start;
			while (s1[start] != '"')
			{
				s2.push_back(s1[start]);
				++start;
			}
			v.push_back(s2);
			++counts;
			++start;
		}
		++start;
	}
	cout << counts << endl;
	for (auto e : v)
	{
		cout << e << endl;
	}
	system("pause");
	return 0;
}