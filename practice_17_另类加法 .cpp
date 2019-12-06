题目ID：25083 --另类加法 
链接：https://www.nowcoder.com/practice/e7e0d226f1e84ba7ab8b28efc6e1aebc?tpId=8& &tqId=11065&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking

class UnusualAdd {
public:
	int addAB(int A, int B)
	{
		int add = 0;
		int tmp = 0;
		while (B != 0)
		{
			add = A ^ B;//对应位的和
			tmp = (A&B) << 1;//对应位的和的进位
			A = add;
			B = tmp;
		}
		return A;
	}
};

//这个应该也算是比较巧妙吧
public class Solution
 {
    public int Add(int num1,int num2)
	{
        if(num1>0)
		{
            while(num1--!=0)
                num2++;
        }
        else if(num1<0)
		{
            while(num1++!=0)
                num2--;
        }
        return num2;
    }
}