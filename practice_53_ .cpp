class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> tmp;
        tmp.resize(2);
        int i = 0;
        for(i; i < nums.size(); i++)
        {
            int j = i +1;
            for(j; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    tmp[0] = i;
                    tmp[1] = j;
                }
            }
        }
        return tmp;
    }
};