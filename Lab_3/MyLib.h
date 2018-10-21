#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
	
int RandomInt(int Min, int Max)/*Генерация рандомного числа в заданном диапозоне для целого числа*/
{	
	int random_number;
	return random_number = Min + rand() % (Max - Min)+1;
}

double RandomFloat(double min, double max)/*Генерация рандомного числа в заданном диапозоне для вещественного числа*/
{
	double random_number;
	return random_number = min + (rand() * (max - min)) / RAND_MAX;
}

int Rounding(double number)/*Перевод числа типа float в int по правилам округления*/
{
	int result;
	if (number > 0)
		number = number + 0.5;
	else
		number = number - 0.5;
	result = (int)number;
	return result;
}

double getPercent(double number, double percent)
{
	return (number*percent)/100;
}

void drawPyramid(int i, int N)
{
	for (int j = 0; j < (N-i) / 2 ; j++)
		printf(" ");

	for (int j = 0; j < i; j++)
		printf("^");	

	printf("\n");
	if (i < N) drawPyramid(i + 2, N);

	for (int j = 0; j < (N - i) / 2; j++)
		printf(" ");

	for (int j = 0; j < i; j++)
		printf("^");

	printf("\n");

}

int Stringlength(char* string)/*Подсчет символов в строке*/
{
	int count = 0;
	for (int i = 0; string[i] != '\0'; i++)
	{
		count++;
	}
	return count;
}

void DeleteSymbol(char *string, char *symbol)/*Удаление символа из строки*/
{
	int i, temp;
	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == symbol[0])
		{
			temp = i - 1;
			do
			{
				string[i] = string[i + 1];
				i++;
			} while (string[i] != '\0');
			i = temp;
		}
	}
}


void AddSymbol(char *string, char *symbol)/*Добавление символа в строку*/
{
	int i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	string[i] = symbol[0];
	string[i + 1] = '\0';
}


int FromCharToInt(char *string)/*Перевод из строки в число*/
{
	int i, rank = 1;
	int number = 0;
	int N = Stringlength(string);

	for (i = N - 1; i >= 0; i--)
	{
		int c = string[i] - 0x30;
		number = c * rank + number;
		rank = rank * 10;
	}
	return number;
}

void FromIntToChar(long int number)/*Перевод из числа в строку*/
{
	int j, i, digit;
	char string[100], temp;

	for (i = 0; (number) != 0; i++)
	{
		digit = number % 10;
		number = number / 10;
		string[i] = digit + '0';
	}
	string[i] = '\0';

	digit = Stringlength(string);
	for (i = 0, j = digit - 1; j >= (digit / 2); j--, i++)
	{
		temp = string[i];
		string[i] = string[j];
		string[j] = temp;

	}
	puts(string);
}


/*array function*/

/*int mass*/
void ArrayFillRand(int *mass, int N, int Min, int Max)/*Заполнение массива рандомными числами*/
{
	for (int i = 0; i < N; i++)
	{
		mass[i] = RandomInt(Min, Max);
	}
}

void ArrayFillKey(int *mass, int N)/*Заполнение массива числами с клавиатуры*/
{
	for (int i = 0; i < N; i++)
		scanf_s("%d", &mass[i]);
}

void ArrayOutput(int *mass, int N)/*Вывод массива в консоль*/
{
	for (int i = 0; i < N; i++)
		printf("%d ", mass[i]);
}

void CopyArray(int *mass1, int *mass2, int N)/*Копирование массива*/
{
	for (int i = 0; i < N; i++)
		mass2[i] = mass1[i];
}


/*float mass*/
void FloatArrayFillRand(double *mass, int N, double Min, double Max)/*Заполнение массива рандомными числами*/
{
	for (int i = 0; i < N; i++)
	{
		mass[i] = RandomFloat(Min, Max);
	}
}

void FloatArrayFillKey(double *mass, int N)/*Заполнение массива числами с клавиатуры*/
{
	for (int i = 0; i < N; i++)
		scanf_s("%lf", &mass[i]);
}

void FloatArrayOutput(double *mass, int N)/*Вывод массива в консоль*/
{
	for (int i = 0; i < N; i++)
		printf("%.3f ", mass[i]);
}

void FloatCopyArray(double *mass1, double *mass2, int N)/*Копирование массива*/
{
	for (int i = 0; i < N; i++)
		mass2[i] = mass1[i];
}



/*INT matrix*/
void IntMatrixRandom(int N, int M, int matrix[][3], int Min, int Max)/*Заполнение матрицы рандомными числами*/
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			matrix[i][j] = RandomInt(Min, Max);
	}
}

void IntMatrixKeyboard(int N, int M, int matrix[][3])/*Заполнение матрицы с клавиатуры*/
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			scanf_s("%d", &matrix[i][j]);
	}
}

void IntMatrixCopy(int N, int M, int matrix1[][3], int matrix2[][3])/*Копирование матриц*/
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			matrix2[i][j] = matrix1[i][j];
	}
}

void OutMatrix(int N, int M, int matrix[][3])/*Вывод матрицы в консоль*/
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

/*Float matrix*/

void FloatMatrixRandom(int N, int M, double matrix[][3], double Min, double Max) /*Заполнение матрицы рандомными числами*/
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			matrix[i][j] = RandomFloat(Min, Max);
	}
}

void FloatMatrixKeyboard(int N, int M, double matrix[][3])/*Заполнение матрицы с клавиатуры*/
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			scanf_s("%lf", &matrix[i][j]);
	}
}

void FloatMatrixCopy(int N, int M, double matrix1[][3], double matrix2[][3])/*Копирование матриц*/
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			matrix2[i][j] = matrix1[i][j];
	}
}

void FloatOutMatrix(int N, int M, double matrix[][3])/*Вывод матрицы в консоль*/
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			printf("%f ", matrix[i][j]);
		printf("\n");
	}
}

