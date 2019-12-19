
题目ID：36836-字符串反转 
链接：：https://www.nowcoder.com/practice/e45e078701ab4e4cb49393ae30f1bb04?tpId=37&&tqId=21 235&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}
