#include <iostream>
using namespace std;
#define N 10

class checkboard
{
public:
	char board[N][N];
	int x, y;
	void w_turn(int, int);
	void b_turn(int, int);

	void enter_location();
	void check_overlap(int, int);

	bool check_end(int, int, char);

	void print_board();
};

int main()
{
	checkboard Board;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Board.board[i][j] = '-';
		}
	}

	int k = 0;
	bool end = false;
	while (k < 100 || end == true)
	{
		if (k % 2 == 1)
		{
			cout << "It's White's turn!" << endl;
			Board.enter_location();
			Board.check_overlap(Board.x, Board.y);
			Board.w_turn(Board.x, Board.y);

			Board.print_board();

			end = Board.check_end(Board.x, Board.y, 'W');
			if (end == true)
			{
				cout << "White Wins!" << endl;
				return 0;
			}
			k++;
		}
		else if (k % 2 == 0)
		{
			cout << "It's Black's turn!" << endl;
			Board.enter_location();
			Board.check_overlap(Board.x, Board.y);
			Board.b_turn(Board.x, Board.y);

			Board.print_board();

			end = Board.check_end(Board.x, Board.y, 'B');
			if (end == true)
			{
				cout << "Black Wins!" << endl;
				return 0;
			}
			k++;
		}
	}

	return 0;
}

void checkboard::w_turn(int x, int y)
{
	board[x][y] = 'W';
}
void checkboard::b_turn(int x, int y)
{
	board[x][y] = 'B';
}
void checkboard::print_board()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
void checkboard::enter_location()
{
	cout << "x:";
	cin >> x;
	cout << "y:";
	cin >> y;
}
void checkboard::check_overlap(int x, int y)
{
	if (board[x][y] != '-')
	{
		cout << "Enter other location." << endl;
		enter_location();
	}
}
bool checkboard::check_end(int x, int y, char c)
{
	int i, j;
	int dir[4] = {0, 0, 0, 0};
	//  dir[0]=diagonal '\'
	//  dir[1]=diagonal '/'
	//  dir[2]=vertex '|'
	//  dir[3]=horizontal '--'

	// dir0
	i = x;
	j = y;
	while (i >= 0 && j >= 0)
	{
		--i;
		--j;
		if (board[i][j] == c)
			++dir[0];
		else
		{
			i = x;
			j = y;
			break;
		}
	}
	while (i < N && j < N)
	{
		++i;
		++j;
		if (board[i][j] == c)
			++dir[0];
		else
			break;
	}

	// dir1
	i = x;
	j = y;
	while (i >= 0 && j < N)
	{
		--i;
		++j;
		if (board[i][j] == c)
			++dir[1];
		else
		{
			i = x;
			j = y;
			break;
		}
	}
	while (i < N && j >= 0)
	{
		++i;
		--j;
		if (board[i][j] == c)
			++dir[1];
		else
			break;
	}

	// dir2
	i = x;
	j = y;
	while (i >= 0)
	{
		--i;
		if (board[i][j] == c)
			++dir[2];
		else
		{
			i = x;
			j = y;
			break;
		}
	}
	while (i < N)
	{
		++i;
		if (board[i][j] == c)
			++dir[2];
		else
			break;
	}

	// dir3
	i = x;
	j = y;
	while (j >= 0)
	{
		--j;
		if (board[i][j] == c)
			++dir[3];
		else
		{
			i = x;
			j = y;
			break;
		}
	}
	while (j < N)
	{
		++j;
		if (board[i][j] == c)
			++dir[3];
		else
			break;
	}

	for (int k = 0; k < 5; k++)
	{
		if (dir[k] == 4)
			return true;
	}
}
