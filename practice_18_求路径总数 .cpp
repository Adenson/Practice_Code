题目ID：36915-求路径总数 
链接：https://www.nowcoder.com/practice/e2a22f0305eb4f2f9846e7d644dba09b?tpId=37 &&tqId=21314&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

#include<iostream>
using namespace std;
int pathNum(int n,int m)
{ 
	if (n > 1 && m > 1)//b情况，递归 
	{
		return pathNum(n-1,m) + pathNum(n,m-1); 
	}
	else if (((n >= 1) && (m == 1)) || ((n == 1) && (m >= 1)))// a情况，终止条件   
	{
		return n + m;  //格子为0时， 路径为0
	}
	else
		return 0; 
} 
int main()
{ 
	int n,m; while(cin>>n>>m)
	{
		cout<<pathNum(n,m)<<endl;
	} return 0;
} 
