class Solution {
public:
    string replaceSpace(string s) 
    {
        string tmp;
        for(int i =0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                tmp += "%20";
            }
            else
            {
                tmp += s[i];
            }
        }
        return tmp;
    }
};