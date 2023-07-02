#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

int main() 
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	FILE* input, * output;
	int* a;
	int size;
	printf("Введите размер массива: ");
	scanf("%d", &size);
	fflush(stdin);
	a = (int*)malloc(size * sizeof(int));
	input = fopen("inputmas.txt", "w");
	if (input == NULL)
		printf("Не удалось открыть файл");
	else
		for (int i = 0; i < size; i++)
		{
			*(a + i) = rand() % 2001 - 1000;
			fprintf(input, "%d\n", *(a + i));
		}
	fclose(input);
	return 0;
}