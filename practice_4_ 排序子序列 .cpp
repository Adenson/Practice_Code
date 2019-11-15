//题目ID：100448 排序子序列 
//https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderBy%20HotValue=1&page=1&onlyReference=false

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    a.resize(n+1); // 注意这里多给了一个值，是处理越界的情况的比较
    
     //读入数组
    int i = 0;
    for (i = 0; i < n; ++i) 
    {
        cin >> a[i];
    }
     
    i = 0;
    int count = 0;
    while (i < n)
    {  
        // 非递减子序列
        if (a[i] < a[i + 1])
        { 
            while (i < n && a[i] <= a[i + 1])
            {
                i++;
            }
            count++;
            i++;
        }
        else if (a[i] == a[i + 1])
        { 
            i++;
        } 
        else // 非递增子序列
        { 
            while (i < n && a[i] >= a[i + 1])
            {
                i++;
            }
 
            count++;
            i++;
        }
    }
    cout << count << endl;
    return 0;
}


// 69389-倒置字符串 
// 链接：https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId=85&&tqId=29867&rp%20=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

#include<iostream>
#include<algorithm> 
#include<string>
using namespace std;

int main()
{
	string s1;
	getline(cin, s1);
	auto begin = s1.begin();
	auto end = s1.end();
	reverse(begin, end);

	size_t start = 0;
	size_t finish = 0;
	while (finish < s1.size())
	{
		if (s1[finish] != ' ')
		{
			start = finish;
			while (s1[finish] != ' ' && s1[finish] != '\0')
			{
				++finish;
			}
		}
		size_t start_tmp = start;
		size_t finish_tmp = finish;
		while (start_tmp < finish_tmp)
		{
			char tmp = s1[start_tmp];
			s1[start_tmp] = s1[finish_tmp - 1];
			s1[finish_tmp - 1] = tmp;
			++start_tmp;
			--finish_tmp;
		}
		++finish;
	}
	cout << s1 << endl;
	system("pause");
	return 0;
}

