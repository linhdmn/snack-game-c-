/*  SNAKE GAME PROGRAM */




/*************************************************

Application: Snake Game
Compiled on: Visual Studio 2013
Programmer : Manish Kumar
OS         : Window 98,2000,XP
             Vista,Windows7

***************************************************/




/* Declaration of Header Files */

#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "dos.h"
#include "time.h"
#include "windows.h"
#include "string.h"

#define right 0
#define left 1
#define up 2
#define down 3


/* Global Declaration */

int x[100], y[100], i, length = 6, score = 0, l_k = right, eat = 0, xf, yf;
char ch;

/* Declaration of Functions */

void Food(void);
void Food1(void);
void Food2(void);
void rectangle(int x, int y, int l, int b);
void fillcolor(int x1, int y1, int x2, int y2);
void rectangle1(int x, int y, int l, int b);
void Level1(void);
void Level2(void);
void Level3(void);
void Level4(void);
void Instruction(void);
void Start(void);
void gotoxy(int x, int y);
COORD coord = { 0, 0 };

void main()
{
	system("cls");
	Start();
	Instruction();
	Level1();
	_getch();
}
/* Level 2 */

void Level2(void)
{
	
	system("cls");
	/* Positioning the snake initally */

	for (i = length - 1; i &gt;= 0; i--)
	{
		x[i] = 25 - i;
		y[i] = 15;
	}

	/*************************************/
    START:
	
	gotoxy(65, 3);
	printf("%c",219);
	rectangle(1, 1, 60, 24);
	rectangle1(63, 13, 78, 18);
	rectangle1(63, 1, 78, 6);
	rectangle1(63, 7, 78, 12);
	rectangle1(63, 19, 78, 24);
	
	gotoxy(66, 3);
	printf("SNAKE GAME%c",219);
	gotoxy(67, 8);
	printf(" LEVEL ");
	gotoxy(70, 10);
	printf("2");
	gotoxy(67, 14);
	printf(" SCORE ");
	gotoxy(65, 3);

	/*********************************/



	while (1)  /* Infinite Loop    */
	{
		while (_kbhit() == 0) /* Do Nothing */
		{
			gotoxy(69, 16);
			printf("%d", score);
			
			for (i = length - 1; i&gt;0; i--)
			{
				x[i] = x[i - 1];
				y[i] = y[i - 1];
			}
			/* Snake Structure */

			for (i = length - 1; i &gt;= 0; i--)
			{
				gotoxy(x[i], y[i]);
				printf("0");
			}
			gotoxy(x[0], y[0]);
			printf("#");
			gotoxy(x[length - 1], y[length - 1]);
			printf(" ");
			Food();
			if (l_k == right || l_k == left)
			{
				Sleep(80);
			}
			if (l_k == up || l_k == down)
			{
				Sleep(130);
			}
			/* Hit the Wall */

			if (x[0] == 1 || x[0] == 60 || y[0] == 1 || y[0] == 24)
			{
				Sleep(1000);
				gotoxy(65, 21);
				printf("  GAME OVER  ");
				gotoxy(65, 3);
				Sleep(1000);
				system("cls");
				exit(0);
			}
			if (l_k == right)
			{
				x[0]++;
			}
			if (l_k == left)
			{
				x[0]--;
			}
			if (l_k == up)
			{
				y[0]--;
			}
			if (l_k == down)
			{
				y[0]++;
			}
			/* Hit yourself */
			for (i = length - 1; i&gt;1; i--)
			{
				if (x[0] == x[i] &amp;&amp; y[0] == y[i])
				{
					
					Sleep(1000);
					gotoxy(65, 21);
					printf("  GAME OVER  ");
					gotoxy(65, 3);
					Sleep(1000);
					system("cls");
					exit(0);
				}
			}
		}
		ch = _getch();
		if (ch == 32)
		{
		
			gotoxy(65, 21);
			printf("%c PAUSED... %c",219,219);
			while (_kbhit() == 0)
				gotoxy(65, 21);
			printf("  ");
			
			system("cls");
			goto START;
		}
		if (ch == 27)
		{
			
			Sleep(1000);
			gotoxy(65, 21);
			printf(" GAME OVER ");
			gotoxy(65, 3);
			Sleep(1000);
			system("cls");
			exit(0);
		}
		else if (ch == 72 &amp;&amp; l_k != down)
			l_k = up;
		else if (ch == 80 &amp;&amp; l_k != up)
			l_k = down;
		else if (ch == 77 &amp;&amp; l_k != left)
			l_k = right;
		else if (ch == 75 &amp;&amp; l_k != right)
			l_k = left;
		gotoxy(65, 3);
		if (score == 180)
		{
			Sleep(30);
			system("cls");
			gotoxy(27, 12);
			printf("Level 2 has been completed.");
			Sleep(2000);
			Level3();
		}
	}
}

/* Level 1 */

void Level1(void)
{
	system("cls");

	/* Positioning the snake initally */

	for (i = length - 1; i &gt;= 0; i--)
	{
		x[i] = 25 - i;
		y[i] = 15;
	}

	/*************************************/
    START:
	
	gotoxy(65, 3);
	printf("%c",219);
	rectangle1(1, 1, 60, 24);
	rectangle1(63, 13, 78, 18);
	rectangle1(63, 1, 78, 6);
	rectangle1(63, 7, 78, 12);
	rectangle1(63, 19, 78, 24);
	
	gotoxy(66, 3);
	printf("SNAKE GAME%c",219);
	gotoxy(67, 8);
	printf(" LEVEL ");
	gotoxy(70, 10);
	printf("1");
	gotoxy(67, 14);
	printf(" SCORE ");
	gotoxy(65, 3);

	/*********************************/



	while (1)  /* Infinite Loop    */
	{
		while (_kbhit() == 0) /* Do Nothing */
		{
			gotoxy(69, 16);
			printf("%d", score);
			
			for (i = length - 1; i&gt;0; i--)
			{
				x[i] = x[i - 1];
				y[i] = y[i - 1];
			}
			/* Snake Structure */

			for (i = length - 1; i &gt;= 0; i--)
			{
				gotoxy(x[i], y[i]);
				printf("0");
			}
			gotoxy(x[0], y[0]);
			printf("#");
			gotoxy(x[length - 1], y[length - 1]);
			printf(" ");
			Food();
			if (l_k == right || l_k == left)
			{
				Sleep(80);
			}
			if (l_k == up || l_k == down)
			{
				Sleep(130);
			}
			/****************************/
			rectangle1(1, 1, 60, 24);
			gotoxy(65, 3);
			if (x[0] == 1)
			{
				rectangle1(1, 1, 60, 24);
				x[0] = 59;
			}
			if (x[0] == 60)
			{
				rectangle1(1, 1, 60, 24);
				x[0] = 2;
			}
			if (y[0] == 1)
			{
				rectangle1(1, 1, 60, 24);
				y[0] = 23;
			}
			if (y[0] == 24)
			{
				rectangle1(1, 1, 60, 24);
				y[0] = 2;
			}
			/*******************************/

			if (l_k == right)
			{
				x[0]++;
			}
			if (l_k == left)
			{
				x[0]--;
			}
			if (l_k == up)
			{
				y[0]--;
			}
			if (l_k == down)
			{
				y[0]++;
			}
			/* Hit yourself */
			for (i = length - 1; i&gt;1; i--)
			{
				if (x[0] == x[i] &amp;&amp; y[0] == y[i])
				{
					
					Sleep(1000);
					gotoxy(65, 21);
					printf("  GAME OVER  ");
					gotoxy(65, 3);
					Sleep(1000);
					system("cls");
					exit(0);
				}
			}
		}
		ch = _getch();
		if (ch == 32)
		{
			
			gotoxy(65, 21);
			printf("%c PAUSED... %c",219,219);
			while (_kbhit() == 0)
				gotoxy(65, 21);
			printf("  ");
			
			system("cls");
			goto START;
		}
		if (ch == 27)
		{
			
			Sleep(1000);
			gotoxy(65, 21);
			printf(" GAME OVER ");
			gotoxy(65, 3);
			Sleep(1000);
			exit(0);
		}
		else if (ch == 72 &amp;&amp; l_k != down)
			l_k = up;
		else if (ch == 80 &amp;&amp; l_k != up)
			l_k = down;
		else if (ch == 77 &amp;&amp; l_k != left)
			l_k = right;
		else if (ch == 75 &amp;&amp; l_k != right)
			l_k = left;
		gotoxy(65, 3);
		if (score == 90)
		{
			Sleep(30);
			system("cls");
			gotoxy(27, 12);
			printf("Level 1 has been completed.");
			Sleep(2000);
			Level2();
		}
	}
}


/* Level 3 */

void Level3(void)
{
	int t;
	
	system("cls");

	/* Positioning the snake initally */

	for (i = length - 1; i &gt;= 0; i--)
	{
		x[i] = 25 - i;
		y[i] = 15;
	}

	/*************************************/
    START:
	
	gotoxy(65, 3);
	printf("%c",219);
	rectangle1(1, 1, 60, 24);
	rectangle1(63, 13, 78, 18);
	rectangle1(63, 1, 78, 6);
	rectangle1(63, 7, 78, 12);
	rectangle1(63, 19, 78, 24);
	for (t = 10; t &lt;= 50; t++) { gotoxy(t, 6); printf("_"); gotoxy(t, 12); printf("_"); gotoxy(t, 18); printf("_"); } gotoxy(66, 3); printf("SNAKE GAME%c",219); gotoxy(67, 8); printf(" LEVEL "); gotoxy(70, 10); printf("3"); gotoxy(67, 14); printf(" SCORE "); gotoxy(65, 3); /*********************************/ while (1) /* Infinite Loop */ { while (_kbhit() == 0) /* Do Nothing */ { gotoxy(69, 16); printf("%d", score); for (i = length - 1; i&gt;0; i--)
			{
				x[i] = x[i - 1];
				y[i] = y[i - 1];
			}
			/* Snake Structure */

			for (i = length - 1; i &gt;= 0; i--)
			{
				gotoxy(x[i], y[i]);
				printf("0");
			}
			gotoxy(x[0], y[0]);
			printf("#");
			gotoxy(x[length - 1], y[length - 1]);
			printf(" ");
			Food1();
			if (l_k == right || l_k == left)
			{
				Sleep(80);
			}
			if (l_k == up || l_k == down)
			{
				Sleep(130);
			}
			/****************************/
			rectangle1(1, 1, 60, 24);
			gotoxy(65, 3);
			if (x[0] == 1)
			{
				rectangle1(1, 1, 60, 24);
				x[0] = 59;
			}
			if (x[0] == 60)
			{
				rectangle1(1, 1, 60, 24);
				x[0] = 2;
			}
			if (y[0] == 1)
			{
				rectangle1(1, 1, 60, 24);
				y[0] = 23;
			}
			if (y[0] == 24)
			{
				rectangle1(1, 1, 60, 24);
				y[0] = 2;
			}
			/********* Hits The Wall **********/
			if ((x[0] &gt;= 10 &amp;&amp; x[0] &lt;= 50 &amp;&amp; y[0] == 6) || (x[0] &gt;= 10 &amp;&amp; x[0] &lt;= 50 &amp;&amp; y[0] == 12) || (x[0] &gt;= 10 &amp;&amp; x[0] &lt;= 50 &amp;&amp; y[0] == 18)) { Sleep(1000); gotoxy(65, 21); printf(" GAME OVER "); gotoxy(65, 3); Sleep(1000); system("cls"); exit(0); } /*******************************/ if (l_k == right) { x[0]++; } if (l_k == left) { x[0]--; } if (l_k == up) { y[0]--; } if (l_k == down) { y[0]++; } /* Hit yourself */ for (i = length - 1; i&gt;1; i--)
			{
				if (x[0] == x[i] &amp;&amp; y[0] == y[i])
				{
					
					Sleep(1000);
					gotoxy(65, 21);
					_cprintf("  GAME OVER  ");
					gotoxy(65, 3);
					Sleep(1000);
					system("cls");
					exit(0);
				}
			}
		}
		ch = _getch();
		if (ch == 32)
		{
			
			gotoxy(65, 21);
			printf("%c PAUSED... %c",219,219);
			while (_kbhit() == 0)
				gotoxy(65, 21);
			printf("  ");
			
			system("cls");
			goto START;
		}
		if (ch == 27)
		{
			
			Sleep(1000);
			gotoxy(65, 21);
			printf(" GAME OVER ");
			gotoxy(65, 3);
			Sleep(1000);
			system("cls");
			exit(0);
		}
		else if (ch == 72 &amp;&amp; l_k != down)
			l_k = up;
		else if (ch == 80 &amp;&amp; l_k != up)
			l_k = down;
		else if (ch == 77 &amp;&amp; l_k != left)
			l_k = right;
		else if (ch == 75 &amp;&amp; l_k != right)
			l_k = left;
		gotoxy(65, 3);
		if (score == 270)
		{
			Sleep(30);
			system("cls");
			gotoxy(27, 12);
			printf("Level 3 has been completed.");
			Sleep(2000);
			Level4();
		}
	}
}

/* Level 4 */

void Level4(void)
{
	int t;
	
	system("cls");

	/* Positioning the snake initally */

	for (i = length - 1; i &gt;= 0; i--)
	{
		x[i] = 45 - i;
		y[i] = 15;
	}

	/*************************************/
    START:
	
	gotoxy(65, 3);
	printf("%c",219);
	rectangle1(1, 1, 60, 24);
	rectangle1(63, 13, 78, 18);
	rectangle1(63, 1, 78, 6);
	rectangle1(63, 7, 78, 12);
	rectangle1(63, 19, 78, 24);
	for (t = 5; t &lt;= 12; t++)
	{
		gotoxy(10, t);
		printf("%c",179);
		gotoxy(50, t);
		printf("%c",179);
	}
	for (t = 17; t &lt;= 21; t++)
	{
		gotoxy(20, t);
		printf("%c",179);
	}
	for (t = 40; t &lt;= 55; t++)
	{
		gotoxy(t, 18);
		printf("%c",95);
	}
	for (t = 20; t &lt;= 40; t++) { gotoxy(t, 7); printf("%c",95); } gotoxy(66, 3); printf("SNAKE GAME%c",219); gotoxy(67, 8); printf(" LEVEL "); gotoxy(70, 10); printf("4"); gotoxy(67, 14); printf(" SCORE "); gotoxy(65, 3); /*********************************/ while (1) /* Infinite Loop */ { while (_kbhit() == 0) /* Do Nothing */ { gotoxy(69, 16); _cprintf("%d", score); for (i = length - 1; i&gt;0; i--)
			{
				x[i] = x[i - 1];
				y[i] = y[i - 1];
			}
			/* Snake Structure */

			for (i = length - 1; i &gt;= 0; i--)
			{
				gotoxy(x[i], y[i]);
				printf("0");
			}
			gotoxy(x[0], y[0]);
			printf("#");
			gotoxy(x[length - 1], y[length - 1]);
			printf(" ");
			Food2();
			if (l_k == right || l_k == left)
			{
				Sleep(80);
			}
			if (l_k == up || l_k == down)
			{
				Sleep(130);
			}
			/****************************/
			rectangle1(1, 1, 60, 24);
			gotoxy(65, 3);
			if (x[0] == 1)
			{
				rectangle1(1, 1, 60, 24);
				x[0] = 59;
			}
			if (x[0] == 60)
			{
				rectangle1(1, 1, 60, 24);
				x[0] = 2;
			}
			if (y[0] == 1)
			{
				rectangle1(1, 1, 60, 24);
				y[0] = 23;
			}
			if (y[0] == 24)
			{
				rectangle1(1, 1, 60, 24);
				y[0] = 2;
			}
			/*************** Hits  the Wall *******************/

			if ((x[0] == 10 &amp;&amp; (y[0] &gt;= 5 &amp;&amp; y[0] &lt;= 12)) || (x[0] == 50 &amp;&amp; (y[0] &gt;= 5 &amp;&amp; y[0] &lt;= 12)) || (x[0] == 20 &amp;&amp; (y[0] &gt;= 17 &amp;&amp; y[0] &lt;= 21))) { Sleep(1000); gotoxy(65, 21); _cprintf(" GAME OVER "); gotoxy(65, 3); Sleep(1000); system("cls"); exit(0); } if (((x[0] &gt;= 40 &amp;&amp; x[0] &lt;= 55) &amp;&amp; y[0] == 18) || ((x[0] &gt;= 20 &amp;&amp; x[0] &lt;= 40) &amp;&amp; y[0] == 7)) { Sleep(1000); gotoxy(65, 21); _cprintf(" GAME OVER "); gotoxy(65, 3); Sleep(1000); system("cls"); exit(0); } /*******************************/ if (l_k == right) { x[0]++; } if (l_k == left) { x[0]--; } if (l_k == up) { y[0]--; } if (l_k == down) { y[0]++; } /* Hit yourself */ for (i = length - 1; i&gt;1; i--)
			{
				if (x[0] == x[i] &amp;&amp; y[0] == y[i])
				{
					
					Sleep(1000);
					gotoxy(65, 21);
					_cprintf("  GAME OVER  ");
					gotoxy(65, 3);
					Sleep(1000);
					system("cls");
					exit(0);
				}
			}
		}
		ch = _getch();
		if (ch == 32)
		{
			
			gotoxy(65, 21);
			printf("%c PAUSED... %c",219,219);
			while (_kbhit() == 0)
				gotoxy(65, 21);
			printf("  ");
			
			system("cls");
			goto START;
		}
		if (ch == 27)
		{
			
			Sleep(1000);
			gotoxy(65, 21);
			_cprintf(" GAME OVER ");
			gotoxy(65, 3);
			Sleep(1000);
			system("cls");
			exit(0);
		}
		else if (ch == 72 &amp;&amp; l_k != down)
			l_k = up;
		else if (ch == 80 &amp;&amp; l_k != up)
			l_k = down;
		else if (ch == 77 &amp;&amp; l_k != left)
			l_k = right;
		else if (ch == 75 &amp;&amp; l_k != right)
			l_k = left;
		gotoxy(65, 3);
	}
}

void Food(void)
{
	if (eat == 0)
	{
		srand(time(NULL));  /* Initializes random number generator  */
		xf = (rand() % (20)) + 4;  /* Generates random number */
		yf = (rand() % (21)) + 3;
		eat = 1;
	}
	if ((xf == 1 || xf == 60) || (yf == 1 || yf == 24))
	{
		xf = 3;
		yf = 3;
	}
	gotoxy(xf, yf);
	printf("*");
	gotoxy(65, 3);
	if ((xf == x[0]) &amp;&amp; (yf == y[0]))
	{
		
		score = score + 9;
		length++;
		eat = 0;
	}
}

void Food1(void)
{
	if (eat == 0)
	{
		srand(time(NULL));  /* Initializes random number generator  */
		xf = (rand() % (20)) + 4;  /* Generates random number */
		yf = (rand() % (21)) + 3;
		eat = 1;
	}
	if ((xf &gt;= 10 &amp;&amp; xf &lt;= 50 &amp;&amp; yf == 6) || (xf &gt;= 10 &amp;&amp; xf &lt;= 50 &amp;&amp; yf == 12) || (xf &gt;= 10 &amp;&amp; xf &lt;= 50 &amp;&amp; yf == 18) || (xf == 1 || xf == 60) || (yf == 1 || yf == 24)) { xf = 5; yf = 3; } gotoxy(xf, yf); printf("*"); gotoxy(65, 3); if ((xf == x[0]) &amp;&amp; (yf == y[0])) { score = score + 9; length++; eat = 0; } } void Food2(void) { if (eat == 0) { srand(time(NULL)); /* Initializes random number generator */ xf = (rand() % (20)) + 4; /* Generates random number */ yf = (rand() % (21)) + 3; eat = 1; } if ((xf == 1 || xf == 60) || (yf == 1 || yf == 24)) { xf = 6; yf = 3; } if ((xf == 10 &amp;&amp; (yf &gt;= 5 &amp;&amp; yf &lt;= 12)) || (xf == 50 &amp;&amp; (yf &gt;= 5 &amp;&amp; yf &lt;= 12)) || (xf == 20 &amp;&amp; (yf &gt;= 17 &amp;&amp; yf &lt;= 21))) { xf = 5; yf = 2; } if (((xf &gt;= 40 &amp;&amp; xf &lt;= 55) &amp;&amp; yf == 18) || ((xf &gt;= 20 &amp;&amp; xf &lt;= 40) &amp;&amp; yf == 7))
	{
		xf = 3;
		yf = 2;

	}



	gotoxy(xf, yf);
	printf("*");
	gotoxy(65, 3);
	if ((xf == x[0]) &amp;&amp; (yf == y[0]))
	{
		
		score = score + 9;
		length++;
		eat = 0;
	}
}

void Start(void)
{
	system("cls");
	fillcolor(3, 3, 76, 23);
	rectangle(2, 2, 78, 24);
	rectangle(3, 2, 77, 24);
	
	gotoxy(35, 5);
	printf(" SNAKE GAME ");
	gotoxy(30, 10);
	printf("Designed and Programmed by:");
	gotoxy(35, 14);
	printf("Manish Kumar");
	gotoxy(35,16);
	printf("Gaurav Anand");
	gotoxy(30, 22);
	printf("Press Any key to Continue...");
	gotoxy(2, 2);
	_getch();
	
}
/* Instruction for the game */

void Instruction(void)
{
	system("cls");
	fillcolor(3, 3, 76, 23);
	rectangle(2, 2, 78, 24);
	rectangle(3, 2, 77, 24);
	
	gotoxy(23, 11);
	printf("Use the arrow keys to change direction.");
	gotoxy(23, 13);
	printf("Press 'Spacebar' to PAUSE and 'Esc' to");
	gotoxy(23, 15);
	printf("EXIT.");
	gotoxy(27, 18);
	printf("Press ENTER to continue...");
	gotoxy(2, 2);
	_getch();
	
}
void rectangle(int x, int y, int l, int b)
{
	int i, j, k, m;
	
	gotoxy(x, y);
	printf("%c", 201);
	for (i = x + 1; i &lt;= l - 1; i++)
	{
		gotoxy(i, y);
		printf("%c", 205);
	}
	gotoxy(l, y);
	printf("%c", 187);
	for (j = y + 1; j &lt;= b - 1; j++) { gotoxy(l, j); printf("%c", 186); } gotoxy(l, b); printf("%c", 188); for (k = l - 1; k &gt;= x + 1; k--)
	{
		gotoxy(k, b);
		printf("%c", 205);
	}
	gotoxy(x, b);
	printf("%c", 200);
	for (m = b - 1; m &gt;= y + 1; m--)
	{
		gotoxy(x, m);
		printf("%c", 186);
	}
}


void rectangle1(int x, int y, int l, int b)
{
	int i, j, k, m;
	
	gotoxy(x, y);
    printf("%c", 218);
	for (i = x + 1; i &lt;= l - 1; i++)
	{
		gotoxy(i, y);
		printf("%c", 196);
	}
	gotoxy(l, y);
	printf("%c", 191);
	for (j = y + 1; j &lt;= b - 1; j++) { gotoxy(l, j); printf("%c", 179); } gotoxy(l, b); printf("%c", 217); for (k = l - 1; k &gt;= x + 1; k--)
	{
		gotoxy(k, b);
		printf("%c", 196);
	}
	gotoxy(x, b);
	printf("%c", 192);
	for (m = b - 1; m &gt;= y + 1; m--)
	{
		gotoxy(x, m);
		printf("%c", 179);
	}
}



void fillcolor(int x1, int y1, int x2, int y2)
{
	int i, j;
	
	for (i = x1; i &lt;= x2; i++)
	{
		for (j = y1; j &lt;= y2; j++)
		{
			gotoxy(i, j);
			printf("%c",177);
		}
	}
}


void gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y; // X and Y coordinates
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
