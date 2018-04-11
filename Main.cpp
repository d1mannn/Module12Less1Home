#include "Header.h"

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int task;
	do
	{
		task = TaskNumb();
		switch (task)
		{
			case 1:
			{
				//1.	Дана последовательность целых чисел, оканчивающаяся нулем.Записать все числа последовательности в типизированный файл
				int numbs[10];
				FILE *file;
				errno_t err;
				err = fopen_s(&file, "Case1.txt", "w");
				if (err == 0) // Важный 
				{	
					printf("File was created\n");
					ArrFilling(numbs, 10);
					FileFilling(file, 10, numbs);
					err = fclose(file);
					if (err != 0)
					{
						printf("ERROR\n");
						system("pause");
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					printf("ERROR\n");
					system("pause");
					exit(EXIT_FAILURE);
				}
			} break;

			case 2:
			{
				/*2.	Дан файл f, компоненты которого являются целыми числами.
					Записать в файл g все четные числа файла f,
					а в файл h — все нечетные.Порядок следования чисел сохраняется*/
				int numbs[15];
				FILE *file1, *file2;
				ArrFilling(numbs, 15);
				errno_t err1, err2;
				err1 = fopen_s(&file1, "Case2_1.txt", "w");
				err2 = fopen_s(&file2, "Case2_2.txt", "w");
				if (err1 == 0 && err2 == 0)
				{	
					printf("Files were created\n");
					ArrFilling2(numbs, 15);
					FileFilling(file1, 15, numbs, even);
					FileFilling(file2, 15, numbs, odd);
					err1 = fclose(file1);
					err2 = fclose(file2);
					if (err1 != 0 && err2 != 0)
					{
						perror("Ошибка");
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					perror("Ошибка");
					exit(EXIT_FAILURE);
				}
			} break;

			case 3:
			{
				//3.	Дан символьный файл f.Записать в файл g ком¬поненты файла f в обратном порядке
				char symbols[20];
				FILE *f, *g;
				errno_t err_f, err_g;
				err_f = fopen_s(&f, "Case3_1.txt", "w");
				if (err_f == 0)
				{
					printf("Files were created\n");
					CharArrFilling(symbols, 20);
					FileFillingChar(f, 20, symbols);
					err_f = fclose(f);
					if (err_f != 0)
					{
						perror("error");
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					perror("Error");
					exit(EXIT_FAILURE);
				}
				err_f = fopen_s(&f, "Case3_1.txt", "r");
				err_g = fopen_s(&g, "Case3_2.txt", "w");
				if (err_g == 0 && err_f == 0)
				{
					char * n = (char*)calloc(ftell(f) + 5, sizeof(char)); // ftell = size of f
					if (n == NULL)
					{
						perror("Error");
						exit(EXIT_FAILURE);
					}
					printf("Good\n");
					FromFileToFile(f, g, n);
					err_f = fclose(f);
					err_g = fclose(g);
					if (err_f != 0 || err_g != 0)
					{
						perror("Ошибка");
						exit(EXIT_FAILURE);
					}
				}
			} break;

			case 4:
			{
				/*4.	Дан файл f, компоненты которого являются целыми числами.
					Никакая из компонент файла не равна нулю.Файл f содержит 
					столько же отрицательных чисел, сколько и положительных.
					Используя вспомогательный файл h, переписать компоненты файла f в файл g так, 
					чтобы в файле g :
				a.не было двух соседних чисел с одним знаком
					b.сначала шли положительные, потом отрицательные числа
					c.числа шли в следующем порядке : два положитель¬ных, 
					два отрицательных, два положительных, два отрица¬тельных и т.д. 
					(предполагается, что число компонент в файле f делится на 4)*/
				FILE * f, *g, *h;
				errno_t err = fopen_s(&f, "Case4_1.txt", "w");
				int arr1[10];
				if (err == 0)
				{
					printf("GOOD\n");
					Case4FileFilling(f, arr1);
					err = fclose(f);
					if (err != 0)
					{
						perror("error");
						system("pause");
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					perror("error");
					system("pause");
					exit(EXIT_FAILURE);
				}
				int n;
				printf("Введите число от 1 до 3 -- ");
				scanf_s("%d", &n);
				switch (n)
				{
					case 1:
					{
						//a.не было двух соседних чисел с одним знаком
						errno_t err = fopen_s(&f, "Case4_1.txt", "r");
						errno_t err2 = fopen_s(&g, "Case4_2.txt", "w");
						if (err == 0 && err2 == 0)
						{
							printf("GOOD\n");
							NoSameNumbsNear(arr1, g);
							err = fclose(f);
							err2 = fclose(g);
							if (err != 0 || err2 != 0)
							{
								perror("error");
								system("pause");
								exit(EXIT_FAILURE);
							}
						}
						else
						{
							perror("error");
							system("pause");
							exit(EXIT_FAILURE);
						}
					} break;

					case 2:
					{
						errno_t err2 = fopen_s(&g, "Case4_3.txt", "w");
						if (err2 == 0)
						{
							printf("GOOD\n");
							NoSameNumbsNear(arr1, g);
							err2 = fclose(g);
							if (err != 0 || err2 != 0)
							{
								perror("error");
								system("pause");
								exit(EXIT_FAILURE);
							}
						}
						else
						{
							perror("error");
							system("pause");
							exit(EXIT_FAILURE);
						}
					} break;
				}
			} break;

			case 5:
			{
				/*5.	Напечатать все элементы типизированного файла, каждый элемент которого — отдельное слово.Рассмотреть два варианта
					a.известно, что в существующем файле записаны 12 слов
					b.размер существующего файла неизвестен*/
				FILE *file;
				errno_t err = fopen_s(&file, "Text.txt", "rb");
				if (err != 0)
				{
					perror("Error");
					system("pause");
					exit(1);
				}
				fseek(file, 0, SEEK_END);
				long size = ftell(file);
				rewind(file);
				char * buffer = (char *)calloc(size, sizeof(char));
				if (buffer == NULL)
				{
					printf("Buffer wasn't created\n");
					exit(1);
				}
				fread(buffer, sizeof(char), size, file);
				puts(buffer);
				fclose(file);
				free(buffer);
			} break;

			case 6:
			{
				//6.	Имеется файл, элементами которого являются отдельные буквы.
				//Получить слово, образованное этими буквами
				char arr[] = "i\nn\ns\nt\nr\nu\nm\ne\nn\nt\na\nl\n";
				FILE* file;
				errno_t err = fopen_s(&file, "Case6.txt", "w");
				if (err != 0)
				{
					perror("Error");
					system("pause");
					exit(1);
				}
				for (int i = 0; i < strlen(arr); i++)
				{
					fprintf(file, "%c", arr[i]);
				}
				//fwrite(arr, sizeof(char), strlen(arr), file);
				fclose(file);
				err = fopen_s(&file, "Case6.txt", "r");
				if (err != 0)
				{
					perror("Error");
					system("pause");
					exit(1);
				}
				fseek(file, 0, SEEK_END);
				long size = ftell(file);
				rewind(file);
				char * buffer = (char *)calloc(size, sizeof(char));
				if (buffer == NULL)
				{
					printf("Buffer wasn't created\n");
					exit(1);
				}
				int i = 0;
				char j;
				while (!feof(file))
				{	
					fscanf_s(file, "%c", &j);
					if (j != '\n')
					{
						buffer[i] = j;
						i++;
					}
				}
				puts(buffer);
				fclose(file);
				free(buffer);
			} break;

			case 7:
			{
				/*7.	Имеется типизированный файл, элементами которого являются отдельные слова.
					Напечатать все слова, начинающиеся на букву с.*/
				FILE * file;
				errno_t err = fopen_s(&file, "Text2.txt", "r");
				if (err != 0)
				{
					perror("Error");
					system("pause");
					exit(1);
				}
				fseek(file, 0, SEEK_END);
				long size = ftell(file);
				rewind(file);
				char * buffer = (char *)calloc(size, sizeof(char));
				int i = 0;
				char j;
				while (!feof(file))
				{
					fscanf_s(file, "%c", &j);
					buffer[i] = j;
					i++;
				}
				puts(buffer);
				int n = strlen(buffer);
				for (int i = 0; i < strlen(buffer); i++)
				{
					if ((buffer[i] == 'с' && buffer[i - 1] == ' ') || (buffer[i] == 'с' && buffer[i - 1] == '\n'))
					{
						while (buffer[i] != ' ' && i != strlen(buffer))
						{
							printf("%c", buffer[i]);
							i++;
						}
					}
				}
				fclose(file);
				free(buffer);
			} break;
		}
	} while (task != 0);
}