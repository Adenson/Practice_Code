69389-倒置字符串 
链接：https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId=85&&tqId=29867&rp%20=1&ru=/activity/oj&qru=/ta/2017test/question-ranking



#include<iostream>
#include<algorithm> 
#include<string>
using namespace std;

int main()
{
	string s1;
	getline(cin, s1);
	auto begin = s1.begin();
	auto end = s1.end();
	reverse(begin, end);

	size_t start = 0;
	size_t finish = 0;
	while (finish < s1.size())
	{
		if (s1[finish] != ' ')
		{
			start = finish;
			while (s1[finish] != ' ' && s1[finish] != '\0')
			{
				++finish;
			}
		}
		size_t start_tmp = start;
		size_t finish_tmp = finish;
		while (start_tmp < finish_tmp)
		{
			char tmp = s1[start_tmp];
			s1[start_tmp] = s1[finish_tmp - 1];
			s1[finish_tmp - 1] = tmp;
			++start_tmp;
			--finish_tmp;
		}
		++finish;
	}
	cout << s1 << endl;
	system("pause");
	return 0;
}



第二思路是一个比较讨巧的思路，直接利用cin>>s接收输入，遇到空格就结束了，自然就分割开了每个单 词，其次将每次接收到的单词拼接到之前串的前面就逆置过来了：
#include <iostream>
#include <string>
using namespace std; // cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出
int main()
{    
	string s1, s2;   
	cin >> s2;   
	while (cin >> s1)
	{
		s2 = s1 + " " + s2;
	}
	cout << s2 << endl;   
	return 0;
}
 备注：上面这个比较巧的方法可以通过调试看出来，比如输入 i like you ,开始会把 i 给 s2, like 给 s1 ,然后根据循环就可以得出！
