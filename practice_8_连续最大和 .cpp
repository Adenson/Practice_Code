// 58539-连续最大和 
// 链接：https://www.nowcoder.com/practice/5a304c109a544aef9b583dce23f5f5db?tpId=85&&tqId=29858&rp%20=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

#include <iostream>
#include<vector>
using namespace std;
int main()
{
	int size;
	cin >> size;
	vector<int> nums(size);
	for (size_t i = 0; i < size; ++i)
	{
		cin >> nums[i];
	}
	int result = nums[0];
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < nums.size(); i++) 
	{      
        if(sum1 >= 0)
        {
            sum2 = sum1 + nums[i];
        }
        if(sum2 > result)
        {
            result = sum2;
        }
        if(sum2 < 0)
        {
            sum2 = 0;
        }
        sum1 = sum2;
	}
	cout << result << endl;
	return 0;
}