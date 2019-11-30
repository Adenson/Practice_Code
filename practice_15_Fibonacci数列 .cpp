题目ID：45846 --Fibonacci数列 
链接： https://www.nowcoder.com/practice/18ecd0ecf5ef4fe9ba3f17f8d00d2d66?tpId=85& &tqId=29846&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking


#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> v;
	v.resize(N + 3);//多加3个是为了防止N = 1
	v[0] = 0;
	v[1] = 1;
	size_t i = 0;
	for (i = 2; i < v.size(); i++)
	{
		v[i] = v[i - 1] + v[i - 2];
		if (v[i] > N)
		{
			break;
		}
	}
	int min = N - v[i - 1];
	int max = v[i] - N;
	if (max < min)
	{
		min = max;
	}
	cout << min << endl;
	return 0;
}
