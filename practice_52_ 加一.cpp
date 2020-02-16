给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:
输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
来源：力扣（LeetCode）


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        for(int i = digits.size()-1; i >= 0; --i)
        {
            if(digits[i] != 9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        ////跳出for循环，说明数字全部是9
        vector<int> tmp;
        tmp.resize(digits.size()+1);
        tmp[0] = 1;
        return tmp;
    }
};