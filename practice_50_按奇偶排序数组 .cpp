给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。
你可以返回满足此条件的任何数组作为答案。
示例：
输入：[3,1,2,4]
输出：[2,4,3,1]
输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-array-by-parity

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) 
    {
        vector<int> odd;
        vector<int> even;
        for(auto e : A)
        {
            if(e %2 == 0)
            {
                even.push_back(e);
            }
            else
            {
                odd.push_back(e);
            }
        }
        for(auto e : odd)
        {
            even.push_back(e);
        }
        return even;
    }
};