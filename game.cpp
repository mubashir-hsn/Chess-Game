#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include"mygraphics.h"
#include"myconsole.h"
#include<conio.h>
#include<cmath>
#include<ctime>
#include<cstdlib>

using namespace std;
char StartingDisplay();
char Types();
void Thanks();
int indexofcolumn(char board[10][9], char col1);
int indexofrow(char board[10][9], char row1);
void swap(char board[10][9], int r1, int col1, int r2, int col2);
void Killswap(char board[10][9], int r1, int col1, int r2, int col2);
bool Killing(char board[10][9], int r1, int c1, int r2, int c2);
void SaveGame(char board[10][9], int rows, int cols);
void LoadGame(char board[10][9], int rows, int cols);
void chessboarddisplay(char entries[10][9]);
bool checkvalid(char board[10][9], int r1, int c1, int r2, int c2);
bool whitepawn(char board[10][9], int r1, int c1, int r2, int c2);
bool blackpawn(char board[10][9], int r1, int c1, int r2, int c2);
bool blackknight(char board[10][9], int r1, int c1, int r2, int c2);
bool whiteknight(char board[10][9], int r1, int c1, int r2, int c2);
bool movecheck(char board[10][9], int r1, int c1, int r2, int c2);
//bool movement(char board[10][9], int r1, int c1, int r2, int c2);
//bool movementforblckrook(char board[10][9], int r1, int c1, int r2, int c2);
bool movementforWrook(char board[10][9], int r1, int c1, int r2, int c2);
bool movementforBrook(char board[10][9], int r1, int c1, int r2, int c2);
bool Wbishop(char board[10][9], int r1, int c1, int r2, int c2);
bool Bbishop(char board[10][9], int r1, int c1, int r2, int c2);
bool Wqueen(char board[10][9], int r1, int c1, int r2, int c2);
bool Bqueen(char board[10][9], int r1, int c1, int r2, int c2);
bool Wking(char board[10][9], int r1, int c1, int r2, int c2);
bool Bking(char board[10][9], int r1, int c1, int r2, int c2);
//killing
bool killWpawn(char board[10][9], int r1, int c1, int r2, int c2);
bool killBpawn(char board[10][9], int r1, int c1, int r2, int c2);
bool killWrook(char board[10][9], int r1, int c1, int r2, int c2);
bool killBrook(char board[10][9], int r1, int c1, int r2, int c2);
bool killWknight(char board[10][9], int r1, int c1, int r2, int c2);
bool killBknight(char board[10][9], int r1, int c1, int r2, int c2);
bool killWbishop(char board[10][9], int r1, int c1, int r2, int c2);
bool killBbishop(char board[10][9], int r1, int c1, int r2, int c2);
bool killWqueen(char board[10][9], int r1, int c1, int r2, int c2);
bool killBqueen(char board[10][9], int r1, int c1, int r2, int c2);
bool killWking(char board[10][9], int r1, int c1, int r2, int c2);
bool killBking(char board[10][9], int r1, int c1, int r2, int c2);
//check
//bool checkking(char board[10][9], int r1, int c1, int r2, int c2);

bool checkingkingpresence(char board[10][9], int r1, int c1, int r2, int c2);


int main()
{
	char type = 0;
	int timer = 0;
	char choice;
	COLORREF RED = RGB(255, 0, 0);
	COLORREF YELLOW = RGB(255, 255, 102);
	COLORREF BLUE = RGB(0, 0, 255);
	choice = StartingDisplay();
	char boardentries[10][9] = {    /*   0   1   2    3   4  5   6   7   8*/
		/**/   {'0','a','b','c','d','e','f','g','h'},
		/*1 */ {'8','R','N','B','Q','K','B','N','R'},
		/*2*/  {'7','P','P','P','P','P','P','P','P'},
		/*3*/  {'6',' ',' ',' ',' ',' ',' ',' ',' '},
		/*4*/  {'5',' ',' ',' ',' ',' ',' ',' ',' '},
		/*5*/  {'4',' ',' ',' ',' ',' ',' ',' ',' '},
		/*6*/  {'3',' ',' ',' ',' ',' ',' ',' ',' '},
		/*7*/  {'2','p','p','p','p','p','p','p','p'},
		/*8*/  {'1','r','n','b','q','k','b','n','r'},
			   {' ','a','b','c','d','e','f','g','h'}

	};
	bool ending = false;
	if (choice == '1')
	{
		type = Types();
		ClearScreen();
	}
	else if (choice == '2')
	{
		LoadGame(boardentries, 10, 9);
	}
	else if (choice == '3')
	{
		Thanks();
		ending = true;
	}

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	//char boardentries[10][9] = {    /*   0   1   2    3   4  5   6   7   8*/
	//	/**/   {'0','a','b','c','d','e','f','g','h'},
	//	/*1 */ {'8','R','N','B','Q','K','B','N','R'},
	//	/*2*/  {'7','P','P','P','P','P','P','P','P'},
	//	/*3*/  {'6',' ',' ',' ',' ',' ',' ',' ',' '},
	//	/*4*/  {'5',' ',' ',' ',' ',' ',' ',' ',' '},
	//	/*5*/  {'4',' ',' ',' ',' ',' ',' ',' ',' '},
	//	/*6*/  {'3',' ',' ',' ',' ',' ',' ',' ',' '},
	//	/*7*/  {'2','p','p','p','p','p','p','p','p'},
	//	/*8*/  {'1','r','n','b','q','k','b','n','r'},
	//		   {' ','a','b','c','d','e','f','g','h'}

	//};
	/*SaveGame(boardentries, 10, 9);
	
	LoadGame(boardentries, 10, 9);*/
	
	chessboarddisplay(boardentries);
	char a = 'a';
	for (int i = 1; ending != true; i++)
	{

		if (i % 2 == 0)
		{
			cout << "<<Black turn>>" << endl;
			char row1, col1;
			cout << "enter the row number from where to move: " << endl;
			cin >> row1;
			cout << "enter the col number from where to move: " << endl;
			cin >> col1;
			int r1, c1;
			c1 = indexofcolumn(boardentries, col1);
			r1 = indexofrow(boardentries, row1);


			char col2, row2;
			cout << "enter the row number where you want to move: " << endl;
			cin >> row2;
			cout << "enter the col number where you want to move: " << endl;
			cin >> col2;

			int r2, c2;
			c2 = indexofcolumn(boardentries, col2);
			r2 = indexofrow(boardentries, row2);
			bool check = false;

			check = checkvalid(boardentries, r1, c1, r2, c2);
			if (check == true)
			{

				swap(boardentries, r1, c1, r2, c2);
				system("cls");

			}
			else
			{
				check = Killing(boardentries, r1, c1, r2, c2);
				if (check == true)
				{
					Killswap(boardentries, r1, c1, r2, c2);
					system("cls");
					chessboarddisplay(boardentries);
					SaveGame(boardentries, 10, 9);
					continue;
				}
				system("cls");
				cout << "invalid move." << endl;
				i = i - 1;

			}
			//Sleep(1000);
			//timer++;
			//if (timer == 10)
			//	ending = true;
			chessboarddisplay(boardentries);
			bool check3 = false;
			{
				check3 = checkingkingpresence(boardentries, r1, c1, r2, c2);
				SaveGame(boardentries, 10, 9);
				if (check3 == false)
				{
					ending = true;
					cout << "WHITE WINS ";
					SaveGame(boardentries, 10, 9);
					continue;
				}
			}
		}
		else
		{
			cout << "<<White turn>>" << endl;
			char row1, col1;
			cout << "enter the row number from where to move: " << endl;
			cin >> row1;
			cout << "enter the col number from where to move: " << endl;
			cin >> col1;
			int r1, c1;
			c1 = indexofcolumn(boardentries, col1);
			r1 = indexofrow(boardentries, row1);


			char col2, row2;
			cout << "enter the row number where you want to move: " << endl;
			cin >> row2;
			cout << "enter the col number where you want to move: " << endl;
			cin >> col2;

			int r2, c2;
			c2 = indexofcolumn(boardentries, col2);
			r2 = indexofrow(boardentries, row2);
			bool check = false;

			check = checkvalid(boardentries, r1, c1, r2, c2);
			if (check == true)
			{

				swap(boardentries, r1, c1, r2, c2);
				system("cls");

			}
			else if (check == false)
			{
				check = Killing(boardentries, r1, c1, r2, c2);
				if (check == true)
				{
					Killswap(boardentries, r1, c1, r2, c2);
					system("cls");
					chessboarddisplay(boardentries);
					SaveGame(boardentries, 10, 9);
					continue;
				}
				system("cls");
				cout << "invalid move." << endl;
				i = i - 1;

			}
			//Sleep(1000);
			//timer++;
			//if (timer == 10)
			//	ending = true;
			chessboarddisplay(boardentries);
			SaveGame(boardentries, 10, 9);
			bool check3 = false;
			{
				check3 = checkingkingpresence(boardentries, r1, c1, r2, c2);
				if (check3 == false)
				{
					ending = true;
					cout << "BLACK WINS ";
					SaveGame(boardentries, 10, 9);
					continue;
				}
			}
		}
	}


	//system("pause");
	return 0;
}

//board display
void chessboarddisplay(char entries[10][9])
{

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << entries[i][j];
			cout << " | ";
		}
		cout << endl;
		for (int i = 0; i < 12; i++)
		{
			cout << "---";
		}
		cout << endl;
	}

}
//index of column
int indexofcolumn(char board[10][9], char col1)
{
	int k = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{

			if (board[i][j] == col1)
			{
				k = j;
				return k;
			}
		}
	}


}
//index of row
int indexofrow(char board[10][9], char row1)
{
	int k = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{

			if (board[i][j] == row1)
			{
				k = i;
				return k;
			}
		}
	}
}
//swaping values
void swap(char board[10][9], int r1, int col1, int r2, int col2)
{
	char temp;
	temp = board[r1][col1];
	board[r1][col1] = board[r2][col2];
	board[r2][col2] = temp;

}
//Killing swap
void Killswap(char board[10][9], int r1, int col1, int r2, int col2)
{
	char temp;
	temp = board[r1][col1];
	board[r2][col2] = temp;
	board[r1][col1] = ' ';

}

//checking the moves if valid.

bool checkvalid(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	if (board[r1][c1] == 'p')
	{
		check = whitepawn(board, r1, c1, r2, c2);



	}
	else if (board[r1][c1] == 'P')
	{
		check = blackpawn(board, r1, c1, r2, c2);

	}
	else if (board[r1][c1] == 'N')
	{
		check = blackknight(board, r1, c1, r2, c2);
	}
	else if (board[r1][c1] == 'n')
	{
		check = whiteknight(board, r1, c1, r2, c2);
	}
	else if (board[r1][c1] == 'r')
	{
		check = movementforWrook(board, r1, c1, r2, c2);
	}
	else if (board[r1][c1] == 'R')
	{
		check = movementforBrook(board, r1, c1, r2, c2);
	}
	else if (board[r1][c1] == 'b')
	{
		check = Wbishop(board, r1, c1, r2, c2);

	}
	else if (board[r1][c1] == 'B')
	{
		check = Bbishop(board, r1, c1, r2, c2);
	}
	else if (board[r1][c1] == 'q')
	{
		check = Wqueen(board, r1, c1, r2, c2);
	}
	else if (board[r1][c1] == 'Q')
	{
		check = Bqueen(board, r1, c1, r2, c2);
	}
	else if (board[r1][c1] == 'k')
	{
		//check = Wking(board, r1, c1, r2, c2);
		//check = checkking(board, r1, c1, r2, c2);
	}
	else if (board[r1][c1] == 'K')
	{
		check = Bking(board, r1, c1, r2, c2);
	}






	return check;
}




//pawn
//white pawn movement
bool whitepawn(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	bool move = false;
	move = movecheck(board, r1, c1, r2, c2);
	if (move == true)
	{
		int static num1 = 0;
		if (c1 == c2)
		{
			if (num1 == 0)
			{
				num1++;
				r1 = r1 - 2;
				if (r1 == r2 || r1 == r2 - 1)
				{
					check = true;
				}
			}
			else
			{
				r1 = r1--;
				if (r1 == r2)
				{
					check = true;
				}
			}
		}

	}

	return check;
}

//black pawn
bool blackpawn(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool move = false;
	bool check = false;
	move = movecheck(board, r1, c1, r2, c2);
	if (move == true)
	{

		int static num = 0;
		if (c1 == c2)
		{
			if (num == 0)
			{
				num++;
				r1 = r1 + 2;
				if (r1 == r2 || r1 == r2 + 1)
				{
					check = true;
				}

			}
			else
			{
				r1 = r1++;
				if (r1 == r2)
				{
					check = true;
				}
			}
		}
	}

	return check;
}




//knight
//black knight 
bool blackknight(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check1 = false;
	if (board[r2][c2] >= 97 && board[r2][c2] <= 122 || board[r2][c2] >= 65 && board[r2][c2] <= 90)
	{
		return check1;
	}
	if (r1 > r2)
	{
		if (c1 > c2)
		{
			r1 = r1 - 2;
			c1 = c1 - 1;

			if (r1 == r2 && c1 == c2)
			{
				check1 = true;
			}
			else if (r1 == r2 && c1 - 2 == c2)
			{
				check1 = true;

			}
		}
		else if (c1 < c2)
		{
			r1 = r1 - 2;
			c1 = c1 + 1;

			if (r1 == r2 && c1 == c2)
			{
				check1 = true;
			}

		}
	}
	else
	{
		if (c1 > c2)
		{

			r1 = r1 + 2;
			c1 = c1 - 1;
			if (r1 == r2 && c1 == c2)
			{
				check1 = true;
			}

		}
		else if (c1 < c2)
		{
			r1 = r1 + 2;
			c1 = c1 + 1;
			if (r1 == r2 && c1 == c2)
			{
				check1 = true;
			}

		}
	}
	return check1;
}
//white knight
bool whiteknight(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check1 = false;
	if (board[r2][c2] >= 97 && board[r2][c2] <= 122 || board[r2][c2] >= 65 && board[r2][c2] <= 90)
	{
		return check1;
	}
	if (r1 > r2)
	{
		if (c1 > c2)
		{

			r1 = r1 - 2;
			c1 = c1 - 1;
			if (r1 == r2 && c1 == c2)
			{
				check1 = true;
			}

		}
		else if (c1 < c2)
		{
			r1 = r1 - 2;
			c1 = c1 + 1;
			if (r1 == r2 && c1 == c2)
			{
				check1 = true;
			}

		}
	}
	else
	{
		if (c1 > c2)
		{

			r1 = r1 + 2;
			c1 = c1 - 1;
			if (r1 == r2 && c1 == c2)
			{
				check1 = true;
			}

		}
		else if (c1 < c2)
		{
			r1 = r1 + 2;
			c1 = c1 + 1;
			if (r1 == r2 && c1 == c2)
			{
				check1 = true;
			}

		}

	}

	return check1;

}



//movement for rook
//White
bool movementforWrook(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = true;
	if (board[r2][c2] >= 97 && board[r2][c2] <= 122 || board[r2][c2] >= 65 && board[r2][c2] <= 90)
	{
		check = false;
	}
	if (c1 == c2)
	{
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[i - 1][c2] != 32)
				{
					check = false;
					return check;
				}
			}
		}
		else
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[i + 1][c2] != 32)
				{
					check = false;
					return check;
				}
			}
		}

	}
	else if (r1 == r2)
	{
		if (c1 > c2)
		{

			for (int i = c1; i > c2; i--)
			{
				if (board[r1][i - 1] != 32)
				{
					check = false;
					return check;
				}
			}
		}
		else
			for (int i = c1; i < c2; i++)
			{
				if (board[r1][i + 1] != 32)
				{
					check = false;
					return check;
				}
			}

	}
	else if (c1 != c2 && r1 != r2)
	{
		check = false;
	}




	return check;
}

//black rook
bool movementforBrook(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = true;
	if (board[r2][c2] >= 97 && board[r2][c2] <= 122 || board[r2][c2] >= 65 && board[r2][c2] <= 90)
	{
		check = false;
	}
	if (c1 == c2)
	{
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[i - 1][c2] != 32)
				{
					check = false;
					return check;
				}
			}
		}
		else
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[i + 1][c2] != 32)
				{
					check = false;
					return check;
				}
			}
		}

	}
	else if (r1 == r2)
	{
		if (c1 < c2)
		{
			for (int i = c1; i < c2; i++)
			{
				if (board[r1][i + 1] != 32)
				{
					check = false;
					return check;
				}
			}
		}




		else
		{
			for (int i = c1; i > c2; i--)
			{
				if (board[r1][i - 1] != 32)
				{
					check = false;
					return check;
				}
			}
		}
	}

	/*else if (r1 == r2)
	{

		for (int i = c1; i <= c2; i++)
		{
			if (board[r1][i+1] != 32)
			{
				check = false;
				return check;
			}
		}
	}*/
	else if (c1 != c2 && r1 != r2)
	{
		check = false;
	}






	return check;
}

//Bishop
//White bishop
bool Wbishop(char board[10][9], int r1, int c1, int r2, int c2)
{



	bool check = false;
	if (board[r2][c2] >= 97 && board[r2][c2] <= 122 || board[r2][c2] >= 65 && board[r2][c2] <= 90)
	{
		return check;
	}
	if (c1 > c2)
	{
		if (r1 > r2)
		{
			for (int i = r1; i >= r2; i--)
			{
				for (int j = c1; j >= c2; j--)
				{
					if (board[i - 1][j - 1] == board[r2][c2] && board[i - 1][j - 1] == 32)
					{
						check = true;
						return check;
					}
					else
					{
						check = false;
						return check;
					}
				}
			}
		}
		else
		{
			for (int i = r1; i <= r2; i++)
			{
				for (int j = c1; j >= c2; j--)
				{
					if (board[i + 1][j - 1] == board[r2][c2] && board[i + 1][j - 1] == 32)
					{
						check = true;
						return check;
					}
					else
					{
						check = false;
						return check;
					}
				}
			}

		}
	}
	//down
	else
	{
		if (r1 < r2)
		{
			for (int i = r1; i <= r2; i++)
			{
				for (int j = c1; j <= c2; j++)
				{
					if (board[i + 1][j + 1] == board[r2][c2] && board[i + 1][j + 1] == 32)
					{
						check = true;
						return check;
					}
					else
					{
						check = false;
						return check;
					}
				}

			}
		}
		else
		{
			for (int i = r1; i >= r2; i--)
			{
				for (int j = c1; j <= c2; j++)
				{
					if (board[i - 1][j + 1] == board[r2][c2] && board[i - 1][j + 1] == 32)
					{
						check = true;
						return check;
					}
					else
					{
						check = false;
						return check;
					}
				}
			}
		}

	}


	return check;
}

//Black Bishop
bool Bbishop(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	if (board[r2][c2] >= 97 && board[r2][c2] <= 122 || board[r2][c2] >= 65 && board[r2][c2] <= 90)
	{
		return check;
	}
	if (c1 > c2)
	{
		if (r1 > r2)
		{
			for (int i = r1; i >= r2; i--)
			{
				for (int j = c1; j >= c2; j--)
				{
					if (board[i - 1][j - 1] == board[r2][c2] && board[i - 1][j - 1] == 32)
					{
						check = true;
						return check;
					}
					else
					{
						check = false;
						return check;
					}
				}
			}
		}
		else
		{
			for (int i = r1; i <= r2; i++)
			{
				for (int j = c1; j >= c2; j--)
				{
					if (board[i + 1][j - 1] == board[r2][c2] && board[i + 1][j - 1] == 32)
					{
						check = true;
						return check;
					}
					else
					{
						check = false;
						return check;
					}
				}
			}

		}
	}
	//down
	else
	{
		if (r1 < r2)
		{
			for (int i = r1; i <= r2; i++)
			{
				for (int j = c1; j <= c2; j++)
				{
					if (board[i + 1][j + 1] == board[r2][c2] && board[i + 1][j + 1] == 32)
					{
						check = true;
						return check;
					}
					else
					{
						check = false;
						return check;
					}
				}

			}
		}
		else
		{
			for (int i = r1; i >= r2; i--)
			{
				for (int j = c1; j <= c2; j++)
				{
					if (board[i - 1][j + 1] == board[r2][c2] && board[i - 1][j + 1] == 32)
					{
						check = true;
						return check;
					}
					else
					{
						check = false;
						return check;
					}
				}
			}
		}

	}













	return check;
}


//Queen
//White Queen
bool Wqueen(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	if (board[r2][c2] >= 97 && board[r2][c2] <= 122 || board[r2][c2] >= 65 && board[r2][c2] <= 90)
	{
		return check;
	}


	//black bishop

	if (board[r2][c2] >= 97 && board[r2][c2] <= 122 || board[r2][c2] >= 65 && board[r2][c2] <= 90)
	{
		return check;
	}
	if (c1 > c2)
	{
		if (r1 > r2)
		{
			for (int i = r1; i >= r2; i--)
			{
				for (int j = c1; j >= c2; j--)
				{
					if (board[i - 1][j - 1] == board[r2][c2] && board[i - 1][j - 1] == 32)
					{
						check = true;
						return check;
					}
					else
					{
						check = false;
						return check;
					}
				}
			}
		}
		else
		{
			for (int i = r1; i <= r2; i++)
			{
				for (int j = c1; j >= c2; j--)
				{
					if (board[i + 1][j - 1] == board[r2][c2] && board[i + 1][j - 1] == 32)
					{
						check = true;
						return check;
					}
					else
					{
						check = false;
						return check;
					}
				}
			}

		}
	}
	//down
	else
	{
		if (r1 < r2)
		{
			for (int i = r1; i <= r2; i++)
			{
				for (int j = c1; j <= c2; j++)
				{
					if (board[i + 1][j + 1] == board[r2][c2] && board[i + 1][j + 1] == 32)
					{
						check = true;
						return check;
					}
					else
					{
						check = false;
						return check;
					}
				}

			}
		}
		else
		{
			for (int i = r1; i >= r2; i--)
			{
				for (int j = c1; j <= c2; j++)
				{
					if (board[i - 1][j + 1] == board[r2][c2] && board[i + 1][j + 1] == 32)
					{
						check = true;
						return check;
					}
					else
					{
						check = false;
						return check;
					}
				}
			}
		}

	}

	if (r1 == r2 || c1 == c2)
	{



		//Black rook
		check = true;
		if (board[r2][c2] >= 97 && board[r2][c2] <= 122 || board[r2][c2] >= 65 && board[r2][c2] <= 90)
		{
			check = false;
		}
		if (c1 == c2)
		{
			if (r1 > r2)
			{
				for (int i = r1; i > r2; i--)
				{
					if (board[i - 1][c2] != 32)
					{
						check = false;
						return check;
					}
				}
			}
			else
			{
				for (int i = r1; i < r2; i++)
				{
					if (board[i + 1][c2] != 32)
					{
						check = false;
						return check;
					}
				}
			}

		}
		else if (r1 == r2)
		{
			if (c1 < c2)
			{
				for (int i = c1; i < c2; i++)
				{
					if (board[r1][i + 1] != 32)
					{
						check = false;
						return check;
					}
				}
			}




			else
			{
				for (int i = c1; i > c2; i--)
				{
					if (board[r1][i - 1] != 32)
					{
						check = false;
						return check;
					}
				}
			}
		}


		else if (c1 != c2 && r1 != r2)
		{
			check = false;
		}



	}


	return check;

}

//Black Queen
bool Bqueen(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	if (board[r2][c2] >= 97 && board[r2][c2] <= 122 || board[r2][c2] >= 65 && board[r2][c2] <= 90)
	{
		return check;
	}


	//black bishop

	if (board[r2][c2] >= 97 && board[r2][c2] <= 122 || board[r2][c2] >= 65 && board[r2][c2] <= 90)
	{
		return check;
	}
	if (c1 > c2)
	{
		if (r1 > r2)
		{
			for (int i = r1; i >= r2; i--)
			{
				for (int j = c1; j >= c2; j--)
				{
					if (board[i - 1][j - 1] == board[r2][c2] && board[i - 1][j - 1] == 32)
					{
						check = true;
						return check;
					}
					else
					{
						check = false;
						return check;
					}
				}
			}
		}
		else
		{
			for (int i = r1; i <= r2; i++)
			{
				for (int j = c1; j >= c2; j--)
				{
					if (board[i + 1][j - 1] == board[r2][c2] && board[i + 1][j - 1] == 32)
					{
						check = true;
						return check;
					}
					else
					{
						check = false;
						return check;
					}
				}
			}

		}
	}
	//down
	else
	{
		if (r1 < r2)
		{
			for (int i = r1; i <= r2; i++)
			{
				for (int j = c1; j <= c2; j++)
				{
					if (board[i + 1][j + 1] == board[r2][c2] && board[i + 1][j + 1] == 32)
					{
						check = true;
						return check;
					}
					else
					{
						check = false;
						return check;
					}
				}

			}
		}
		else
		{
			for (int i = r1; i >= r2; i--)
			{
				for (int j = c1; j <= c2; j++)
				{
					if (board[i - 1][j + 1] == board[r2][c2] && board[i + 1][j + 1] == 32)
					{
						check = true;
						return check;
					}
					else
					{
						check = false;
						return check;
					}
				}
			}
		}

	}

	if (r1 == r2 || c1 == c2)
	{



		//Black rook
		check = true;
		if (board[r2][c2] >= 97 && board[r2][c2] <= 122 || board[r2][c2] >= 65 && board[r2][c2] <= 90)
		{
			check = false;
		}
		if (c1 == c2)
		{
			if (r1 > r2)
			{
				for (int i = r1; i > r2; i--)
				{
					if (board[i - 1][c2] != 32)
					{
						check = false;
						return check;
					}
				}
			}
			else
			{
				for (int i = r1; i < r2; i++)
				{
					if (board[i + 1][c2] != 32)
					{
						check = false;
						return check;
					}
				}
			}

		}
		else if (r1 == r2)
		{
			if (c1 < c2)
			{
				for (int i = c1; i < c2; i++)
				{
					if (board[r1][i + 1] != 32)
					{
						check = false;
						return check;
					}
				}
			}




			else
			{
				for (int i = c1; i > c2; i--)
				{
					if (board[r1][i - 1] != 32)
					{
						check = false;
						return check;
					}
				}
			}
		}


		else if (c1 != c2 && r1 != r2)
		{
			check = false;
		}



	}


	return check;

}


//King
bool Wking(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	if (board[r2][c2] >= 97 && board[r2][c2] <= 122 || board[r2][c2] >= 65 && board[r2][c2] <= 90)
	{
		return check;
	}
	if (c1 == c2)
	{
		if (r1 - 1 == r2 || r1 + 1 == r2)
		{
			if (r1 > r2)
			{

				if (board[r1 - 1][c1] == board[r2][c2] && board[r1 - 1][c1] == 32)
				{
					check = true;
					return check;
				}

			}
			else
			{
				if (board[r1 + 1][c1] == board[r2][c2] && board[r1 + 1][c1] == 32)
				{
					check = true;
					return check;
				}
			}
		}

	}
	//rows
	if (r1 == r2)
	{
		if (c1 - 1 == c2 || c1 + 1 == c2)
		{
			if (c1 > c2)
			{

				if (board[r1][c1 - 1] == board[r2][c2] && board[r1][c1 - 1] == 32)
				{
					check = true;
					return check;
				}

			}
			else
			{
				if (board[r1][c1 + 1] == board[r2][c2] && board[r1][c1 + 1] == 32)
				{
					check = true;
					return check;
				}
			}
		}
	}
	//diagonal
	if (c1 != c2 && r1 != r2)
	{
		if (c1 + 1 == c2 || c1 - 1 == c2 || r1 - 1 == r2 || r1 + 1 == r2)
		{


			if (r1 > r2 && c1 > c2)
			{

				if (board[r1 - 1][c1 - 1] == board[r2][c2] && board[r1 - 1][c1 - 1] == 32)
				{
					check = true;
					return check;
				}

			}
			if (r1 > r2 && c1 < c2)
			{
				if (board[r1 - 1][c1 + 1] == board[r2][c2] && board[r1 - 1][c1 + 1] == 32)
				{
					check = true;
					return check;
				}
			}
			if (r1<r2 && c1>c2)
			{
				if (board[r1 + 1][c1 - 1] == board[r2][c2] && board[r1 + 1][c1 - 1] == 32)
				{
					check = true;
					return check;
				}
			}

			if (r1 < r2 && c1 < c2)
			{
				if (board[r1 + 1][c1 + 1] == board[r2][c2] && board[r1 + 1][c1 + 1] == 32)
				{
					check = true;
					return check;
				}
			}


		}

	}


	return check;
}

//Black king
bool Bking(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	if (board[r2][c2] >= 97 && board[r2][c2] <= 122 || board[r2][c2] >= 65 && board[r2][c2] <= 90)
	{
		return check;
	}
	if (c1 == c2)
	{
		if (r1 - 1 == r2 || r1 + 1 == r2)
		{
			if (r1 > r2)
			{

				if (board[r1 - 1][c1] == board[r2][c2] && board[r1 - 1][c1] == 32)
				{
					check = true;
					return check;
				}

			}
			else
			{
				if (board[r1 + 1][c1] == board[r2][c2] && board[r1 + 1][c1] == 32)
				{
					check = true;
					return check;
				}
			}
		}

	}
	//rows
	if (r1 == r2)
	{
		if (c1 - 1 == c2 || c1 + 1 == c2)
		{
			if (c1 > c2)
			{

				if (board[r1][c1 - 1] == board[r2][c2] && board[r1][c1 - 1] == 32)
				{
					check = true;
					return check;
				}

			}
			else
			{
				if (board[r1][c1 + 1] == board[r2][c2] && board[r1][c1 + 1] == 32)
				{
					check = true;
					return check;
				}
			}
		}
	}
	//diagonal
	if (c1 != c2 && r1 != r2)
	{
		if (c1 + 1 == c2 || c1 - 1 == c2 || r1 - 1 == r2 || r1 + 1 == r2)
		{


			if (r1 > r2 && c1 > c2)
			{

				if (board[r1 - 1][c1 - 1] == board[r2][c2] && board[r1 - 1][c1 - 1] == 32)
				{
					check = true;
					return check;
				}

			}
			if (r1 > r2 && c1 < c2)
			{
				if (board[r1 - 1][c1 + 1] == board[r2][c2] && board[r1 - 1][c1 + 1] == 32)
				{
					check = true;
					return check;
				}
			}
			if (r1<r2 && c1>c2)
			{
				if (board[r1 + 1][c1 - 1] == board[r2][c2] && board[r1 + 1][c1 - 1] == 32)
				{
					check = true;
					return check;
				}
			}

			if (r1 < r2 && c1 < c2)
			{
				if (board[r1 + 1][c1 + 1] == board[r2][c2] && board[r1 + 1][c1 + 1] == 32)
				{
					check = true;
					return check;
				}
			}


		}

	}


	return check;





}







//move checking
bool movecheck(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	bool check2 = false;
	/*if (board[r1][c1] >= 97 && board[r1][c1] <= 122)
	{

		check2 = movement(board, r1, c1, r2, c2);
	}
	if (check2 == false)
	{*/

	if (board[r2][c2] == 32)
	{
		check = true;
	}
	/*}*/



	return check;
}




//killing operations
bool Killing(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	if (check == false && board[r1][c1] == 'p')
	{
		check = killWpawn(board, r1, c1, r2, c2);
	}
	if (check == false && board[r1][c1] == 'P')
	{
		check = killBpawn(board, r1, c1, r2, c2);
	}
	if (check == false && board[r1][c1] == 'r')
	{
		check = killWrook(board, r1, c1, r2, c2);
	}
	if (check == false && board[r1][c1] == 'R')
	{
		check = killBrook(board, r1, c1, r2, c2);
	}
	if (check == false && board[r1][c1] == 'n')
	{
		check = killWknight(board, r1, c1, r2, c2);
	}
	if (check == false && board[r1][c1] == 'N')
	{
		check = killBknight(board, r1, c1, r2, c2);
	}
	if (check == false && board[r1][c1] == 'b')
	{
		check = killWbishop(board, r1, c1, r2, c2);
	}
	if (check == false && board[r1][c1] == 'B')
	{
		check = killBbishop(board, r1, c1, r2, c2);
	}
	if (check == false && board[r1][c1] == 'q')
	{
		check = killWqueen(board, r1, c1, r2, c2);
	}
	if (check == false && board[r1][c1] == 'Q')
	{
		check = killBqueen(board, r1, c1, r2, c2);
	}
	if (check == false && board[r1][c1] == 'k')
	{
		check = killWking(board, r1, c1, r2, c2);
	}
	if (check == false && board[r1][c1] == 'K')
	{
		check = killBking(board, r1, c1, r2, c2);
	}

	return check;
}



//killoperation for the white pawn
bool killWpawn(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;

	if (r1 - 1 == r2 && c1 + 1 == c2)
	{
		if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
		{
			check = true;
		}

	}
	//Left
	else if (r1 - 1 == r2 && c1 - 1 == c2)
	{
		if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
		{
			check = true;


		}
	}
	return check;
}
//kill black pawn
bool killBpawn(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	//right
	if (r1 + 1 == r2 && c1 + 1 == c2)
	{
		if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
		{
			check = true;
		}

	}
	//lesft
	else if (r1 + 1 == r2 && c1 - 1 == c2)
	{
		if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
		{
			check = true;
		}
	}
	return check;
}

//white rook operations
bool killWrook(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	if (r1 == r2)
	{
		if (c1 < c2)
		{
			//right
			for (int i = c1; i < c2; i++)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[r1][i + 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
		else
		{
			//Left
			for (int i = c1; i > c2; i--)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[r1][i - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
	}

	if (c1 == c2)
	{
		//up
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i - 1][c1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}


		}
		else

			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i + 1][c1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}



	}



	return check;
}

//black rook
bool killBrook(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	if (r1 == r2)
	{
		if (c1 < c2)
		{
			//right
			for (int i = c1; i < c2; i++)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[r1][i + 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
		else
		{
			//Left
			for (int i = c1; i > c2; i--)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[r1][i - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
	}

	if (c1 == c2)
	{
		//up
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i - 1][c1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}


		}
		else

			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i + 1][c1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}



	}


	return check;
}

//White knight 
bool killWknight(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	//upward right
	if (c1 < c2)
	{
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i - 1][c1 + 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
	}
	//upward left
	else
	{

		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i - 1][c1 - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
	}

	//downwards left

	if (c1 > c2)
	{
		if (r1 < r2)
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i + 1][c1 - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
	}
	else
	{
		if (r1 < r2)
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i + 1][c1 + 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}



	}






	return check;
}
//black
bool killBknight(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	//upward right
	if (c1 < c2)
	{
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i - 1][c1 + 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
	}
	//upward left
	else
	{

		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i - 1][c1 - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
	}

	//downwards left

	if (c1 > c2)
	{
		if (r1 < r2)
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i + 1][c1 - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
	}
	//downward right
	else
	{
		if (r1 < r2)
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i + 1][c1 + 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}



	}




	return check;
}

//white bishop
bool killWbishop(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	//upward left
	if (c1 > c2)
	{
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i - 1][c1 - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
	}
	//upward right
	else
	{
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i - 1][c1 + 1] == board[r2][c2])
					{

						check = true;
						return check;
					}
					c1++;
				}
			}
		}
	}
	//downwards right
	if (c1 < c2)
	{
		if (r1 < r2)
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i + 1][c1 + 1] == board[r2][c2])
					{

						check = true;
						return check;
					}
					c1++;
				}
			}
		}
	}
	else
	{
		if (r1 < r2)
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i + 1][c1 - 1] == board[r2][c2])
					{

						check = true;
						return check;
					}
					c1--;
				}
			}
		}
	}
	return check;
}

//black bishop
bool killBbishop(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	//upward left
	if (c1 > c2)
	{
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 95 && board[r2][c2] <= 122)
				{
					if (board[i - 1][c1 - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
	}
	//upward right
	else
	{
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 95 && board[r2][c2] <= 122)
				{
					if (board[i - 1][c1 + 1] == board[r2][c2])
					{

						check = true;
						return check;
					}
					c1++;
				}
			}
		}
	}
	//downwards right
	if (c1 < c2)
	{
		if (r1 < r2)
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 95 && board[r2][c2] <= 122)
				{
					if (board[i + 1][c1 + 1] == board[r2][c2])
					{

						check = true;
						return check;
					}
					c1++;
				}
			}
		}
	}
	else
	{
		if (r1 < r2)
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 95 && board[r2][c2] <= 122)
				{
					if (board[i + 1][c1 - 1] == board[r2][c2])
					{

						check = true;
						return check;
					}
					c1--;
				}
			}
		}
	}
	return check;
}

//White queen
bool killWqueen(char board[10][9], int r1, int c1, int r2, int c2)
{
	//bishop
	bool check = false;
	//upward left
	if (c1 > c2)
	{
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i - 1][c1 - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
	}
	//upward right
	else
	{
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i - 1][c1 + 1] == board[r2][c2])
					{

						check = true;
						return check;
					}
					c1++;
				}
			}
		}
	}
	//downwards right
	if (c1 < c2)
	{
		if (r1 < r2)
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i + 1][c1 + 1] == board[r2][c2])
					{

						check = true;
						return check;
					}
					c1++;
				}
			}
		}
	}
	else
	{
		if (r1 < r2)
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i + 1][c1 - 1] == board[r2][c2])
					{

						check = true;
						return check;
					}
					c1--;
				}
			}
		}
	}
	//rook
	if (r1 == r2)
	{
		if (c1 < c2)
		{
			//right
			for (int i = c1; i < c2; i++)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[r1][i + 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
		else
		{
			//Left
			for (int i = c1; i > c2; i--)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[r1][i - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
	}

	if (c1 == c2)
	{
		//up
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i - 1][c1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}


		}
		else

			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i + 1][c1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}



	}




	return check;
}
//black queen
bool killBqueen(char board[10][9], int r1, int c1, int r2, int c2)
{
	//bishop
	bool check = false;
	//upward left
	if (c1 > c2)
	{
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i - 1][c1 - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
	}
	//upward right
	else
	{
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i - 1][c1 + 1] == board[r2][c2])
					{

						check = true;
						return check;
					}
					c1++;
				}
			}
		}
	}
	//downwards right
	if (c1 < c2)
	{
		if (r1 < r2)
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i + 1][c1 + 1] == board[r2][c2])
					{

						check = true;
						return check;
					}
					c1++;
				}
			}
		}
	}
	else
	{
		if (r1 < r2)
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i + 1][c1 - 1] == board[r2][c2])
					{

						check = true;
						return check;
					}
					c1--;
				}
			}
		}
	}
	//rook
	if (r1 == r2)
	{
		if (c1 < c2)
		{
			//right
			for (int i = c1; i < c2; i++)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[r1][i + 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
		else
		{
			//Left
			for (int i = c1; i > c2; i--)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[r1][i - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
	}

	if (c1 == c2)
	{
		//up
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i - 1][c1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}


		}
		else

			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i + 1][c1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}



	}




	return check;
}

//white king
bool killWking(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	if (c1 > c2)
	{
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i - 1][c1 - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
		else
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i + 1][c1 - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}


		}



	}
	else
	{
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i - 1][c1 + 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
		else
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i + 1][c1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}


		}

	}
	//same rows
	if (r1 == r2)
	{
		if (c1 < c2)
		{
			for (int i = r1; i <= r2; i++)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i][c1 + 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
		else
		{
			for (int i = r1; i <= r2; i++)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i][c1 - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}


		}

	}

	//same columns
	if (c1 == c2)
	{
		if (r1 < r2)
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i][c1 - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}

		}
		else
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 65 && board[r2][c2] <= 90)
				{
					if (board[i - 1][c1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}

		}
	}
	return check;
}
//black king
bool killBking(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	if (c1 > c2)
	{
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i - 1][c1 - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
		else
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i + 1][c1 - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}


		}



	}
	else
	{
		if (r1 > r2)
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i - 1][c1 + 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
		else
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i + 1][c1 + 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}


		}

	}
	//same rows
	if (r1 == r2)
	{
		if (c1 < c2)
		{
			for (int i = r1; i <= r2; i++)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i][c1 + 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}
		}
		else
		{
			for (int i = r1; i <= r2; i++)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i][c1 - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}


		}

	}

	//same columns
	if (c1 == c2)
	{
		if (r1 < r2)
		{
			for (int i = r1; i < r2; i++)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i][c1 - 1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}

		}
		else
		{
			for (int i = r1; i > r2; i--)
			{
				if (board[r2][c2] >= 97 && board[r2][c2] <= 122)
				{
					if (board[i - 1][c1] == board[r2][c2])
					{
						check = true;
						return check;
					}
				}
			}

		}
	}
	return check;
}


//check code for white king:
//bool checkking(char board[10][9], int r1, int c1, int r2, int c2)
//{
//	bool check = 0;
//	int i, j;
//
//	if (board[i + 1][j] == 'k' || board[i + 1][j] == 'r' || board[i + 1][j] == 'q')
//	{
//		check = 1;
//		return(check);
//	}
//	if (board[i - 1][j] == 'k' || board[i - 1][j] == 'r' || board[i - 1][j] == 'q')
//	{
//		check = 1;
//		return(check);
//	}
//	if (board[i][j + 1] == 'k' || board[i][j + 1] == 'r' || board[i][j + 1] == 'q')
//	{
//		check = 1;
//		return(check);
//	}
//	if (board[i][j - 1] == 'k' || board[i][j - 1] == 'r' || board[i][j - 1] == 'q')
//	{
//		check = 1;
//		return(check);
//	}
//	if (board[i - 1][j - 1] == 'b' || board[i - 1][j - 1] == 'p' || board[i - 1][j - 1] == 'q' || board[i - 1][j - 1] == 'k')
//	{
//		check = 1;
//		return(check);
//	}
//	if (board[i - 1][j + 1] == 'b' || board[i - 1][j + 1] == 'p' || board[i - 1][j + 1] == 'q' || board[i - 1][j + 1] == 'k')
//	{
//		check = 1;
//		return(check);
//	}
//	if (board[i + 1][j + 1] == 'b' || board[i + 1][j + 1] == 'q' || board[i + 1][j + 1] == 'k')
//	{
//		check = 1;
//		return(check);
//	}
//	if (board[i + 1][j - 1] == 'b' || board[i + 1][j - 1] == 'q' || board[i + 1][j - 1] == 'k')
//	{
//		check = 1;
//		return(check);
//	}
//	if (board[i - 2][j - 1] == 'n' || board[i - 2][j + 1] == 'n' || board[i + 2][j - 1] == 'n' || board[i + 2][j + 1] == 'n')
//	{
//		check = 1;
//		return(check);
//	}
//
//	//horizontal
//
//	for (int k = 1; board[i + k][j] == ' '; k++)
//	{
//		if (board[i + k + 1][j] == 'r' || board[i + k + 1][j] == 'q')
//		{
//			check = 1;
//			return(check);
//		}
//	}
//
//	for (int k = 1; board[i - k][j] == ' '; k++)
//	{
//		if (board[i - k - 1][j] == 'r' || board[i - k - 1][j] == 'q')
//		{
//			check = 1;
//			return(check);
//		}
//	}
//
//	for (int k = 1; board[i][j + k] == ' '; k++)
//	{
//		if (board[i][j + k + 1] == 'r' || board[i][j + k + 1] == 'q')
//		{
//			check = 1;
//			return(check);
//		}
//	}
//
//	for (int k = 1; board[i][j - k] == ' '; k++)
//	{
//		if (board[i][j - k - 1] == 'r' || board[i][j - k - 1] == 'q')
//		{
//			check = 1;
//			return(check);
//		}
//	}
//
//	//horizontal end
//
//	//diagonal
//
//	for (int k = 1; board[i + k][j + k] == ' '; k++)
//	{
//		if (board[i + k + 1][j + k + 1] == 'b' || board[i + k + 1][j + k + 1] == 'q')
//		{
//			check = 1;
//			return(check);
//		}
//	}
//
//	for (int k = 1; board[i - k][j - k] == ' '; k++)
//	{
//		if (board[i - k - 1][j - k - 1] == 'b' || board[i - k - 1][j - k - 1] == 'q')
//		{
//			check = 1;
//			return(check);
//		}
//	}
//
//
//
//}


void SaveGame(char board[10][9], int rows, int cols)
{
	ofstream out;
	char x;
	out.open("savegame.txt");
	//out << 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			x = board[i][j];
			out << x << " ";
			//cout << board[i][j];
		}
		out << endl;
	}
	out.close();
}

void LoadGame(char board[10][9], int rows, int cols)
{
	ifstream in;
	char x;
	int temp = 0;
	string str;
	in.open("savegame.txt");
	int i = 0, j = 0;
	for (int y = 0; y < 10; y++)
	{
		getline(in, str);
		for (j = 0; j < 18; j++)
		{
			board[i][temp] = str[j];
			j++;
			temp++;
		}
		i++;
		temp = 0;
	}
	//for (int s = 0; s < 10; s++)
	//{
	//	for (int m = 0; m < 9; m++)
	//	{
	//		cout << board[s][m] << " ";
	//	}
	//	cout << endl;
	//}

	in.close();
}

char StartingDisplay()
{

	COLORREF RED = RGB(255, 0, 0);
	COLORREF YELLOW = RGB(255, 255, 102);
	COLORREF BLUE = RGB(0, 0, 255);
	myDrawTextWithFont(250, 10, 40, (char*)"<< WELCOME TO THE CHESS GAME >>", BLUE, YELLOW);
	myDrawTextWithFont(340, 60, 40, (char*)"1.START NEW GAME", BLUE, YELLOW);
	myDrawTextWithFont(340, 100, 40, (char*)"2.LOAD SAVED GAME", BLUE, YELLOW);
	myDrawTextWithFont(340, 140, 40, (char*)"3.EXIT", BLUE, YELLOW);

	char ch = _getch();
	while (ch > '3' || ch < '1')
	{
		myDrawTextWithFont(250, 230, 40, (char*)" Wrong Choice Entered, Try Again.", RED, YELLOW);
		ch = _getch();
	}
	ClearScreen();
	return ch;
}

char Types()
{
	COLORREF RED = RGB(255, 0, 0);
	COLORREF YELLOW = RGB(255, 255, 102);
	COLORREF BLUE = RGB(0, 0, 255);
	myDrawTextWithFont(250, 10, 40, (char*)"<< ENTER THE GAME MODE >>", BLUE, YELLOW);
	myDrawTextWithFont(340, 60, 40, (char*)"1.CLASSICAL MODE", BLUE, YELLOW);
	myDrawTextWithFont(340, 100, 40, (char*)"2.RAPID MODE", BLUE, YELLOW);
	myDrawTextWithFont(340, 140, 40, (char*)"3.BLITZ MODE", BLUE, YELLOW);
	myDrawTextWithFont(340, 180, 40, (char*)"4.LIGHTENING MODE", BLUE, YELLOW);
	char ch = _getch();
	while (ch > '4' || ch < '1')
	{
		myDrawTextWithFont(250, 230, 40, (char*)" Wrong Choice Entered, Try Again.", RED, YELLOW);
		ch = _getch();
	}

	return ch;
}



bool checkingkingpresence(char board[10][9], int r1, int c1, int r2, int c2)
{
	bool check = false;
	int x = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == 'k' || board[i][j] == 'K')
			{
				
				x++;
				continue;
			}
		}
	}
	if (x == 2)
	{
		check=true;
			return check;

	}


	return check;
}

void Thanks()
{
	COLORREF YELLOW = RGB(255, 255, 102);
	COLORREF BLUE = RGB(0, 0, 255);
	myDrawTextWithFont(450, 10, 40, (char*)"<< Thanks for our time>>", BLUE, YELLOW);
}
