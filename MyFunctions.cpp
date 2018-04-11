#include "Header.h"

int TaskNumb()
{
	int task;
	printf("¬ведите номер задани€ (дл€ выхода введите 0)\n ---->");
	scanf_s("%d", &task);
	return task;
}

void ArrFilling(int * arr, int length)
{
	for (size_t i = 0; i < length; i++)
	{	
		if (i != length - 1)
			arr[i] = -5 + rand() % 10;
		else
			arr[i] = 0;
	}
}

void ArrFilling2(int * arr, int length)
{	
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = -20 + rand() % 40;
	}
}

void ArrFilling3(char * arr, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = 0 + rand() % 255;
		printf("%c\n", arr[i]);
	}
}

void FileFilling(FILE * file, int length, int *arr)
{
	for (size_t i = 0; i < length; i++)
	{
		fprintf(file, "%d\n", arr[i]);
	}
}

void FileFilling(FILE * file, int length, int *arr, NumbsType type)
{	
	switch (type)
	{
	case even:
	{
		for (size_t i = 0; i < length; i++)
		{	
			if(arr[i] % 2 == 0)
				fprintf(file, "%d\n", arr[i]);
		}
	}
		break;
	case odd:
	{
		for (size_t i = 0; i < length; i++)
		{
			if (arr[i] % 2 != 0)
				fprintf(file, "%d\n", arr[i]);
		}
	}
		break;

	case all:
	{
		for (size_t i = 0; i < length; i++)
		{
			fprintf(file, "%d\n", arr[i]);
		}
	} break;

	case order:
	{
		for (size_t i = length - 1; i >= 0; i--)
		{
			fprintf(file, "%d\n", arr[i]);
		}
	} break;
	default: printf("Error\n");
		break;
	}
}

void CharArrFilling(char * arr, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = (char)1 + rand() % 255;
		printf("%c\n", arr[i]);
	}
}

void FileFillingChar(FILE * file, int length, char *arr)
{
	for (size_t i = 0; i < length; i++)
	{
		fprintf(file, "%c\n", arr[i]);
	}
}

void FromFileToFile(FILE * from, FILE * to, char *n)
{	
	int i = 0;
	while (!feof(from))
	{
		fscanf_s(from, "%c", &n[i]);
		//fprintf(g, "%c", n[i]);
		i++;
	}
	printf("\n\n%d\n", i);
	for (int j = i - 2; j >= 0; j--)
	{
		fprintf(to, "%c", n[j]);
	}
}

void Case4FileFilling(FILE *file, int * arr)
{
	int i = 1;
	int plus = 0, minus = 0;
	int count = 0;
	int n = 0;
	while (i <= 10)
	{
		n = -50 + rand() % 100;
		if (n != 0 && n % 4 == 0)
		{	
			if (n > 0 && plus != 5)
			{
				fprintf(file, "%d\n", n);
				arr[count] = n;
				count++;
				plus++;
				i++;
			}
			if (n < 0 && minus != 5)
			{
				fprintf(file, "%d\n", n);
				arr[count] = n;
				count++;
				minus++;
				i++;
			}
		}
	}
}

void Case4FromFileToFile(FILE * from, FILE * to, char *arr)
{
	int i = 0;
	int plus = 0, minus = 0;
	int n = 0;
	while (i <= 10)
	{
		if (i % 2 == 0)
		{
			fscanf_s(from, "%d", &arr[i]);
			n = atoi(&arr[i]);
			if (n > 0)
			{
				fprintf(to, "%d", arr[i]);
				i++;
			}
		}
		else
		{
			fscanf_s(from, "%d", &arr[i]);
			n = atoi(&arr[i]);
			if ((int)arr[i] < 0)
			{
				fprintf(to, "%d", arr[i]);
				i++;
			}
		}
		fgetc(from);
	}
}

void NoSameNumbsNear(int *arr, FILE * file)
{	
	int temp;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 10 - 1; j > 0; j--)
		{
			if (arr[j] > arr[j - 1])
			{
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		fprintf(file, "%d\n", arr[i]);
	}
}

void CountOfEOF(FILE * file, int * count)
{
	while (!feof(file))
	{
		*(count++);
	}
}

//void TwoPositiveTwoNegative(int * arr, FILE * file)
//{	
//	int temp[10];
//	int  i = 0;
//	int j = 0;
//
//	for (int i = 0; i < 9; i+=2)
//	{
//		while (j != 10)
//		{
//			j = i;
//			if (arr[j] > 0)
//			{
//
//			}
//
//		}
//	}
//	while (i <= 10)
//	{
//		while (j <= 10)
//		{
//
//		}
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 10 - 1; j > 0; j--)
//		{
//
//		}
//	}
//}