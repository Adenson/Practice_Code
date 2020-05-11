class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
    {
        if(matrix.size() == 0)
        {
            return 0;
        }
        int row = matrix[0].size();
        int line = matrix.size();
        int l = 0;
        int r = row - 1;
        while(l < line && r >= 0)
        {
            if(target > matrix[l][r])
          {
               l++;
          }
           else if(target < matrix[l][r])
          {
               r--;
           }
            else
           {
              return true;
           }
        }
        return false;
    }
};