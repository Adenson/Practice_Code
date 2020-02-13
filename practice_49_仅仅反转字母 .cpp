给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
示例 1：
输入："ab-cd"
输出："dc-ba"

示例 2：
输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"

示例 3：
输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-only-letters
class Solution
 {
public:
    string reverseOnlyLetters(string S) 
    {
        for(int i = 0,j = S.size()-1; i< S.size() && j >=0; ++i,--j)
        {
            if(i < j)
            {
                while(!isLetter(S[i]) && i < j)
                {
                    ++i;
                }
                while(!isLetter(S[j]) && i < j)
                {
                    --j;
                }
                swap(S[i],S[j]);
            }
        }
        return S;
    }
private:
    bool isLetter(char c)
    {
      return (c >= 'a'&& c <= 'z')||(c >= 'A'&& c <= 'Z');
    }
};