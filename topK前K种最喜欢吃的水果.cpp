struct CountCompare
{
	bool operator()(const pair<string, int>& L, const pair<string, int>& R)
	{
		return L.second > R.second;
	}
};
//方法①:通过sort  O(N*logN)
void GetFavoriteFruit(const vector<string>& v, size_t k)
{
	map<string, int> countMap;
	for (auto& e : v)
	{
		countMap[e]++;
	}

	vector<pair<string, int>> tmp;
	for (auto& e : countMap)
	{
		tmp.push_back(e);
	}

	sort(tmp.begin(), tmp.end(), CountCompare());

	for (int i = 0; i < k; i++)
	{
		cout << tmp[i].first << " : " << tmp[i].second << endl;
	}
}

//方法②:优先级队列做法 O(N*logK)
void GetFavoriteFruit(const vector<string>& v, size_t k)
{
	map<string, int> CountMap;
	for (auto&e : v)
	{
		CountMap[e]++;
	}

	priority_queue < pair<string, int>, vector<pair<string, int>>, CountCompare > pq;
	int i = 0;
	for (auto& e : CountMap)
	{
		if (i < k)
		{
			pq.push(e);
			++i;
		}
		if (e.second > pq.top().second)
		{
			pq.pop();
			pq.push(e);
		}
	}

	for (int i = 0; i < k; i++)
	{
		cout << pq.top().first << " : " << pq.top().second << endl;
		pq.pop();
	}
}
int main()
{
	vector<string> v = { "香蕉", "菠萝", "香蕉", "香蕉", "菠萝", "桃子" };
	GetFavoriteFruit(v, 2);
	system("pause");
	return 0;
}