题目ID：24992 --井字棋 
链接：https://www.nowcoder.com/practice/e1bb714eb9924188a0d5a6df2216a3d1?tpId=8 &&tqId=11055&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranki ng
【题目解析】： 
井字棋，是一种在3*3格子上进行的连珠游戏，三个相同就代表获胜。 

class Board {
public:
	bool checkWon(vector<vector<int>> board)
	{
		int tmp = 0;
		for (size_t i = 0; i < 3; i++)
		{
			if (board[i][0] + board[i][1] + board[i][2] == 3)
			{
				tmp = 1;
			}
		}
		for (size_t i = 0; i < 3; i++)
		{
			if (board[0][i] + board[1][i] + board[2][i] == 3)
			{
				tmp = 1;
			}
		}
		if (board[0][0] + board[1][1] + board[2][2] == 3)
		{
			tmp = 1;
		}
		if (board[0][2] + board[1][1] + board[2][0] == 3)
		{
			tmp = 1;
		}
		if (tmp == 1)
		{
			return true;
		}
		return false;
	}
};