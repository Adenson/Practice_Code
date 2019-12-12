题目ID：36884-查找组成一个偶数最接近的两个素数
 链接：https://www.nowcoder.com/practice/f8538f9ae3f1484fb137789dec6eedb9?tpId=37& &tqId=21283&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
 
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int number = 0;
	while (cin >> number)
	{
		vector<int> v(2);
		int sub = 0;
		int Min = number;
		int end = number / 2;
		for (int i = 2; i <= end; i++)
		{
			int counts1 = 0;
			int counts2 = 0;
			int part1 = i;
			int part2 = number - i;
			for (int k = 1; k <= part1; k++)
			{
				if (part1%k == 0)
				{
					counts1++;
				}
			}
			for (int j = 1; j <= part2; j++)
			{
				if (part2%j == 0)
				{
					counts2++;
				}
			}
			int min = 0;
			int max = 0;
			if (counts1 == 2 && counts2 == 2)
			{
				min = part1;
				max = part2;
				if (min > max)
				{
					min = part2;
					max = part1;
				}
				sub = max - min;
				v[0] = min;
				v[1] = max;
			}
			if (sub < Min)
			{
				Min = sub;
				v[0] = min;
				v[1] = max;
			}
		}
		cout << v[0] << "\n" << v[1] << endl;
	}
	return 0;
}
