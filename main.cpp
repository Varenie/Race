#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>// для замедление игры

using namespace std;

const int width = 20;//размерность поля: ширина
const int height = 20;//размерность поля: высота

int x, y;//переменные для машины игрока
int xcar1, ycar1, xcar2, ycar2, xcar3, ycar3, xcar4, ycar4, xcar5, ycar5, xcar6, ycar6, xcar7, ycar7 ;//переменные для машин компьютера


enum movement { STOP = 0, UP, DOWN, LEFT, RIGHT };//перечисление для движения
movement mov;

bool game_over;
int score;

void Setup()
{
	srand(time(NULL));
	game_over = false;
	mov = STOP;//переменная движения
	x = width / 2 - 1;//задание координаты x для отображения машины игрока
	y = height - 1;//задание координаты y для отображения машины игрока

	xcar1 = rand() % width;//задание координаты x для отображения машины компьютера 1
	ycar1 = rand() % height;//задание координаты y для отображения машины компьютера 1

	xcar2 = rand() % width;
	ycar2 = rand() % height;

	xcar3 = rand() % width;
	ycar3 = rand() % height;

	xcar4 = rand() % width;
	ycar4 = rand() % height;

	xcar5 = rand() % width;
	ycar5 = rand() % height;

	xcar6 = rand() % width;
	ycar6 = rand() % height;

	xcar7 = rand() % width;
	ycar7 = rand() % height;

	score = 0;
}

void Draw()
{
	system("cls");//очищение карты при каждом вызове функции

	for (int i = 0; i < width + 1; i++)//верхняя граница карты
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)//отображение боковых границ карты
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
				cout << "#";
			if (i == y && j == x)//отображение машины игрока
				cout << "@";
			if (i == ycar1 && j == xcar1)//отображение машины компьютера 1
				cout << "C";
			if (i == ycar2 && j == xcar2)
				cout << "C";
			if (i == ycar3 && j == xcar3)
				cout << "C";
			if (i == ycar4 && j == xcar4)
				cout << "C";
			if (i == ycar5 && j == xcar5)
				cout << "C";
			if (i == ycar6 && j == xcar6)
				cout << "C";
			if (i == ycar7 && j == xcar7)
				cout << "C";
			cout << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 1; i++)//нижняя граница карты
		cout << "#";
	cout << endl;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())//определение клавиш и присваивание соответсвующего значения
		{
		case 'a':
			mov = LEFT;
			break;
		case 's':
			mov = DOWN;
			break;
		case 'd':
			mov = RIGHT;
			break;
		case 'w':
			mov = UP;
			break;
		case 'x':
			game_over = true;
			break;
		}
	}


}

void Logic()
{
	switch (mov)//движения
	{
	case UP:
		y--;
		mov = STOP;
		break;
	case DOWN:
		y++;
		mov = STOP;
		break;
	case LEFT:
		x--;
		mov = STOP;
		break;
	case RIGHT:
		x++;
		mov = STOP;
		break;
	}

	if (x > height || x < 0 || y > width || y < 0)// проверка на выход из поля
		game_over = true;

	if ((x == xcar1 && y == ycar1) || (x == xcar2 && y == ycar2) || (x == xcar3 && y == ycar3) || (x == xcar4 && y == ycar4) || (x == xcar5 && y == ycar5) || (x == xcar6 && y == ycar6) || (x == xcar7 && y == ycar7))
		game_over = true;

	ycar1++;//перемещение машинок
	ycar2++;
	ycar3++;
	ycar4++;
	ycar5++;
	ycar6++;
	ycar7++;


	if (ycar1 > width)// "возрождение" машинок
	{
		ycar1 = 0;
		xcar1 = rand() % width;
	}
	if (ycar2 > width)
	{
		ycar2 = 0;
		xcar2 = rand() % width;
	}
	if (ycar3 > width)
	{
		ycar3 = 0;
		xcar3 = rand() % width;
	}
	if (ycar4 > width)
	{
		ycar4 = 0;
		xcar4 = rand() % width;
	}
	if (ycar5 > width)
	{
		ycar5 = 0;
		xcar5 = rand() % width;
	}
	if (ycar6 > width)
	{
		ycar6 = 0;
		xcar6 = rand() % width;
	}
	if (ycar7 > width)
	{
		ycar7 = 0;
		xcar7 = rand() % width;
	}

}


int main()
{
	Setup();//вызов функции предустановки
	while (!game_over)//поочередный вызов функции отрисовки карты, ввода данных и логики пока игра не завершилась
	{
		Draw();
		Input();
		Logic();
		score++;//подсчет очков
		cout << score;//вывод количества очков онлайн
		Sleep(50);
	}
	
	system("cls");
	cout << "Your score: " << score << endl;
	cout << "Game Over" << endl;
	system("pause");
	return 0;
}