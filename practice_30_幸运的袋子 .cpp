题目ID:45839-幸运的袋子 
链接：https://www.nowcoder.com/practice/a5190a7c3ec045ce9273beebdfe029ee?tpId=85&&tqId=29 839&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

#include<iostream>
#include<algorithm>
using namespace std;
int getLuckyPacket(int x[], int n, int pos, int sum, int multi)
{   
	int count = 0; 
	for (int i = pos; i<n; i++) 
	{       
		sum += x[i];  
		multi *= x[i];  
		if (sum > multi)
		{     
			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi); 
		}      	
		else if (x[i] == 1)     
		{         
			count += getLuckyPacket(x, n, i + 1, sum, multi);    
		}    
		else 
		{  
			break;  
		}  
		sum -= x[i]; 
		multi /= x[i];
		while (i < n - 1 && x[i] == x[i + 1])  
		{     
			i++;     		
		}
	}  
	return count;
} 
int main()
{   
	int n; 
	vector<int> v;
	while (cin >> n) 
	{   
		v.resize(n);
		for (int i = 0; i < n; i++)  
		{     
			cin >> v[i];  
		}      
		sort(v.begin(), v.end());
		cout << getLuckyPacket(&v[0], n, 0, 0, 1) << endl;  
	} 
	return 0;
}
