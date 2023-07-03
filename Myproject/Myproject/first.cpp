#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
	setlocale(LC_ALL, "Rus");	// Консоль на русском
	srand(time(0));	// Для генерации псевдослучайных чисел

	FILE* input,* output;	// Указатели на файлы
	int* mas;	// Указатель на массив
	int size;	// Размер массива

	printf("Введите размер массива >= 1: ");	
	while (size <= 1)
		scanf("%d", &size);	// Ввод размера массива

	mas = (int*)malloc(size * sizeof(int));	// Выделение памяти под массив
	input = fopen("inputmas.txt", "w");	// Открываем файл для записи
	if (input == NULL)	// Если файл не открылся
		printf("Не удалось открыть файл");
	else	// Если файл открылся
	{
		for (int i = 0; i < size; i++)	// Пока i меньше размера массива
		{
			*(mas + i) = rand() % 2001 - 1000;	// Заполняем массив числами диапащона [-1000:1000]
			fprintf(input, "%d ", *(mas + i));	// Записываем массив в файл
		}
	}
	fclose(input);	// Закрываем файл
	free(mas);	// Очищаем память

	mas = (int*)malloc(size * sizeof(int));	// Выделение памяти под массив
	input = fopen("inputmas.txt", "r");	// Открываем файл для чтения 
	if (input == NULL)	// Если файл не открылся
		printf("Не удалось открыть файл");
	else	// Если файл открылся
		for (int i = 0; i < size; i++)	// Пока i меньше размера массива
		{
			fscanf(input, "%d", &mas[i]);	// Считываем данные из файла в массив
		}
	fclose(input);	// Закрываем файл
	//__________________________________________________

	//Код программы(сортировка массива mas[size])

	//__________________________________________________
	output = fopen("outputmas.txt", "w");	// Открываем файл для записи
	if (output == NULL)	// Если файл не открылся
		printf("Не удалось открыть файл");
	else	// Если файл открылся
	{
		for (int i = 0; i < size; i++)	// Пока i меньше размера массива
			fprintf(output, "%d\n", *(mas + i));	// Записываем в файл отсортированный массив
	}
	fclose(output);	// Закрываем файл
	free(mas);	// Очищаем память
	return 0;
}