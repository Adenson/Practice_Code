class Solution {
public:
string reverseWords(string s)
{
	if (s.size() == 0)
		return "";
	int k = 0;
	while (k < s.size() && s[k] == ' ')
	{
		k++; // 去掉前面的空格
	}
	s.erase(s.begin(), s.begin() + k);
	int e = s.size() - 1;
	while (e >= 0 && s[e] == ' ')
	{
		e--; // 去掉后面的空格
	}
	s.erase(s.begin() + e +1, s.end());

	string tmp;
	reverse(s.begin(), s.end());	
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			tmp += s[i];
		}
		else
		{
			int j = i;
			int count = 0;
			while (s[j] == ' ')//去掉中间多余的空格
			{
				count++;
				if (count == 1)
				{
					tmp += s[j];
				}
				j++;
			}
			i = j - 1;
		}
	}
	auto start = tmp.begin();
	auto end = start;
	while (start != tmp.end() && *start != ' ')
	{
		if (*start != ' ')
		{
			end = start;
			while (end != tmp.end() && *end != ' ')
			{
				end++;
			}
			auto begin = start;
			auto last = end - 1;
			while (begin <= last)
			{
				swap(*begin, *last);
				begin++;
				last--;
			}
			start = end;
		}
		if (start == tmp.end())
		{
			break;
		}
		start++;
	}
	return tmp;
}
};