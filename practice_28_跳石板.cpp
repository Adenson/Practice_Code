题目ID:46574-跳石板 
链接：https://www.nowcoder.com/practice/4284c8f466814870bae7799a07d49ec8?tpId=85&&tqId=29 852&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

我的代码（只通过60%）：
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N, M;
	int counts = 0;
	cin >> N >> M;
	vector<int> v;
	while (N < M)
	{
		v.clear();
		for (int i = 2; i < N; i++)
		{
			if (N % i == 0)
			{
				int tmp = N / i;
				v.push_back(tmp);
			}
		}
		if (v.size() == 0)
		{
			counts = -1;
			break;
		}
		sort(v.begin(), v.end());
		int flag = 1;
		for (size_t j = v.size() - 1; j >= 0; --j)
		{
			if (N + v[j] <= M)
			{
				N += v[j];
				counts++;
				break;
			}


			else if (j == 0 && N + v[j] > M)
			{
				flag = 0;
				counts = -1;
				break;
			}


			else if (N + v[j] > M)
			{
				v.pop_back();
			}


			else if (j == 0 && v[j] + N < M)
			{
				flag = 0;
				counts = -1;
				break;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
	cout << counts << endl;
	system("pause");
	return 0;
}
