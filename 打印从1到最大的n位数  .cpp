class Solution {
public:
    vector<int> printNumbers(int n)
    {
        vector<int> tmp;
        for(int i = 1; i < pow(10,n); i++)
        {
            tmp.push_back(i);
        }
        return tmp;
    }
};