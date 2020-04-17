左旋转字符串

class Solution {
public:
    string reverseLeftWords(string s, int n)
    {
        string tmp = s.substr(n,s.size()-n);
        for(int i = 0; i < n;i++)
        {
            tmp.push_back(s[i]);
        }
        return tmp;
    }
};