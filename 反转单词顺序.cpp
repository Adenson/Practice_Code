string reverseWords(string s)
{
	reverse(s.begin(), s.end());
	auto start = s.begin();
	auto end = start;
	while (start != s.end() && *start != ' ')
	{
		if (*start != ' ')
		{
			end = start;
			while (*end != '\0' && *end != ' ')
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
		start++;
	}
	if (start != s.end())
	{
		*start = '\0';
	}
	return s;
}
int main()
{
	string s("the sky is blue");
	reverseWords(s);
	system("pause");
	return 0;
}