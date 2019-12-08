题目ID：24979-最近公共祖先 
链接：https://www.nowcoder.com/practice/70e00e490b454006976c1fdf47f155d9?tpId=8& &tqId=11017&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking

class LCA {
public:
	int getLCA(int a, int b)
	{
		while (a != b)
		{
			if (a > b)
			{
				a = a / 2;
			}
			if (b > a)
			{
				b = b / 2;
			}
		}
		return a;
	}
};