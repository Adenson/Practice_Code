// 题目ID：45842-统计回文 
// 链接：https://www.nowcoder.com/practice/9d1559511b3849deaa71b576fa7009dc?tpId=85&&tqId=29%20842&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

#include<iostream>
using namespace std;
#include<string>
bool IsCircleText(string& tmp)
{
	size_t start = 0;
	size_t end = tmp.size() - 1;
	while (start <= end)
	{
		if (tmp[start] != tmp[end])
		{
			return false;
		}
		++start;
		--end;
	}
	return true;
}
int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	int counts = 0;
	for (size_t i = 0; i <= s1.size(); i++)
	{
		string tmp = s1;
		tmp.insert(i, s2);
		if (IsCircleText(tmp) == true)
		{
			++counts;
		}
	}
	cout << counts << endl;
	return 0;
}