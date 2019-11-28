题目ID：69385--字符串中找出连续最长的数字串 
链接：https://www.nowcoder.com/practice/bd891093881d4ddf9e56e7cc8416562d?tpId=85&&tqId=29%20864&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking



我的代码：
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string s1;
	getline(cin, s1);
	vector<char> v1;
	vector<vector<char>> v2;
	int count = 0;
	int max = 0;
	for (size_t i = 0; i < s1.size(); i++)
	{
		v1.clear();//记得清理
        int count = 0;//记得将count 置零
		while (s1[i] >= '0' && s1[i] <= '9')
		{
			v1.push_back(s1[i]);
			++count;
			++i;
		}
		if (max < count)
		{
			max = count;
			v2.push_back(v1);
		}
	}


	auto v3 = v2.back();
	for (size_t i = 0; i < v3.size(); i++)
	{
		cout << v3[i];
	}
	return 0;
}

优秀代码：
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1,s2,s3;
	getline(cin, s1);
    for(size_t i = 0; i <= s1.size(); i++)
//此处的 i 一定要 <= ,以为如果遇到这种 123ad123456 测试用例，最后需要再次进循环使得 s3=s2!!!
    {
        if(s1[i] >= '0' && s1[i] <= '9')
        {
            s2 += s1[i];
        }
        else
        {
            if(s3.size() < s2.size())
            {
               s3 = s2;
            }
            else
            {
               s2.clear();
            }
        }
    }
    cout << s3;
	return 0;
} 