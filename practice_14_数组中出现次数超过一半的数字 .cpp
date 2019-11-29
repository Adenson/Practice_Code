3271-数组中出现次数超过一半的数字 
链接：https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&tPa%20ge=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking


思路：数组排序后，如果符合条件的数存在，则一定是数组中间那个数。这种方法虽然容易理解，但由于涉及到快排sort，其时间复杂度为O(NlogN)并非最优；
 
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if(numbers.empty()) return 0;
        sort(numbers.begin(),numbers.end());
        int middle = (numbers[numbers.size()/2]);
        
        int count = 0;
        for(size_t i = 0; i < numbers.size(); i++)
        {
            if(numbers[i] == middle)
            {
                ++count;
            }
        }
        if(count > numbers.size()/2)
        {
            return middle;
        }
        else
        {
            return 0;
        }
    }
};