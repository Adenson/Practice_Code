题目ID：36939-合法括号序列判断 
链接：https://www.nowcoder.com/practice/d8acfa0619814b2d98f12c071aef20d4?tpId=8& &tqId=11039&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking

class Parenthesis {
public:
	bool chkParenthesis(string A, int n)
	{
		int count1 = 0;
		int count2 = 0;
		if (n % 2 != 0)
		{
			return false;
		}
		for (size_t i = 0; i < A.size(); i++)
		{
			if (A[i] == '(')
			{
				++count1;
			}
			if (A[i] == ')')
			{
				++count2;
			}
			if (A[i] != '(' && A[i] != ')')
			{
				return false;
			}
		}
		if (count1 == count2)
		{
			return true;
		}
		return false;
	}
};
