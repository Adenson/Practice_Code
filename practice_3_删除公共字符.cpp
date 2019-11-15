//69390-删除公共字符
//链接：https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId=85&&tqId=29 868&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

自己的方法：
#include<iostream>
#include<string>
using namespace std;
#include<string>
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s1.size(); i++)
	{
		int flag = 0;
		for (int j = 0; j < s2.size(); j++)
		{
			if (s1[i] == s2[j])
			{
				flag += 1;
			}
		}
		if (flag == 0)
		{
			cout << s1[i];
		}
	}
	return 0;
}

优化后的方法：
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    int arr[256] = {0};
    for(size_t i = 0; i < s2.size(); i++)
    {
        arr[s2[i]]++;
    }
    string s3;
    for(size_t j = 0; j < s1.size(); j++)
    {
        if(arr[s1[j]] == 0)
        {
            s3 += s1[j];
        }
    }
    cout << s3 << endl;
    return 0;
}