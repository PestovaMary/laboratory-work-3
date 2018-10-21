#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "MyLib.h"




void Function()
{
	int selection;
	int Min, Max, N, i;
	double min, max;
	double number;

	printf("\n1. RandomInt\n2. RandomFloat\n3. Rounding\n4. GetPercent\n5. DrawPyramid\n\n");
	scanf_s("%d", &selection);
	switch (selection)
	{
	case 1:
		system("@cls||clear");
		printf("Введите диапозон\n");
		scanf_s("%d", &Min);
		scanf_s("%d", &Max);
		printf("\n%d", RandomInt(Min, Max));
		break;

	case 2:
		system("@cls||clear");
		printf("Введите диапозон\n");
		scanf_s("%lf", &min);
		scanf_s("%lf", &max);
		printf("%.3f", RandomFloat(min, max));
		break;

	case 3:
		system("@cls||clear");
		printf("Введите число\n");
		scanf_s("%lf", &number);
		printf("%d", Rounding(number));
		break;

	case 4:
		double percent;
		system("@cls||clear");
		printf("Введите число\n");
		scanf_s("%lf", &number);
		printf("Введите процент\n");
		scanf_s("%lf", &percent);
		printf("\n\n%.3f", getPercent(number, percent));
		break;

	case 5:
		printf("Введите размер основания");
		scanf_s("%d", &N);
		i = 1;
		drawPyramid(i, N);
		break;
	}
}


void ArrayFunction()
{	
	int selection;
	int Min, Max;
	double min, max;
	int N;
	int *mass;
	double *Mass;

	printf("\t\tSelect data type\n\n");
	printf("1. Int\n2. Float\n\n");
	scanf_s("%d", &selection);
	
	switch (selection)
	{
	case 1: 
		system("@cls||clear");
		printf("1. Array filling randomly\n2. Filling the array with the keyboard\n3. Copy array\n\n");
		scanf_s("%d", &selection);
		
		switch (selection)
		{
		case 1:
			system("@cls||clear");
			printf("Введите размер массива\n");
			scanf_s("%d", &N);
			mass = (int*)malloc(N * sizeof(int));
			printf("Введите интервал\n");
			scanf_s("%d", &Min);
			scanf_s("%d", &Max);
			ArrayFillRand(mass, N, Min, Max);
			ArrayOutput(mass, N);
			break;

		case 2:
			system("@cls||clear");
			printf("Введите размер массива\n");
			scanf_s("%d", &N);
			mass = (int*)malloc(N * sizeof(int));
			printf("Введите элементы массива\n");
			ArrayFillKey(mass, N);
			ArrayOutput(mass, N);
			break;

		case 3:
			int *mass1, *mass2;
			system("@cls||clear");
			printf("Введите размер массивов\n");
			scanf_s("%d", &N);
			mass1 = (int*)malloc(N * sizeof(int));
			mass2 = (int*)malloc(N * sizeof(int));
			printf("Введите элементы массива\n");
			ArrayFillKey(mass1, N);
			CopyArray(mass1, mass2, N);
			ArrayOutput(mass2, N);
			break;
		}
		break;

	case 2:
		system("@cls||clear");
		printf("1. Array filling randomly\n2. Filling the array with the keyboard\n3. Copy array\n\n");
		scanf_s("%d", &selection);
		switch (selection)
		{
		case 1:
			system("@cls||clear");
			printf("Введите размер массива\n");
			scanf_s("%d", &N);
			Mass = (double*)malloc(N * sizeof(double));
			printf("Введите интервал\n");
			scanf_s("%lf", &min);
			scanf_s("%lf", &max);
			FloatArrayFillRand(Mass, N, min, max);
			FloatArrayOutput(Mass, N);
			break;

		case 2:
			system("@cls||clear");
			printf("Введите размер массива\n");
			scanf_s("%d", &N);
			Mass = (double*)malloc(N * sizeof(double));
			printf("Введите элементы массива\n");
			FloatArrayFillKey(Mass, N);
			FloatArrayOutput(Mass, N);
			break;

		case 3:
			system("@cls||clear");
			double *Mass1, *Mass2;
			printf("Введите размер массивов\n");
			scanf_s("%d", &N);
			Mass1 = (double*)malloc(N * sizeof(double));
			Mass2 = (double*)malloc(N * sizeof(double));
			printf("Введите элементы массива\n");
			FloatArrayFillKey(Mass1, N);
			FloatCopyArray(Mass1, Mass2, N);
			FloatArrayOutput(Mass2, N);
			break;
		}
		break;
	}
}

void StringFunction()
{
	while (getchar() != '\n');
	int selection;
	char string[30], symbol[2];
	printf("number or string?\n1.Number\n2.String\n");
	scanf_s("%d", &selection);
	switch (selection)
	{
	case 1:
		while (getchar() != '\n');
		system("@cls||clear");
		long int number;
		printf("Введите число\n");
		scanf_s("%li", &number);	
		FromIntToChar(number);
		break;

	case 2:
		while (getchar() != '\n');
		system("@cls||clear");
		printf("Введите строку\n");
		gets_s(string);
		printf("1.Подсчет количества символов\n2.Удаление символа\n3.Добавление символа\n4.Преобразование строки в целое число\n");
		scanf_s("%d", &selection);
		switch (selection)
		{
		case 1:
			system("@cls||clear");
			while (getchar() != '\n');
			printf("%d",Stringlength(string));			
			break;

		case 2:
			system("@cls||clear");
			while (getchar() != '\n');
			printf("Введите символ, который нужно удалить\n");
			gets_s(symbol);
			DeleteSymbol(string, symbol);
			puts(string);
			break;

		case 3:
			system("@cls||clear");
			while (getchar() != '\n');
			printf("Введите символ, который нужно добавить\n");
			gets_s(symbol);
			AddSymbol(string, symbol);
			puts(string);
			break;

		case 4:
			system("@cls||clear");
			while (getchar() != '\n');
			printf("%d", FromCharToInt(string));
			break;
		}
		break;
	}
}
	
void MatrixFunction()
{			
	const int N = 3, M = 3;
	int selection;
	printf("1. Int Matrix\n2. Float Matrix\n\n");
	scanf_s("%d", &selection);
	switch (selection)
	{
	case 1:
		system("@cls||clear");
		printf("1. Random\n2. Keyboard\n3. Copy\n\n");
		scanf_s("%d", &selection);
		switch (selection)
		{
		case 1:
			system("@cls||clear");
			int matrix[N][M];
			int Min, Max;
			printf("Диапозон\n");
			scanf_s("%d", &Min);
			scanf_s("%d", &Max);
			IntMatrixRandom(N, M, matrix, Min, Max);
			OutMatrix(N, M, matrix);
			break;

		case 2:
			system("@cls||clear");
			IntMatrixKeyboard(N, M, matrix);
			OutMatrix(N, M, matrix);
			break;

		case 3:
			system("@cls||clear");
			int matrix1[N][M], matrix2[N][M];
			printf("Диапозон\n");
			scanf_s("%d", &Min);
			scanf_s("%d", &Max);
			IntMatrixRandom(N, M, matrix1, Min, Max);
			IntMatrixCopy(N, M, matrix1, matrix2);
			OutMatrix(N, M, matrix2);
			break;
		}
		break;

	case 2:
		system("@cls||clear");
		printf("1. Random\n2. Keyboard\n3. Copy\n\n");
		scanf_s("%d", &selection);

		switch (selection)
		{
		case 1:
			system("@cls||clear");
			double min, max;
			double Matrix[N][M];
			printf("Диапозон\n");
			scanf_s("%lf", &min);
			scanf_s("%lf", &max);
			FloatMatrixRandom(N, M, Matrix, min, max);
			FloatOutMatrix(N, M, Matrix);
			break;

		case 2:
			system("@cls||clear");
			FloatMatrixKeyboard(N, M, Matrix);
			FloatOutMatrix(N, M, Matrix);
			break;
		
		case 3:
			system("@cls||clear");
			double Matrix1[N][M], Matrix2[N][M];
			printf("Диапозон\n");
			scanf_s("%d", &min);
			scanf_s("%d", &max);
			FloatMatrixRandom(N, M, Matrix1, min, max);
			FloatMatrixCopy(N, M, Matrix1, Matrix2);
			FloatOutMatrix(N, M, Matrix2);
			break;
		}

		break;
	}
	
}

void main_menu()
{
	int selection;
	printf("\t\t\t\t Welcome to the main menu.\n\t Familiarize yourself with the available features and enter the order number.\n\n");
	printf("1.Function\n2.Array function\n3.String function\n4.Matrix function\n\n");
	scanf_s("%d", &selection);
	switch (selection)
	{
	case 1:
		system("@cls||clear");
		Function();
		break;

	case 2:
		system("@cls||clear");
		ArrayFunction();
		break;

	case 3:
		system("@cls||clear");
		StringFunction();
		break;

	case 4:
		system("@cls||clear");
		MatrixFunction();
		break;
	}
	printf("\n\nНажмите 1 для выхода в главное меню\n\n");
	scanf_s ("%d", & selection);	
	if (selection == 1)
	{
		system("@cls||clear");
		main_menu();
	}
}


int main()
{			
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	main_menu();
	_getch();
}
