23292-字符串转成整数 
链接：https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp%20=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking

本题的关键是要处理几个关键边界条件：
1. 空字符串 
2. 正负号处理 
3. 数字串中存在非法字符

class Solution {
public:
    int StrToInt(string str)
    {
     	if (str.empty())
    	{
    		return 0;
    	}
    	int flag = 1;
      	if (str[0] == '-')
    	{
    		str[0] = '0';
    		flag = -1;
    	}
	    else if (str[0] == '+')
	    {
    		str[0] = '0';
    		flag = 1;
    	}
    	int sum = 0;
    	for (size_t i = 0; i < str.size(); ++i)
       	{
		if (str[i] < '0' || str[i] > '9')
		{
			return 0;
		}
		sum = sum * 10 + str[i] - '0';
    	}
    	return flag * sum;
      }
};