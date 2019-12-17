题目ID:36889-查找两个字符串a,b中的最长公共子串 
链接：https://www.nowcoder.com/practice/181a1a71c7574266ad07f9739f791506?tpId=37&&tqId=212 88&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		if (s1.size() > s2.size())
			swap(s1, s2);
		string str_m;//存储最长公共子串
		for (int i = 0; i < s1.size(); i++)
		{
			for (int j = i; j < s1.size(); j++)
			{
				string temp = s1.substr(i, j - i + 1);
				if (s2.find(temp) == -1)
				{
					break;
				}
				else if (str_m.size() < temp.size())
				{
					str_m = temp;
				}
			}
		}
		cout << str_m << endl;
	}
	return 0;
}
