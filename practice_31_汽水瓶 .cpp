题目ID：36846-汽水瓶 
链接：https://www.nowcoder.com/practice/fe298c55694f4ed39e256170ﬀ2c205f?tpId=37&&tqId=2124 5&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

#include<iostream>
using namespace std;
int main()
{
	int bottle = 0;
	while (cin >> bottle)
	{
		int drink = 0;
		int tmp1 = 0;
		int tmp2 = 0;
		while (bottle >= 3)
		{
			tmp1 = bottle % 3;
			tmp2 = bottle / 3;
			drink += tmp2;
			bottle = tmp1 + tmp2;
		}
		if (bottle == 2)
		{
			drink += 1;
		}
		cout << drink << endl;
	}
	return 0;
}