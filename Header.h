#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

enum NumbsType
{
	even, odd
};

enum NumsOrSymb
{
	numb, symb, all, order
};

int TaskNumb();
void ArrFilling(int * arr, int length);
void FileFilling(FILE * file, int length, int *arr);
void ArrFilling2(int * arr, int length);
void FileFilling(FILE * file, int length, int *arr, NumbsType type);
void FileFillingChar(FILE * file, int length, char *arr);
void ArrFilling3(char * arr, int length);
void FromFileToFile(FILE * from, FILE * to, char *n);

void CharArrFilling(char * arr, int length);
void Case4FileFilling(FILE *file, int * arr);
void Case4FromFileToFile(FILE * from, FILE * to, char *arr);
void CountOfEOF(FILE * file, int * count);
void NoSameNumbsNear(int *arr, FILE * file);

