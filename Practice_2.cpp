//链接：https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue=1&page=1&onlyReference=false
#include<iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int *arr = new int[3 * n];
		for (int i = 0; i < 3 * n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + 3 * n);
		long long sum = 0;//将 int sum = 0;改为long long sum = 0;
		for (int i = n; i <= 3 * n - 2; i += 2)//将此处的循环修改 ，是从第n个数开始
		{
			sum += arr[i];
		}
		cout << sum << endl;
		delete[]arr;
	}
	system("pause");
	return 0;
}