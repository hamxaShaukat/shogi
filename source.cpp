#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
enum COLOR { White, Black };
struct position {
	int ri, ci;
};
#define s 5
#define brows 9
#define Dbrows 5
#define bcols 9
#define PI 3.142
#define DBLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGREY 7
#define DARKGREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define DWHITE 15
#define BLINK 128
void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void SetClr(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}
void doClr(int r, int c)
{
	r = r * brows + 5;
	c = c * bcols + 5;

	r = (r / bcols) * bcols;
	c = (c / bcols) * bcols;

	for (int i = c; i < c + bcols; i++)
	{
		gotoRowCol(r, i);
		SetClr(2);
		cout << char(-37);
	}
	for (int i = c + bcols - 1, j = r; j < r + bcols; j++)
	{
		gotoRowCol(j, i);
		SetClr(2);
		cout << char(-37);
	}
	for (int i = r + bcols - 1, j = (c + bcols) - 1; j >= c; j--)
	{
		gotoRowCol(i, j);
		SetClr(2);
		cout << char(-37);
	}

	for (int i = (r + bcols) - 1; i >= r; i--)
	{
		gotoRowCol(i, c);
		SetClr(2);
		cout << char(-37);
	}
}
void doClrBound(int r, int c)
{
	r = r * brows + 5;
	c = c * bcols + 5;

	r = (r / bcols) * bcols;
	c = (c / bcols) * bcols;

	for (int i = c; i < c + bcols; i++)
	{
		gotoRowCol(r, i);
		SetClr(4);
		cout << char(-37);
	}
	for (int i = c + bcols - 1, j = r; j < r + bcols; j++)
	{
		gotoRowCol(j, i);
		SetClr(4);
		cout << char(-37);
	}
	for (int i = r + bcols - 1, j = (c + bcols) - 1; j >= c; j--)
	{
		gotoRowCol(i, j);
		SetClr(4);
		cout << char(-37);
	}

	for (int i = (r + bcols) - 1; i >= r; i--)
	{
		gotoRowCol(i, c);
		SetClr(4);
		cout << char(-37);
	}


}
void prntPawn(int rc, int cc)
{
	for (int ln = 0; ln < s / 2; ln++)
	{
		gotoRowCol(ln + rc, cc - ln);
		for (int sl = 0; sl < ln * 2 + 1; sl++)
			cout << char(-37);
	}
	for (int ln = 2, cl = 0; ln < s / 2 + 2; ln++, cl++)
	{
		gotoRowCol(ln + rc, cc - cl);
		for (int sl = 0; sl < cl * 2 + 1; sl++)
			cout << char(-37);
	}
}
void prntLance(int rc, int cc)
{
	for (int ln = 0; ln < s / 2; ln++)
	{
		gotoRowCol(ln + rc, cc - ln);
		for (int sl = 0; sl < ln * 2 + 1; sl++)
			cout << char(-37);
	}
	for (int ln = 2, cl = 1; ln < s / 2 + 2; ln++, cl++)
	{
		gotoRowCol(ln + rc, cc - cl);
		for (int sl = 0; sl < cl * 2 + 1; sl++)
			cout << char(-37);
	}
}
void prntRook(int rc, int cc)
{
	for (int ln = 0; ln < s / 2; ln++)
	{
		gotoRowCol(ln + rc, cc);
		cout << char(-37);
	}
	for (int ln = 2, cl = 1; ln < s / 2 + 2; ln++)
	{
		gotoRowCol(ln + rc, cc - cl);
		for (int sl = 0; sl < cl * 2 + 1; sl++)
			cout << char(-37);
	}
}
void prntKing(int rc, int cc)
{
	for (int ln = 0; ln < s / 2 + 2; ln++)
	{
		gotoRowCol(ln + rc, cc - ln);
		for (int sl = 0; sl < ln * 2 + 1; sl++)
			cout << char(-37);
	}
}
void prntBishop(int rc, int cc)
{
	for (int ln = 0; ln < s / 2 + 1; ln++)
	{
		gotoRowCol(ln + rc, cc - ln);
		for (int sl = 0; sl < ln * 2 + 1; sl++)
		{
			cout << char(-37);
		}
	}
	for (int ln = 3, cl = 1; ln < s / 2 + 2; ln++, cl++)
	{
		gotoRowCol(ln + rc, cc - cl);
		for (int sl = 0; sl < cl * 2 + 1; sl++)
		{
			cout << char(-37);
		}
	}

}
void prntKnight(int rc, int cc)
{
	for (int ln = 0; ln < s / 2; ln++)
	{
		gotoRowCol(ln + rc, cc - ln);
		for (int sl = 0; sl < ln * 2 + 1; sl++)
		{
			if (sl == 0)
				cout << char(-37);
			else
				continue;
		}
	}
	for (int ln = 2, cl = 1; ln < s / 2 + 2; ln++, cl++)
	{
		if (ln == 2)
		{
			gotoRowCol(ln + rc, cc - cl);
			for (int sl = 0; sl < cl * 2 + 1; sl++)
			{
				if (sl <= 1)
					cout << char(-37);
				else
					continue;
			}
		}
		else
		{
			gotoRowCol(ln + rc, cc - cl);
			for (int sl = 0; sl < cl * 2 + 1; sl++)
			{
				cout << char(-37);
			}
		}
	}
}
void prntGoldGen(int rc, int cc)
{
	for (int ln = 0, cl = 2; ln < s / 2 + 1; ln++)
	{
		gotoRowCol(ln + rc, cc - cl);
		for (int sl = 0; sl < cl * 2 + 1; sl++)
		{
			if (sl % 2 == 0)
				cout << char(-37);
			else
				continue;
		}
	}
	for (int ln = 3, cl = 2; ln < s / 2 + 2; ln++)
	{
		gotoRowCol(ln + rc, cc - cl);
		for (int sl = 0; sl < cl * 2 + 1; sl++)
			cout << char(-37);
	}
}
void prntSilGen(int rc, int cc)
{
	for (int ln = 0, cl = 2; ln < s / 2 + 2; ln++)
	{
		if (ln % 2 == 0)
		{
			gotoRowCol(ln + rc, cc - cl);
			for (int sl = 0; sl < cl * 2 + 1; sl++)
			{
				cout << char(-37);
			}
		}
		else
		{
			gotoRowCol(ln + rc, cc - cl);
			for (int sl = 0; sl < cl * 2 + 1; sl++)
			{
				if (sl % 2 == 0)
					cout << char(-37);
				else
					continue;
			}
		}

	}
}
void prntBox(int sr, int sc)
{
	for (int r = 1; r < brows - 1; r++)
	{
		for (int c = 1; c < bcols - 1; c++)
		{
			SetClr(14);
			gotoRowCol(sr + r, sc + c);
			cout << char(-37);
		}
	}
}
void prntBox1(int sr, int sc)
{
	for (int r = 0; r < brows; r++)
	{
		for (int c = 0; c < brows; c++)
		{
			SetClr(14);
			gotoRowCol(100 + sr + r, sc + c);
			cout << char(-37);
		}
	}
}
void prntBound(int sr, int sc)
{
	for (int r = 0; r < brows; r++)
	{
		for (int c = 0; c < bcols; c++)
		{
			SetClr(128);
			gotoRowCol(sr + r, sc + c);
			doClrBound(sr + r, sc + c);
		}
	}
}
void drawBoard(int dim)
{
	prntBound(0, 0);
	for (int r = 0; r < dim; r++)
	{
		for (int c = 0; c < dim; c++)
		{
			prntBox(r * brows, c * bcols);
		}
	}
}
void compBoard(char** B, int dim, int sr, int sc)
{
	for (int r = 0; r < dim; r++)
	{
		for (int c = 0; c < dim; c++)
		{
			int cenrow = sr + r * brows;
			int cencol = sc + c * bcols;
			gotoRowCol(sr + r * brows, sc + c * bcols);
			if (B[r][c] != '-')
			{
				switch (B[r][c])
				{
				case('R'):
					SetClr(1);
					prntRook(cenrow, cencol);
					break;
				case('B'):
					SetClr(1);
					prntBishop(cenrow, cencol);
					break;
				case('H'):
					SetClr(1);
					prntKnight(cenrow, cencol);
					break;
				case('K'):
					SetClr(1);
					prntKing(cenrow, cencol);
					break;
				case('L'):
					SetClr(1);
					prntLance(cenrow, cencol);
					break;
				case('P'):
					SetClr(1);
					prntPawn(cenrow, cencol);
					break;
				case('G'):
					SetClr(1);
					prntGoldGen(cenrow, cencol);
					break;
				case('S'):
					SetClr(1);
					prntSilGen(cenrow, cencol);
					break;
				case('r'):
					SetClr(6);
					prntRook(cenrow, cencol);
					break;
				case('b'):
					SetClr(6);
					prntBishop(cenrow, cencol);
					break;
				case('h'):
					SetClr(6);
					prntKnight(cenrow, cencol);
					break;
				case('k'):
					SetClr(6);
					prntKing(cenrow, cencol);
					break;
				case('l'):
					SetClr(6);
					prntLance(cenrow, cencol);
					break;
				case('p'):
					SetClr(6);
					prntPawn(cenrow, cencol);
					break;
				case('g'):
					SetClr(6);
					prntGoldGen(cenrow, cencol);
					break;
				case('s'):
					SetClr(6);
					prntSilGen(cenrow, cencol);
					break;
				case('O'):
					SetClr(3);
					prntGoldGen(cenrow, cencol);
					break;
				case('X'):
					SetClr(3);
					prntRook(cenrow, cencol);
					break;
				case('Z'):
					SetClr(3);
					prntBishop(cenrow, cencol);
					break;
				case('o'):
					SetClr(9);
					prntGoldGen(cenrow, cencol);
					break;
				case('x'):
					SetClr(9);
					prntRook(cenrow, cencol);
					break;
				case('z'):
					SetClr(9);
					prntBishop(cenrow, cencol);
					break;
				default:
					break;

				}
			}
		}
	}
}
bool isHor(position sC, position dC)
{
	if (sC.ri == dC.ri)
		return true;
	return false;
}
bool isVer(position sC, position dC)
{
	if (sC.ci == dC.ci)
		return true;
	return false;
}
bool isDiag(position sC, position dC)
{
	int DR = abs(sC.ri - dC.ri);
	int DC = abs(sC.ci - dC.ci);
	if (DR == DC)
	{
		return true;
	}
	return false;
}
bool isHorPC(char** B, position sC, position dC)
{
	if (sC.ci < dC.ci)
	{
		for (int col = sC.ci + 1; col < dC.ci; col++)
		{
			if (B[sC.ri][col] != '-')
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		for (int col = dC.ci + 1; col < sC.ci; col++)
		{
			if (B[sC.ri][col] != '-')
			{
				return false;
			}
		}
		return true;
	}
}
bool ndMethodisHorPC(char** B, position sC, position dC)
{
	int cs, ce;
	if (sC.ci < dC.ci)
		cs = sC.ci + 1, ce = dC.ci - 1;
	else
		cs = dC.ci + 1, ce = sC.ci - 1;


	for (int col = cs; col < ce; col++)
	{
		if (B[sC.ri][col] != '-')
		{
			return false;
		}
	}
	return true;

}
bool isVerPC(char** B, position sC, position dC)
{
	if (sC.ri < dC.ri)
	{
		for (int rows = sC.ri + 1; rows < dC.ri; rows++)
		{
			if (B[rows][sC.ci] != '-')
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		for (int rows = dC.ri + 1; rows < sC.ri; rows++)
		{
			if (B[rows][sC.ci] != '-')
			{
				return false;
			}
		}
		return true;
	}
}
bool ndMethodisVerPC(char** B, position sC, position dC)
{
	int rs, re;
	if (sC.ri < dC.ri)
		rs = sC.ri + 1, re = dC.ri - 1;
	else
		rs = dC.ri + 1, re = sC.ri - 1;


	for (int row = rs; row < re; row++)
	{
		if (B[row][sC.ci] != '-')
		{
			return false;
		}
	}
	return true;

}
bool isLeftdiagPC(char** B, position sC, position dC)
{
	if (sC.ri < dC.ri)
	{
		int dr = abs(dC.ri - sC.ri - 1);
		for (int d = 1; d <= dr; d++)
		{
			if (B[sC.ri + d][sC.ci + d] != '-')
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		int dr = abs(sC.ri - dC.ri - 1);
		for (int d = 1; d <= dr; d++)
		{
			if (B[dC.ri + d][dC.ci + d] != '-')
			{
				return false;
			}
		}
		return true;
	}
}
bool ndMethodisLdiaPC(char** B, position sC, position dC)
{
	int rs, re; int dr = 0;
	if (sC.ri < dC.ri)
	{
		int dr = dC.ri - sC.ri - 1;
		rs = sC.ri;
		re = dC.ri - 1;
	}
	else
	{
		int dr = abs(sC.ri - dC.ri - 1);
		rs = dC.ri;
		re = sC.ri - 1;
	}


	for (int row = rs; row < dr; row++)
	{
		if (B[sC.ri + row][sC.ci + row] != '-')
		{
			return false;
		}
	}
	return true;

}
bool ndMethodisRdiaPC(char** B, position sC, position dC)
{
	int rs, re; int dr = 0;
	if (sC.ri < dC.ri)
	{
		int dr = dC.ri - sC.ri - 1;
		rs = sC.ri;
		re = dC.ri - 1;
	}
	else
	{
		int dr = abs(sC.ri - dC.ri - 1);
		rs = dC.ri;
		re = sC.ri - 1;
	}


	for (int row = rs; row < dr; row++)
	{
		if (B[sC.ri + row][sC.ci - row] != '-')
		{
			return false;
		}
	}
	return true;

}
bool isRightdiagPC(char** B, position sC, position dC)
{
	if (sC.ri < dC.ri)
	{
		int dr = abs(dC.ri - sC.ri - 1);
		for (int d = 1; d <= dr; d++)
		{
			if (B[sC.ri + d][sC.ci - d] != '-')
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		int dr = abs(sC.ri - dC.ri - 1);
		for (int d = 1; d <= dr; d++)
		{
			if (B[dC.ri + d][dC.ci - d] != '-')
			{
				return false;
			}
		}
		return true;
	}
}
void init(char**& B, char**& nB, char***& uB, char dP1[], char dP2[], string pNam[], int& dim, int& turn)
{
	ifstream rdr("bscs22033_input.txt");
	rdr >> dim;
	B = new char* [dim];
	nB = new char* [dim];
	uB = new char** [10000];
	for (int ri = 0; ri < dim; ri++)
	{
		B[ri] = new char[dim];
		nB[ri] = new char[dim];
		uB[ri] = new char* [dim];
		for (int i = 0; i < dim; i++)
		{
			uB[ri][i] = new char[dim] {};
		}
	}

	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			rdr >> B[ri][ci];
		}
	}
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			rdr >> nB[ri][ci];
		}
	}

	for (int i = 0; i < 19; i++)
	{
		dP1[i] = '-';
		dP2[i] = '-';
	}
	for (int n = 0; n < 2; n++)
	{
		cout << "Enter player " << n + 1 << "'s name: ";
		cin >> pNam[n];
	}
	turn = White;
}
void print_board(char** B, int dim)
{
	system("cls");
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			cout << B[ri][ci];
		}
		cout << endl;
	}
}
bool isBlackPiece(char sym)
{
	return sym >= 'a' && sym <= 'z';
}
bool isWhitePiece(char sym)
{
	return sym >= 'A' && sym <= 'Z';
}
bool isMyTurn(char sym, int turn)
{
	if (turn == Black)
	{
		return isBlackPiece(sym);
	}
	else if (turn == White)
	{
		return isWhitePiece(sym);
	}
}
void turnMsg(string pNam[], int turn)
{
	gotoRowCol(2, 90);
	cout << " It's " << pNam[turn] << "'s turn.....";
}
void sel_src(position& sC, int dim)
{
	gotoRowCol(3, 90);
	cout << "Give sel Coordinate(A1:H8): ";

	int r;
	int c;
	getRowColbyLeftClick(r, c);
	sC.ri = r / brows;
	sC.ci = c / bcols;
}
void sel_des(position& dC, int dim)
{
	gotoRowCol(4, 90);
	cout << "Give des Coordinate(A1:H8):";
	int r;
	int c;
	getRowColbyLeftClick(r, c);
	dC.ri = r / brows;
	dC.ci = c / bcols;
}
bool isValidSrc(position sC, char** B, int dim, int turn)
{
	if (sC.ri < 0 || sC.ri >= dim || sC.ci < 0 || sC.ci >= dim)
	{
		return false;
	}
	return isMyTurn(B[sC.ri][sC.ci], turn);

}
bool isValidDes(position dC, char** B, int dim, int turn)
{
	if (dC.ri < 0 || dC.ri >= dim || dC.ci < 0 || dC.ci >= dim)
	{
		return false;
	}
	if (isMyTurn(B[dC.ri][dC.ci], turn) == false || B[dC.ri][dC.ci] == '-')
		return true;

	return false;
}
void updateBoard(char** B, position sC, position dC)
{
	char Pos = B[sC.ri][sC.ci];
	B[dC.ri][dC.ci] = Pos;
	if ((sC.ri + sC.ci) % 2 == 0)
	{
		SetClr(14);
		B[sC.ri][sC.ci] = '-';
	}
	else
	{
		SetClr(4);
		B[sC.ri][sC.ci] = '-';
	}
}
int turnChng(int turn)
{
	if (turn == 0)
	{
		turn++;
	}
	else
		turn--;
	return turn;
}
void dropinit(char d1[20], char d2[20], int turn)
{
	if (turn == 0)
	{
		for (int i = 0; i < 20; i++)
			d1[i] = '-';
	}
	else
	{
		for (int i = 0; i < 20; i++)
			d2[i] = '-';
	}
}
void dropArr(char** B, position dC, char d1[], char d2[], int cp1, int cp2, int turn)
{
	if (turn == 0)
	{
		for (int i = cp1; i < 19; i++)
		{
			if (d1[i] == '-')
				d1[i] = B[dC.ri][dC.ci];
			break;
		}
	}
	else
	{
		for (int i = cp2; i < 19; i++)
		{
			if (d2[i] == '-')
				d2[i] = B[dC.ri][dC.ci];
			break;
		}
	}
}
void dispdrop(char d1[], char d2[], int cp1, int cp2, int cpp1, int cpp2, int dim, int turn)
{
	int P1G = 100;
	int P2G = 120;
	if (turn == 0)
	{
		for (int i = cp1; i < 19; i++)
		{
			if (i <= 9)
			{
				int cencol = 5 + i * bcols;
				gotoRowCol(P1G, cencol);
				switch (d1[i])
				{
				case('r'):
					SetClr(1);
					toupper('R');
					prntRook(P1G, cencol);
					return;
				case('b'):
					toupper('b');
					SetClr(1);
					prntBishop(P1G, cencol);
					return;
				case('h'):
					toupper('h');
					SetClr(1);
					prntKnight(P1G, cencol);
					return;
				case('k'):
					SetClr(1);
					prntKing(P1G, cencol);
					return;
				case('l'):
					SetClr(1);
					prntLance(P1G, cencol);
					return;
				case('p'):
					SetClr(1);
					prntPawn(P1G, cencol);
					return;
				case('g'):
					SetClr(1);
					prntGoldGen(P1G, cencol);
					return;
				case('s'):
					SetClr(1);
					prntSilGen(P1G, cencol);
					return;
				default:
					return;
				}
			}
			else
			{

				int cencol2 = 5 + cpp1 * bcols;
				gotoRowCol(P1G + 10, cencol2);
				switch (d1[i])
				{
				case('r'):
					SetClr(1);
					prntRook(P1G + 10, cencol2);
					return;
				case('b'):
					SetClr(1);
					prntBishop(P1G + 10, cencol2);
					return;
				case('h'):
					SetClr(1);
					prntKnight(P1G + 10, cencol2);
					return;
				case('k'):
					SetClr(1);
					prntKing(P1G + 10, cencol2);
					return;
				case('l'):
					SetClr(1);
					prntLance(P1G + 10, cencol2);
					return;
				case('p'):
					SetClr(1);
					prntPawn(P1G + 10, cencol2);
					return;
				case('g'):
					SetClr(1);
					prntGoldGen(P1G + 10, cencol2);
					return;
				case('s'):
					SetClr(1);
					prntSilGen(P1G + 10, cencol2);
					return;
				default:
					return;
				}
			}
		}
	}
	else
	{
		for (int i = cp2; i < 19; i++)
		{
			if (i <= 9)
			{
				int cencol = 5 + i * bcols;
				gotoRowCol(P2G, cencol);
				switch (d2[i])
				{
				case('R'):
					SetClr(6);
					prntRook(P2G, cencol);
					return;
				case('B'):
					SetClr(6);
					prntBishop(P2G, cencol);
					return;
				case('H'):
					SetClr(6);
					prntKnight(P2G, cencol);
					return;
				case('K'):
					SetClr(6);
					prntKing(P2G, cencol);
					return;
				case('L'):
					SetClr(6);
					prntLance(P2G, cencol);
					return;
				case('P'):
					SetClr(6);
					prntPawn(P2G, cencol);
					return;
				case('G'):
					SetClr(6);
					prntGoldGen(P2G, cencol);
					return;
				case('S'):
					SetClr(6);
					prntSilGen(P2G, cencol);
					return;
				default:
					return;
				}
			}
			else
			{
				int cencol = 5 + i * bcols;
				int cencol1 = 5 + cpp2 * bcols;
				gotoRowCol(P2G + 10, cencol1);
				switch (d2[i])
				{
				case('R'):
					SetClr(6);
					prntRook(P2G + 10, cencol1);
					return;
				case('B'):
					SetClr(6);
					prntBishop(P2G + 10, cencol1);
					return;
				case('H'):
					SetClr(6);
					prntKnight(P2G + 10, cencol1);
					return;
				case('K'):
					SetClr(6);
					prntKing(P2G + 10, cencol1);
					return;
				case('L'):
					SetClr(6);
					prntLance(P2G + 10, cencol1);
					return;
				case('P'):
					SetClr(6);
					prntPawn(P2G + 10, cencol1);
					return;
				case('G'):
					SetClr(6);
					prntGoldGen(P2G + 10, cencol1);
					return;
				case('S'):
					SetClr(6);
					prntSilGen(P2G + 10, cencol1);
					return;
				default:
					return;
				}
			}
		}
	}
}
void saving(char** B, char dP1[], char dP2[], string pNam[], int dim, int turn)
{
	ofstream svr("bscs22033_save.txt");
	svr << dim << endl;

	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			svr << B[ri][ci];
		}
		svr << endl;
	}

	for (int i = 0; i < 19; i++)
	{
		svr << dP1[i];
		svr << dP2[i];
	}


	svr << endl << turn << endl;
	svr << pNam[turn] << endl;


}
void initLaod(char**& B, char**& nB, char dP1[], char dP2[], string pNam[], int& dim, int& turn)
{
	ifstream rdrL("bscs22033_save.txt");
	rdrL >> dim;
	B = new char* [dim];
	nB = new char* [dim];
	for (int ri = 0; ri < dim; ri++)
	{
		B[ri] = new char[dim];
		nB[ri] = new char [dim] {};
	}

	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			rdrL >> B[ri][ci];
		}
	}

	for (int i = 0; i < 19; i++)
	{
		rdrL >> dP1[i];
		rdrL >> dP2[i];
	}
	rdrL >> turn;
	rdrL >> pNam[turn];
}
void printPromoteButton()
{
	for (int i = 0; i < brows; i++)
	{
		for (int j = 0; j < bcols; j++)
		{
			gotoRowCol(i + 15, j + 95);
			SetClr(5);
			cout << char(-37);
		}
	}
}
void printUndoButton()
{
	for (int i = 0; i < brows; i++)
	{
		for (int j = 0; j < bcols; j++)
		{
			gotoRowCol(i + 45, j + 95);
			SetClr(4);
			cout << char(-37);
		}
	}
}
void printDropButton()
{
	for (int i = 0; i < brows; i++)
	{
		for (int j = 0; j < bcols; j++)
		{
			gotoRowCol(i + 25, j + 95);
			SetClr(2);
			cout << char(-37);
		}
	}
}

void printReplyButton()
{
	for (int i = 0; i < brows; i++)
	{
		for (int j = 0; j < bcols; j++)
		{
			gotoRowCol(i + 35, j + 95);
			SetClr(1);
			cout << char(-37);

		}
	}
}

bool drop()
{
	int r, c;
	getRowColbyLeftClick(r, c);
	if (r < 25 && c<95)
		return false;
	else if (r > 35 && c > 105)
		return false;
	return true;
}
bool undo()
{
	int r, c;
	getRowColbyLeftClick(r, c);
	if (r < 45 && c<95)
		return false;
	else if (r > 55 && c > 105)
		return false;
	return true;
}
bool promote()
{
	int r, c;
	getRowColbyLeftClick(r, c);
	if (r < 15 && c<95)
		return false;
	else if (r > 25 && c > 105)
		return false;
	return true;
}
bool reply()
{
	int r, c;
	getRowColbyLeftClick(r, c);
	if (r < 35 && c<95)
		return false;
	else if (r > 45 && c > 105)
		return false;
	return true;
}

/*

----------------------------------------------->Legality || Moves <---------------------------------------------
														 ||
														 ||
														 ||
														 ||
														 ||
														 ||
														 ||
														 \/
*/
bool isDiagPC(char** B, position sC, position dC)
{
	if (isLeftdiagPC(B, sC, dC) || isRightdiagPC(B, sC, dC))
	{
		return true;
	}
	return false;
}
bool rookLegal(char** B, position sC, position dC)
{
	return (isHor(sC, dC) && isHorPC(B, sC, dC)) || (isVer(sC, dC) && isVerPC(B, sC, dC));
}
bool bishopLegal(char** B, position sC, position dC)
{
	return isDiag(sC, dC) && isDiagPC(B, sC, dC);
}
bool queenLegal(char** B, position sC, position dC)
{
	return rookLegal(B, sC, dC) && bishopLegal(B, sC, dC);
}
bool kingLegal(char** B, position sC, position dC)
{
	int delR, delC;
	delC = abs(dC.ci - sC.ci);
	delR = abs(dC.ri - sC.ri);
	return queenLegal(B, sC, dC) || delC <= 1 && delR <= 1;
}
bool knightLegal(char** B, position sC, position dC, int turn)
{
	int delR, delC;
	delC = abs(dC.ci - sC.ci);
	delR = abs(dC.ri - sC.ri);
	if (turn == 0)
	{
		if (delR == 2 && delC == 1 && sC.ri > dC.ri)
		{
			return true;
		}
		return false;
	}
	else
	{
		if (delR == 2 && delC == 1 && sC.ri < dC.ri)
		{
			return true;
		}
		return false;
	}

	return (delR == 2 && delC == 1) || (delR == 1 && delC == 2);
}
bool pawnLegal(char** B, position sC, position dC, int turn)
{
	int delR = abs(dC.ri - sC.ri);
	if (turn == 0)
	{
		if (isVer(sC, dC) && delR == 1 && sC.ri > dC.ri)
		{
			return true;
		}
		return false;
	}
	else
	{
		if (isVer(sC, dC) && delR == 1 && sC.ri < dC.ri)
		{
			return true;
		}
		return false;
	}


}
bool lanceLegal(char** B, position sC, position dC, int turn)
{
	if (turn == 0)
	{
		if (isVer(sC, dC) && isVerPC(B, sC, dC) && sC.ri > dC.ri)
		{
			return true;
		}
		return false;
	}
	else
	{
		if (isVer(sC, dC) && isVerPC(B, sC, dC) && sC.ri < dC.ri)
		{
			return true;
		}
		return false;
	}
}
bool goldGenLegal(char** B, position sC, position dC, int turn)
{
	int delR, delC;
	delC = abs(dC.ci - sC.ci);
	delR = abs(dC.ri - sC.ri);
	if (turn == 0)
	{
		if ((bishopLegal(B, sC, dC) && sC.ri > dC.ri) && delR <= 1 && delC <= 1 || rookLegal(B, sC, dC) && delR <= 1 && delC <= 1)
		{
			return true;
		}
		return false;
	}
	else
	{
		if ((bishopLegal(B, sC, dC) && sC.ri < dC.ri) && delR <= 1 && delC <= 1 || rookLegal(B, sC, dC) && delR <= 1 && delC <= 1)
		{
			return true;
		}
		return false;
	}


}
bool silvGenLegal(char** B, position sC, position dC, int turn)
{
	int delR, delC;
	delC = abs(dC.ci - sC.ci);
	delR = abs(dC.ri - sC.ri);
	if (turn == 0)
	{
		if ((bishopLegal(B, sC, dC) && delR == 1 && delC == 1) || pawnLegal(B, sC, dC, turn) && sC.ri > dC.ri)
		{
			return true;
		}
		return false;
	}
	else
	{
		if ((bishopLegal(B, sC, dC) && delR == 1 && delC == 1) || pawnLegal(B, sC, dC, turn) && sC.ri < dC.ri)
		{
			return true;
		}
		return false;
	}


}
bool dragonRookLegal(char** B, position sC, position dC)
{
	if (rookLegal(B, sC, dC) || kingLegal(B, sC, dC))
		return true;
	return false;
}
bool dragonBishopLegal(char** B, position sC, position dC)
{
	if (bishopLegal(B, sC, dC) || kingLegal(B, sC, dC))
		return true;
	return false;
}
bool Legality(char** B, position sC, position dC, int turn)
{
	if (turn == 0)
	{
		switch (B[sC.ri][sC.ci])
		{
		case('R'):
			return rookLegal(B, sC, dC);
			break;
		case('B'):
			return bishopLegal(B, sC, dC);
			break;
		case('L'):
			return lanceLegal(B, sC, dC, turn);
			break;
		case('H'):
			return knightLegal(B, sC, dC, turn);
			break;
		case('S'):
			return silvGenLegal(B, sC, dC, turn);
			break;
		case('G'):
			return goldGenLegal(B, sC, dC, turn);
			break;
		case('K'):
			return kingLegal(B, sC, dC);
			break;
		case('P'):
			return pawnLegal(B, sC, dC, turn);
			break;
		case('O'):
			return goldGenLegal(B, sC, dC, turn);
			break;
		case('X'):
			return dragonRookLegal(B, sC, dC);
			break;
		case('Z'):
			return dragonBishopLegal(B, sC, dC);
			break;
		default:
			return false;
		}
		return false;
	}
	else if (turn == 1)
	{
		switch (B[sC.ri][sC.ci])
		{
		case('r'):
			return rookLegal(B, sC, dC);
			break;
		case('b'):
			return bishopLegal(B, sC, dC);
			break;
		case('l'):
			return lanceLegal(B, sC, dC, turn);
			break;
		case('h'):
			return knightLegal(B, sC, dC, turn);
			break;
		case('s'):
			return silvGenLegal(B, sC, dC, turn);
			break;
		case('g'):
			return goldGenLegal(B, sC, dC, turn);
			break;
		case('k'):
			return kingLegal(B, sC, dC);
			break;
		case('p'):
			return pawnLegal(B, sC, dC, turn);
			break;
		case('o'):
			return goldGenLegal(B, sC, dC, turn);
			break;
		case('x'):
			return dragonRookLegal(B, sC, dC);
			break;
		case('z'):
			return dragonBishopLegal(B, sC, dC);
			break;
		default:
			return false;

		}
		return false;

	}
}
void updateSingleBox(position sC, int dim)
{
	int r = sC.ri;
	int c = sC.ci;

	for (int i = (r * brows) + 1; i < (r * brows + brows) - 1; i++)
	{
		for (int j = (c * bcols) + 1; j < (c * bcols + bcols) - 1; j++)
		{
			int prntRows = (r * brows) + 1;
			int prntCols = (c * bcols) + 1;
			SetClr(14);
			gotoRowCol(prntRows, prntCols);
			cout << char(-37);
		}
	}


}


/*

							/\							 /\									  /\
							||							 ||									  ||
							||							 ||									  ||
							||							 ||									  ||
							||							 ||									  ||
							||							 ||									  ||
							||							 ||									  ||
							||  						 ||									  ||
----------------------------||-------------------------> || <---------------------------------||------------------
*/

bool isFound(char** B, char* droP1, char* droP2, char sym, int turn)
{
	if (turn == 0)
	{
		for (int i = 0; i < 19; i++)
		{
			if (droP1[i] == sym)
				return true;
		}
		return false;
	}
	else
	{
		for (int i = 0; i < 19; i++)
		{
			if (droP1[i] == sym)
				return true;
		}
		return false;
	}
}
position findKing(char** B, position& dC, int dim, int turn)
{
	if (turn == 0)
	{
		for (int i = 0; i < dim; i++)
		{
			for (int j = 0; j < dim; j++)
			{
				if (B[i][j] == 'k')
					dC.ri = i, dC.ci = j;
			}
		}
	}
	else
	{
		for (int i = 0; i < dim; i++)
		{
			for (int j = 0; j < dim; j++)
			{
				if (B[i][j] == 'K')
					dC.ri = i, dC.ci = j;
			}
		}
	}
	return dC;
}
bool check(char** B, position sC, int dim, int turn)
{
	position D;

	turnChng(turn);
	D = findKing(B, D, dim, turn);
	turnChng(turn);
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			sC.ri = i, sC.ci = j;
			if (isValidSrc(sC, B, dim, turn) == true)
			{
				if (Legality(B, sC, D, turn) == true)
					return true;
			}
		}
	}
	return false;
}
bool selfCheck(char** B, position sC, position dC, int dim, int turn)
{
	turnChng(turn);
	return check(B, sC, dim, turn);
}
bool checkpos(char** B, position sC, int dim, int turn)
{
	position D;
	bool** bMap;
	bMap = new bool* [dim];
	for (int i = 0; i < dim; i++)
		bMap[i] = new bool[dim] {};

	for (int r = 0; r < dim; r++)
	{
		for (int c = 0; c < dim; c++)
		{
			D.ri = r, D.ci = c;
			if (Legality(B, sC, D, turn) && isValidDes(D, B, dim, turn))
			{
				bMap[r][c] = true;
			}
		}
	}
	return bMap;
}
bool checkpos1(char** B, bool**& bMap, position sC, int dim, int turn)
{

	position D;
	bMap = new bool* [dim];
	for (int i = 0; i < dim; i++)
		bMap[i] = new bool[dim] {};

	for (int r = 0; r < dim; r++)
	{
		for (int c = 0; c < dim; c++)
		{
			D.ri = r, D.ci = c;
			if (isValidDes(D, B, dim, turn) && Legality(B, sC, D, turn))
			{
				bMap[r][c] = true;
			}
		}
	}
	return bMap;
}
void highlight(char** B, bool** bMap, position sC, int dim, int turn)
{

	for (int r = 0; r < dim; r++)
	{
		for (int c = 0; c < dim; c++)
		{
			if (bMap[r][c] == true)
			{
				doClr(r, c);
			}
		}
	}
}
bool capture(char** B, position sC, position dC, int turn)
{
	if (turn == 0)
	{
		if (Legality(B, sC, dC, turn) == true)
		{
			if (B[dC.ri][dC.ci] >= 'a' && B[dC.ri][dC.ci] <= 'z')
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		if (Legality(B, sC, dC, turn) == true)
		{
			if (B[dC.ri][dC.ci] >= 'A' && B[dC.ri][dC.ci] <= 'Z')
			{
				return true;
			}
		}
		return false;
	}
}
void do_capture(char** B, position sC, position dC, int turn)
{
	if (capture(B, sC, dC, turn) == true)
	{
		if (turn == 0)
		{
			B[dC.ri][dC.ci] = B[sC.ri][sC.ci];
			B[sC.ri][sC.ci] = '-';
			return;
		}
		else
		{
			B[dC.ri][dC.ci] = B[sC.ri][sC.ci];
			B[sC.ri][sC.ci] = '-';
			return;
		}
	}
}
void promotions(char** B, position sC, position dC, int dim, int turn)
{
	if (turn == 0)
	{

		for (int ri = 0; ri < dim; ri++)
		{
			for (int ci = 0; ci < dim; ci++)
			{
				if (ri < 3)
				{
					switch (B[dC.ri][dC.ci])
					{
					case('L'):
						B[dC.ri][dC.ci] = 'O';
						return;
					case('P'):
						B[dC.ri][dC.ci] = 'O';
						return;
					case('S'):
						B[dC.ri][dC.ci] = 'O';
						return;
					case('H'):
						B[dC.ri][dC.ci] = 'O';
						return;
					case('R'):
						B[dC.ri][dC.ci] = 'X';
						return;
					case('B'):
						B[dC.ri][dC.ci] = 'Z';
						return;
					default:
						return;

					}
				}
			}
		}

	}
	else
	{

		for (int ri = 0; ri < dim; ri++)
		{
			for (int ci = 0; ci < dim; ci++)
			{
				if (ri > 5)
				{
					switch (B[dC.ri][dC.ci])
					{
					case('l'):
						B[dC.ri][dC.ci] = 'o';
						return;
					case('p'):
						B[dC.ri][dC.ci] = 'o';
						return;
					case('s'):
						B[dC.ri][dC.ci] = 'o';
						return;
					case('h'):
						B[dC.ri][dC.ci] = 'o';
						return;
					case('r'):
						B[dC.ri][dC.ci] = 'x';
						return;
					case('b'):
						B[dC.ri][dC.ci] = 'z';
						return;
					default:
						return;

					}
				}
			}
		}
	}
}
bool ispromote(char** B, position sC, position dC, int dim, int turn)
{
	if (turn == 0)
	{
		if (isWhitePiece(B[dC.ri][dC.ci]) == true)
			if (B[dC.ri][dC.ci] == 'O' || B[dC.ri][dC.ci] == 'X' || B[dC.ri][dC.ci] == 'Z')
				return false;
		if (dC.ri < 3)
			return true;
		return false;
	}
	else
	{
		if (isBlackPiece(B[dC.ri][dC.ci]) == true)
			if (B[dC.ri][dC.ci] == 'o' || B[dC.ri][dC.ci] == 'x' || B[dC.ri][dC.ci] == 'z')
				return false;
		if (dC.ri > 5)
			return true;
		return false;
	}
}
bool pawnCheck(char** B, position sC, position dC, int turn)
{
	if (turn == 0)
	{
		if (sC.ri < dC.ri)
		{
			for (int rows = sC.ri + 1; rows < dC.ri; rows++)
			{
				if (B[rows][sC.ci] != 'P')
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			for (int rows = dC.ri + 1; rows < sC.ri; rows++)
			{
				if (B[rows][sC.ci] != 'P')
				{
					return false;
				}
			}
			return true;
		}
	}
	else
	{
		if (sC.ri < dC.ri)
		{
			for (int rows = sC.ri + 1; rows < dC.ri; rows++)
			{
				if (B[rows][sC.ci] != 'p')
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			for (int rows = dC.ri + 1; rows < sC.ri; rows++)
			{
				if (B[rows][sC.ci] != 'p')
				{
					return false;
				}
			}
			return true;
		}
	}

}
bool isValidDropCordP1(char** B, position sC, int turn)
{
	if (sC.ri != 0 && sC.ci > 10)
		return false;
	else if (sC.ri != 10 && sC.ci > 9)
		return false;
	return(isMyTurn(B[sC.ri][sC.ci], turn));
}
bool isValidDropCordP2(char** B, position sC, int turn)
{
	if (sC.ri != 2 && sC.ci > 10)
		return false;
	else if (sC.ri != 10 && sC.ci > 9)
		return false;
	return(isMyTurn(B[sC.ri][sC.ci], turn));
}
void dropCordPlayer1(position& sC)
{
	int r, c;
	getRowColbyLeftClick(r, c);
	if (r >= 100 && r < 110)
	{
		r = r / bcols;
		sC.ri = r % bcols;
		sC.ci = c / bcols;
	}
	else if (r >= 110 && r < 120)
	{
		r = r / bcols;

		sC.ri = r - 1;
		sC.ci / c / bcols;
	}
}
void dropCordPlayer2(position& sC)
{
	int r, c;
	getRowColbyLeftClick(r, c);
	if (r >= 120 && r < 130)
	{
		r = r / bcols;
		sC.ri = r % bcols;
		sC.ci = c / bcols;
	}
	else if (r >= 130 && r < 140)
	{
		r = r / bcols;

		sC.ri = r - 3;
		sC.ci / c / bcols;
	}
}
bool isValidDesDropP1(char** B, position sC, position dC, int dim, int turn)
{
	if (pawnCheck(B, sC, dC, turn) == true)
	{
		if (check(B, sC, dim, turn) == false)
		{
			if (isValidDes(dC, B, dim, turn) == true)
			{
				return true;
			}
		}
	}
	return false;
}
bool isValidDesDropP2(char** B, position sC, position dC, int dim, int turn)
{
	if (pawnCheck(B, sC, dC, turn) == true)
	{
		if (check(B, sC, dim, turn) == false)
		{
			if (isValidDes(dC, B, dim, turn) == true)
			{
				return true;
			}
		}
	}
	return false;
}
void dropping(char** B, char d1[], char d2[], position sC, position dC, int dim, int turn)
{
	if (turn == 0)
	{
		do
		{
			do
			{
				dropCordPlayer1(sC);
			} while (isValidDropCordP1(B, sC, turn) == false);
			sel_des(dC, dim);
		} while (isValidDesDropP1(B, sC, dC, dim, turn) == false);
	}
	else
	{
		do
		{
			do
			{
				dropCordPlayer2(sC);
			} while (isValidDropCordP2(B, sC, turn) == false);
			sel_des(dC, dim);
		} while (isValidDesDropP2(B, sC, dC, dim, turn) == false);
	}
}
void undoBord(char***& uB, char** B, int dim, int c)
{
	for (int i = c; i < c - 1; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			for (int k = 0; k < dim; k++)
			{
				uB[i][j][k] = B[j][k];
			}
		}
	}
}
void undomooo(char** nB, position S, position D)
{
	nB[D.ri][D.ci] = nB[S.ri][S.ci];
	nB[D.ri][D.ci] = '-';
}
void undomv(char*** uB, char**& B, int dim, int c)
{
	for (int i = c; i < c - 1; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			for (int k = 0; k < dim; k++)
			{
				B[j][k] = uB[i][j][k];
			}
		}
	}
}
void copyMove(char** B, char**& nB, position sC, position dC, int dim, int turn)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			nB[i][j] = B[i][j];
		}
	}
	nB[dC.ri][dC.ci] = nB[sC.ri][sC.ci];
	nB[sC.ri][sC.ci] = '-';



}
bool checkMate(char** B, char** nB, position sC, int dim, int turn)
{
	position D;
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			D.ri = i, D.ci = j;
			if (isValidDes(D, nB, dim, turn) == true)
			{
				copyMove(B, nB, sC, D, dim, turn);
				if (check(nB, sC, dim, turn) == false)
				{
					return false;
				}
			}
		}
	}
}


int main()
{
	cout << "\n\nread the intructions carefully....\n\n";
	cout << "\n\nIf you want to undo tap on red box........\n\n";
	cout << "\n\nif you want reply tap on Blue box.......\n\n";
	cout << "\n\nif You want to promote tape on purple one......\n\n";
	cout << "\n\nIf you wanna drop a piece then tap on green box.........\n\n";
	cout << "\n\nRemember the color scheme........\n\n";
	cout << "\n\nPress any key to continue......\n\n";
	_getch();
	system("cls");
	char** B, ** nB;
	char*** uB;
	char dP1[19], dP2[19], game;
	position sC, dC;
	string pNam[2];
	int turn, dim;
	bool** bMap;
	int cp1 = 0, cp2 = 0, cpp1 = 0, cpp2 = 0, dro = -1;
	int count = 0;

	while (true)
	{
		cout << "Do you want to play from where you left(Y/N): ";
		cin >> game;
		if (game == 'y' || game == 'Y')
		{

			initLaod(B, nB, dP1, dP2, pNam, dim, turn);
			printPromoteButton();
			printUndoButton();
			printDropButton();
			printReplyButton();
			drawBoard(dim);
			compBoard(B, dim, 4, 4);
			do
			{
				do {

					turnMsg(pNam, turn);
					do {
						do
						{
							prntBound(0, 0);
							sel_src(sC, dim);
						} while (isValidSrc(sC, B, dim, turn) == false);
						checkpos1(B, bMap, sC, dim, turn);
						highlight(B, bMap, sC, dim, turn);
						sel_des(dC, dim);
						if (capture(B, sC, dC, turn) == true && isValidDes(dC, B, dim, turn) == true)
						{
							dro = 1;
							dropArr(B, dC, dP1, dP2, cp1, cp2, turn);
							dispdrop(dP1, dP2, cp1, cp2, cpp1, cpp2, dim, turn);
							if (turn == 0)
							{
								cp1++;
								if (cp1 >= 9)
									cpp1++;
							}
							else
							{
								cp2++;
								if (cp2 >= 9)
									cpp2++;
							}
						}

					} while (isValidDes(dC, B, dim, turn) == false);
				} while (Legality(B, sC, dC, turn) == false);
				if (check(B, sC, dim, turn) == true)
				{
					gotoRowCol(6, 90);
					cout << pNam[turn] << "is in check You are in check";
				}
				if (checkMate(B, nB, sC, dim, turn) == true)
					break;

				updateBoard(B, sC, dC);
				if (ispromote(B, sC, dC, dim, turn) == true)
				{
					if (promote() == true)
						promotions(B, sC, dC, dim, turn);
				}
				drawBoard(dim);
				undoBord(uB, B, dim, count);

				compBoard(B, dim, 4, 4);
				saving(B, dP1, dP2, pNam, dim, turn);
				count++;
				turn = turnChng(turn);

			} while (true);
			cout << "PLayer " << pNam[turn] << "Has won the game";

		}
		//New Game
		else if (game == 'n' || game == 'N')
		{

			init(B, nB, uB, dP1, dP2, pNam, dim, turn);
			printPromoteButton();
			printUndoButton();
			printDropButton();
			printReplyButton();
			drawBoard(dim);
			compBoard(B, dim, 4, 4);
			do
			{
				do {
					do {


						turnMsg(pNam, turn);
						do {
							do
							{

								prntBound(0, 0);
								sel_src(sC, dim);
							} while (isValidSrc(sC, B, dim, turn) == false);
							checkpos1(B, bMap, sC, dim, turn);
							highlight(B, bMap, sC, dim, turn);
							sel_des(dC, dim);
							if (capture(B, sC, dC, turn) == true && isValidDes(dC, B, dim, turn) == true)
							{
								dro = 1;
								dropArr(B, dC, dP1, dP2, cp1, cp2, turn);
								dispdrop(dP1, dP2, cp1, cp2, cpp1, cpp2, dim, turn);
								if (turn == 0)
								{
									cp1++;
									if (cp1 >= 9)
										cpp1++;
								}
								else
								{
									cp2++;
									if (cp2 >= 9)
										cpp2++;
								}
							}

						} while (isValidDes(dC, B, dim, turn) == false);
					} while (Legality(B, sC, dC, turn) == false);
					updateBoard(nB, sC, dC);
				} while (selfCheck(B, sC, dC, dim, turn) == true);
				updateBoard(B, sC, dC);
				if (check(B, sC, dim, turn) == true)
				{
					gotoRowCol(6, 90);
					cout << "Check";
				}
				if (ispromote(B, sC, dC, dim, turn) == true)
				{
					if (promote() == true)
						promotions(B, sC, dC, dim, turn);
				}
				drawBoard(dim);
				undoBord(uB, B, dim, count);

				compBoard(B, dim, 4, 4);
				saving(B, dP1, dP2, pNam, dim, turn);
				count++;
				turn = turnChng(turn);

			} while (true);
			cout << "PLayer " << pNam[turn] << "Has won the game";
		}
		else
			cout << "Sorry wrong input......Plzzz try again:\n\n ";
	}
	return 0;
}




