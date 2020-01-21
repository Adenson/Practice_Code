题目ID：26026-微信红包 
链接：https://www.nowcoder.com/practice/fbcf95ed620f42a88be24eb2cd57ec54?tpId=49&&tqId=293 11&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking

思路一：
class Gift
{
public:
	int getValue(vector<int> gifts, int n)
	{
		sort(gifts.begin(), gifts.end());
		int middle = gifts[n / 2];
		int counts = 0;
		for (size_t i = 0; i < gifts.size(); ++i)
		{
			if (gifts[i] == middle)
			{
				++counts;
			}
		}
		if (counts > n / 2)
		{
			return middle;
		}
		else
		{
			return 0;
		}
	}
};

思路二：
class Gift 
{
public:
    int getValue(vector<int> gifts, int n) 
    {
        int middle = gifts.size()/2;
        map<int,int> m;
        for(auto& e : gifts)
        {
            ++m[e];
        }
        for(auto& e : m)
        {
            if(e.second >= middle)
            {
                return e.first;
            }
        }
        return 0;
    }
};
