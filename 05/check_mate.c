#include "../exam.h"

int validate(int rows, char **board, int *king)
{
	int i;
	int j;
	int king_found;

	i = 0;
	king_found = 0;
	while (i < rows)
	{
		j = 0;
		while (board[i][j] && j < rows)
		{
			if (board[i][j] == 'K')
			{
				king[0] = i;
				king[1] = j;
				king_found = 1;
			}
			j++;
		}
		if (j != rows)
			return (0);
		i++;
	}
	if (!king_found)
		return (0);
	return (1);
}

int	check_case(char **board, int i, int j, char c)
{
	if (board[i][j] == c)
		return (1);
	return (0);
}

int check_pawns(int *king, int rows, char **board)
{
	int i;
	int j;

	i = king[0];
	j = king[1];
	if (i + 1 < rows)
	{
		if (j + 1 < rows && board[i + 1][j + 1] == 'P')
		//if (j + 1 < rows && check_case(board, i + 1, j + 1, 'P'))
			return (1);
		if (j - 1 >= 0 && board[i + 1][j - 1] == 'P')
			return (1);
	}
	return (0);
}

// Pawns Bishops Rooks Queens

int	check_BQ(char **board, int i, int j)
{
	if (board[i][j] == 'B' || board[i][j] == 'Q')
		return (1);
	return (0);
}

int	check_PR(char **board, int i, int j)
{
	if (board[i][j] == 'P' || board[i][j] == 'R')
		return (1);
	return (0);
}

int	check_RQ(char **board, int i, int j)
{
	if (board[i][j] == 'R' || board[i][j] == 'Q')
		return (1);
	return (0);
}

int	check_PB(char **board, int i, int j)
{
	if (board[i][j] == 'P' || board[i][j] == 'B')
		return (1);
	return (0);
}

int check_bishop_queen(int *king, int rows, char **board)
{
	int i;
	int j;

	i = king[0];
	j = king[1];
	// jesus christ is there a way to factorise this so it looks less dumb?
	while (i - 1 >= 0 && j - 1 >= 0)
	{
		i--;
		j--;
		if (check_BQ(board, i , j))
			return (1);
		if (check_PR(board, i, j))
			break;
	}
	i = king[0];
	j = king[1];
	while (i - 1 >= 0 && j + 1 < rows)
	{
		i--;
		j++;
		if (check_BQ(board, i , j))
			return (1);
		if (check_PR(board, i, j))
			break;
	}
	i = king[0];
	j = king[1];
	while (i + 1 < rows && j + 1 < rows)
	{
		i++;
		j++;
		if (check_BQ(board, i , j))
			return (1);
		if (check_PR(board, i, j))
			break;
	}
	i = king[0];
	j = king[1];
	while (i + 1 < rows && j - 1 >= 0)
	{
		i++;
		j--;
		if (check_BQ(board, i , j))
			return (1);
		if (check_PR(board, i, j))
			break;
	}
	return (0);
}

int	check_rook_queen(int *king, int rows, char **board)
{
	int i;
	int j;

	i = king[0];
	j = king[1];
	while (i + 1 < rows)
	{
		i++;
		if (check_RQ(board, i , j))
			return (1);
		if (check_PB(board, i, j))
			break;
	}
	i = king[0];
	j = king[1];
	while (i - 1 >= 0)
	{
		i--;
		if (check_RQ(board, i , j))
			return (1);
		if (check_PB(board, i, j))
			break;
	}
	i = king[0];
	j = king[1];
	while (j + 1 < rows)
	{
		j++;
		if (check_RQ(board, i , j))
			return (1);
		if (check_PB(board, i, j))
			break;
	}
	i = king[0];
	j = king[1];
	while (j - 1 >= 0)
	{
		j--;
		if (check_RQ(board, i , j))
			return (1);
		if (check_PB(board, i, j))
			break;
	}
	return (0);
}

int check_mate(int rows, char **board)
{
	int king[2];

	if (!validate(rows, board, king))
		return (0);
	if (check_pawns(king, rows, board))
		return (1);
	if (check_bishop_queen(king, rows, board))
		return (1);
	if (check_rook_queen(king, rows, board))
		return (1);
	return (0);
}

void check(int rows, char **board)
{
	if (check_mate(rows, board))
		printf("Success");
	else
		printf("Fail");
}

int main(int argc, char **argv)
{
	if (argc > 1)
		check(argc - 1, &argv[1]);
	printf("\n");
}
