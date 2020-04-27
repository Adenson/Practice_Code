给一非空的单词列表，返回前 k 个出现次数最多的单词。
返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。
示例 1：
输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
输出: ["i", "love"]
解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
    注意，按字母顺序 "i" 在 "love" 之前。
 示例 2：
输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
输出: ["the", "is", "sunny", "day"]
解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
    出现次数依次为 4, 3, 2 和 1 次。


方法一：
class Solution {
public:
    struct CountCompare
    {
    	bool operator()(const pair<string, int>& p1, const pair<string, int>& p2)
    	{
    		if (p1.second > p2.second)
			    return true;
		    if (p1.second == p2.second) 
            {
			    if (p1.first < p2.first)
				    return true;
		    }
		return false;
	    }
    };
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        map<string,int> CountMap;
        for(auto& e : words)
        {
            CountMap[e]++;
        }

        vector<pair<string,int>> v;
        for(auto& e : CountMap)
        {
            v.push_back(e);
        }

        sort(v.begin(),v.end(),CountCompare());

        words.clear();

        for(int i = 0; i < k; i++)
        {
            words.push_back(v[i].first);
        }

        return words;
    }
};

//方法二：
class Solution {
public:
    struct CountCompare
    {
    	bool operator()(const pair<string, int>& p1, const pair<string, int>& p2)
    	{
    		if (p1.second > p2.second)
			    return true;
		    if (p1.second == p2.second) 
            {
			    if (p1.first < p2.first)
				    return true;
		    }
		return false;
	    }
    };
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
	map<string, int> CountMap;
	for (auto& e : words)
	{
		CountMap[e]++;
	}

	priority_queue<pair<string, int>, vector<pair<string, int>>, CountCompare> pq;
	int i = 0;
	for (auto& e : CountMap)
	{
		if (i < k)
		{
			pq.push(e);
			i++;
			continue;
		}
		else
		{
			if (e.second > pq.top().second)
			{
				pq.pop();
				pq.push(e);
			}
		}
	}

	vector<string> tmp;
	while (k--)
	{
		tmp.push_back(pq.top().first);
		pq.pop();
	}
    reverse(tmp.begin(),tmp.end());
	return tmp;
    }
};


//方法三：
class Solution {
public:
    struct CountCompare
    {
        bool operator()(const pair<string, int>& L, const pair<string, int>& R)
        {
            return L.second > R.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        map<string, int> CountMap;
        for (auto& e : words)
        {
            CountMap[e]++;
        }

        multimap<int, string, greater<int>> SortMap;
        for (auto& e : CountMap)
        {
            SortMap.insert(make_pair(e.second, e.first));
        }
        int i = 0;
        vector<string> vv;
        for (auto& e : SortMap)
        {
            if (i < k)
            {
                vv.push_back(e.second);
                i++;
            }
        }
        return vv;
    }
};