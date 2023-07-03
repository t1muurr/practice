#include <stdio.h> 
#include <locale.h> 
#include <stdlib.h> 
#include <time.h> 

void Merge(int arr[], int* aux, int low, int mid, int high) 
{ 
int k = low, i = low, j = mid + 1; 

// пока есть элементы в левом и правом рядах 
while (i <= mid && j <= high) 
{ 
if (arr[i] <= arr[j]) 
{ 
aux[k] = arr[i]; 
i++; k++; 
} 
else 
{ 
aux[k] = arr[j]; 
j++; k++; 
} 
} 

// копируем оставшиеся элементы 
while (i <= mid) { 
aux[k] = arr[i]; 
i++; k++; 
} 
// копируем оставшиеся элементы 
while (j <= high) { 
aux[k] = arr[j]; 
j++; k++; 
} 
// Вторую половину копировать не нужно (поскольку остальные элементы 
// уже находятся на своем правильном месте во вспомогательном массиве) 

// копируем обратно в исходный массив, чтобы отразить порядок сортировки 
for (int k = low; k <= high; k++) { 
arr[k] = aux[k]; 
} 
} 

// Сортируем массив `arr[low…high]`, используя вспомогательный массив `aux` 
void mergesort(int arr[], int* aux, int low, int high) 
{ 
// базовый вариант 
if (high <= low) { // если размер прогона <= 1 
return; 
} 

// найти середину 
int mid = ((low + high) / 2); 

// рекурсивно разделяем прогоны на две половины до тех пор, пока размер прогона не станет <= 1, 
// затем объединяем их и возвращаемся вверх по цепочке вызовов 

mergesort(arr, aux, low, mid); // разделить/объединить левую половину 
mergesort(arr, aux, mid + 1, high); // разделить/объединить правую половину 

Merge(arr, aux, low, mid, high); // объединить два полупрогона. 
} 

int main() 
{ 
setlocale(LC_ALL, "Rus"); // Консоль на русском 
srand(time(0)); 

FILE* input, * output; // Указатели на файлы 
int* mas, * aux; // Указатель на массив 
int size; // Размер массива 

printf("Введите размер массива: "); 
scanf("%d", &size); // Ввод размера массива 

mas = (int*)malloc(size * sizeof(int)); // Выделение памяти под массив 
input = fopen("inputmas.txt", "w"); // Открываем файл для записи 
if (input == NULL) // Если файл не открылся 
printf("Не удалось открыть файл"); 
else // Если файл открылся 
{ 
for (int i = 0; i < size; i++) // Пока i меньше размера массива 
{ 
*(mas + i) = rand() % 2001 - 1000; // Заполняем массив числами диапащона [-1000:1000] 
fprintf(input, "%d ", *(mas + i)); // Записываем массив в файл 
} 
} 
fclose(input); // Закрываем файл 
free(mas); // Очищаем память 

mas = (int*)malloc(size * sizeof(int)); // Выделение памяти под массив 
input = fopen("inputmas.txt", "r"); // Открываем файл для чтения 
if (input == NULL) // Если файл не открылся 
printf("Не удалось открыть файл"); 
else // Если файл открылся 
{ 
for (int i = 0; i < size; i++) // Пока i меньше размера массива 
{ 
fscanf(input, "%d", &mas[i]); // Считываем данные из файла в массив 
} 
} 
fclose(input); // Закрываем файл 

aux = (int*)malloc(size * sizeof(int)); // Выделение памяти под массив 
mergesort(mas, aux, 0, size - 1); // Вызываем функцию 

output = fopen("outputmas.txt", "w"); // Открываем файл для записи 
if (output == NULL) // Если файл не открылся 
printf("Не удалось открыть файл"); 
else // Если файл открылся 
{ 
for (int i = 0; i < size; i++) // Пока i меньше размера массива 
{ 
fprintf(output, "%d ", *(mas + i)); // Записываем в файл отсортированный массив 
} 
} 
fclose(output); // Закрываем файл 
free(mas); // Очищаем память 
free(aux); // Очищаем память 
return 0; 
}