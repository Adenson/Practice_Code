题目ID：36897-计算日期到天数转换 
链接：https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21 296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

#include<iostream>
using namespace std;
int judge_date(int& month, int& day)
{
	if ((month < 0 || month > 12) || (day < 0 || day > 31))
	{
		return -1;
	}
	return 0;
}
int GetMonthDay(int& year, int& month)
{
	int arr[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		arr[2] = 29;
	}
	return arr[month];
}
int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		int sum = 0;
		int ret = judge_date(month, day);
		if (ret == -1)
		{
			return -1;
		}
		if (ret == 0)
		{
			for (int i = 0; i < month; i++)
			{
				sum = sum + GetMonthDay(year, i);
			}
		}
		int counts = sum + day;
		cout << counts << endl;
	}
	return 0;
}
