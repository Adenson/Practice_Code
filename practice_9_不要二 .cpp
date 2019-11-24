题目ID：45840-不要二 
链接：https://www.nowcoder.com/practice/1183548cd48446b38da501e58d5944eb?tpId=85&&tqId=2%209840&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int H, W;
	cin >> H >> W;
	vector<vector<int>> v;
	v.resize(H);
	for (auto& e : v)
	{
		e.resize(W, 1);
	}


	int counts = 0;
	for (size_t i = 0; i < v.size(); ++i)
	{
		for (size_t j = 0; j < v[i].size(); ++j)
		{
			if (v[i][j] == 1)
			{
				++counts;
				if (j + 2 < W)
				{
					v[i][j + 2] = 0;
				}
				if (i + 2 < H)
				{
					v[i + 2][j] = 0;
				}
			}
		}
	}
	cout << counts;
	return 0;
}
