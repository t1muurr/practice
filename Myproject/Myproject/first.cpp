#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
	setlocale(LC_ALL, "Rus");	// ������� �� �������
	srand(time(0));	// ��� ��������� ��������������� �����

	FILE* input,* output;	// ��������� �� �����
	int* mas;	// ��������� �� ������
	int size;	// ������ �������

	printf("������� ������ ������� >= 1: ");	
	while (size <= 1)
		scanf("%d", &size);	// ���� ������� �������

	mas = (int*)malloc(size * sizeof(int));	// ��������� ������ ��� ������
	input = fopen("inputmas.txt", "w");	// ��������� ���� ��� ������
	if (input == NULL)	// ���� ���� �� ��������
		printf("�� ������� ������� ����");
	else	// ���� ���� ��������
	{
		for (int i = 0; i < size; i++)	// ���� i ������ ������� �������
		{
			*(mas + i) = rand() % 2001 - 1000;	// ��������� ������ ������� ��������� [-1000:1000]
			fprintf(input, "%d ", *(mas + i));	// ���������� ������ � ����
		}
	}
	fclose(input);	// ��������� ����
	free(mas);	// ������� ������

	mas = (int*)malloc(size * sizeof(int));	// ��������� ������ ��� ������
	input = fopen("inputmas.txt", "r");	// ��������� ���� ��� ������ 
	if (input == NULL)	// ���� ���� �� ��������
		printf("�� ������� ������� ����");
	else	// ���� ���� ��������
		for (int i = 0; i < size; i++)	// ���� i ������ ������� �������
		{
			fscanf(input, "%d", &mas[i]);	// ��������� ������ �� ����� � ������
		}
	fclose(input);	// ��������� ����
	//__________________________________________________

	//��� ���������(���������� ������� mas[size])

	//__________________________________________________
	output = fopen("outputmas.txt", "w");	// ��������� ���� ��� ������
	if (output == NULL)	// ���� ���� �� ��������
		printf("�� ������� ������� ����");
	else	// ���� ���� ��������
	{
		for (int i = 0; i < size; i++)	// ���� i ������ ������� �������
			fprintf(output, "%d\n", *(mas + i));	// ���������� � ���� ��������������� ������
	}
	fclose(output);	// ��������� ����
	free(mas);	// ������� ������
	return 0;
}