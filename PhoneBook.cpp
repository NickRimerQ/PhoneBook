#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>//дл€ использовани€ функции, например, strcmp
#include <malloc.h>//дл€ создани€ darr
#include <ctype.h>//дл€ использовани€ функции, например, isalnum
#include <vector>
using namespace std;
#define LEN 26


char path[300] = "cat.txt";
//vector <string> path(300);

struct phonebook {
	char surname[LEN];
	char name[LEN];
	char numb[LEN];

	//vector <string> surname(LEN);
	//vector <string> name(LEN);
	//vector <string> numb(LEN);
};

void menu() {
	printf("---------------------------------\n");
	printf("1. Add person.\n");
	printf("2. Show list.\n");
	printf("3. Delete.\n");
	printf("4. Sort.\n");
	printf("5. Copy .txt.\n");
	printf("6. Delete .txt.\n");
	printf("7. Register.\n");
	printf("8. Exit.\n");
	printf("---------------------------------\n");
}


void zero(int n, phonebook* darr1) {  //дл€ использовани€ в del
	char zero[] = "";
	for (int i = 0; i < n; i++) {
		strcpy(darr1[i].numb, zero);
	}
	for (int i = 0; i < n; i++) {
		strcpy(darr1[i].name, zero);
	}
	for (int i = 0; i < n; i++) {
		strcpy(darr1[i].surname, zero);
	}
}

void add_person(phonebook* darr1, int i) { //добавление
	system("cls");
	printf("Enter your surname\n");
	scanf("%s", darr1[i].surname);

	system("cls");
	printf("Enter your name\n");
	scanf("%s", darr1[i].name);

	system("cls");
	printf("Enter your number\n");
	scanf("%s", darr1[i].numb);
	while (1) {
		if ((atol(darr1[i].numb)) != 0 && strlen(darr1[i].numb) == 11) {
			break;
		}
		else {
			printf("Enter correct number. 11 numbers.\n");
			scanf("%s", darr1[i].numb);
		}
	}
	system("cls");
}

int show_persons(int n, phonebook* darr1) {   //список
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (!(strcmp(darr1[i].numb, "")) == 0) {
			j += 1;
			printf("%d. %s %s %s\n", j, darr1[i].surname, darr1[i].name, darr1[i].numb);
		}

	}
	return j;
}

void del(int i, phonebook* darr1) { //удаление
	char zero[] = "";
	strcpy(darr1[i].numb, zero);

	strcpy(darr1[i].name, zero);

	strcpy(darr1[i].surname, zero);
}

void sort(int n, phonebook* darr1) { //сортировка
	system("cls");
	int method = 0;
	printf("choose method of sort\n1. surname 2.name\n");
	scanf_s("%d", &method);
	system("cls");
	if (method == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((strcmp(darr1[i].numb, "")) != 0 && (strcmp(darr1[j].numb, "")) != 0) {
					if (strncmp(darr1[j].surname, darr1[i].surname, LEN) < 0) {
						char help_me1[LEN] = "";
						char help_me2[LEN] = "";

						strcpy(help_me1, darr1[i].surname);
						strcpy(darr1[i].surname, darr1[j].surname);
						strcpy(darr1[j].surname, help_me1);
						strcpy(help_me1, help_me2);

						strcpy(help_me1, darr1[i].name);
						strcpy(darr1[i].name, darr1[j].name);
						strcpy(darr1[j].name, help_me1);
						strcpy(help_me1, help_me2);

						strcpy(help_me1, darr1[i].numb);
						strcpy(darr1[i].numb, darr1[j].numb);
						strcpy(darr1[j].numb, help_me1);

					}
				}
			}
		}
	}
	if (method == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((strcmp(darr1[i].numb, "")) != 0 && (strcmp(darr1[j].numb, "")) != 0) {
					if (strncmp(darr1[j].name, darr1[i].name, LEN) < 0) {
						char help_me1[LEN] = "";
						char help_me2[LEN] = "";
						strcpy(help_me1, darr1[i].surname);
						strcpy(darr1[i].surname, darr1[j].surname);
						strcpy(darr1[j].surname, help_me1);
						strcpy(help_me1, help_me2);

						strcpy(help_me1, darr1[i].name);
						strcpy(darr1[i].name, darr1[j].name);
						strcpy(darr1[j].name, help_me1);
						strcpy(help_me1, help_me2);

						strcpy(help_me1, darr1[i].numb);
						strcpy(darr1[i].numb, darr1[j].numb);
						strcpy(darr1[j].numb, help_me1);

					}
				}
			}
		}
	}
	if (method != 1 && method != 2) {
		printf("wrong! choose correctly next time\n");
	}
}

void copy(phonebook* darr1, int n) { //создание текстового файла и копирование списка туда(если уже создан файл, удал€ет его)
	system("cls");
	int z = 0;
	FILE* file;
	file = fopen(path, "wt");
	if (file) {
		printf("file opened \n");
		for (int i = 0; i < n; i++) {
			if ((strcmp(darr1[i].numb, "")) != 0) {
				z = z + 1;
				fprintf(file, "%d. %s %s %s\n", z, darr1[i].surname, darr1[i].name, darr1[i].numb);
			}
		}
		fclose(file);
	}
	else {
		printf("file not opened \n");
	}
}

void del_txt(FILE* f) {  //удаление текстового файла 
	fclose(f);
	if (remove(path) == 0) {
		printf("file deleted\n");
	}
	else {
		printf("file not deleted\n");
		printf("%d\n", remove(path));
	}
}

void

reg(phonebook* darr1, int n) { //верхний и нижний регистры
	int reg = 0;
	printf("What register do u want?\n");
	printf("1 for low, 2 for high\n");
	scanf_s("%d", &reg);
	if (reg == 1) {
		for (int i = 0; i < n; i++) {
			if ((strcmp(darr1[i].numb, "")) != 0) {
				for (int j = 0; j < strlen(darr1[i].surname); j++) {
					darr1[i].surname[j] = tolower(darr1[i].surname[j]);
					darr1[i].name[j] = tolower(darr1[i].name[j]);
				}
			}
		}
	}
	if (reg == 2) {
		for (int i = 0; i < n; i++) {
			if ((strcmp(darr1[i].numb, "")) != 0) {
				for (int j = 0; j < strlen(darr1[i].surname); j++) {
					darr1[i].surname[j] = toupper(darr1[i].surname[j]);
					darr1[i].name[j] = toupper(darr1[i].name[j]);
				}
			}
		}
	}
	if (reg != 1 && reg != 2) {
		printf("wrong! choose correctly next time\n");
	}
}

void everything_darr2(FILE* f, phonebook* darr2, int more_people, int lines_count) {
	int n = 0;//кол-во €чейк в darr1
	int death = 0;//переменна€ дл€ завершени€ работа программы

	printf("How many people will be on your list?\n");
	scanf_s("%d", &n);
	n = n + more_people;
	struct phonebook* darr1 = (struct phonebook*)malloc(n * sizeof(struct phonebook));

	zero(n, darr1);
	if (f) {


		for (int i = 0; i < lines_count; i++) {
			strcpy(darr1[i].surname, darr2[i].surname);
			strcpy(darr1[i].name, darr2[i].name);
			strcpy(darr1[i].numb, darr2[i].numb);
		}

	}

	while (1) {//бесконечный цикл дл€ полной работы с телефонной книжкой
		int choice = 0;
		if (death == 1) {
			break;
		}
		menu();
		while (!choice && scanf_s("%1d", &choice) == 1) {
			switch (choice) {

			case 1: {
				int g = 0;
				for (int i = 0; i < n; i++) {
					if (strcmp(darr1[i].numb, "") == 0) {
						add_person(darr1, i);
						break;
					}
					else {
						g += 1;
					}
				}
				if (g == n) {
					system("cls");
					printf("Array is busy.\n");

				}
				break;
			}
			case 2:
				system("cls");

				show_persons(n, darr1);
				break;
			case 3: {
				int i = 0;
				system("cls");
				show_persons(n, darr1);
				printf("What you want to delete?\n");
				scanf_s("%d", &i);
				if (i != 0 && i <= show_persons(n, darr1)) {
					system("cls");
					i = i - 1;
					del(i, darr1);
				}
				else {
					system("cls");
					printf("Something wrong\n");
				}

				break;
			}
			case 4:
				sort(n, darr1);
				break;
			case 5:
				copy(darr1, n);
				break;
			case 6:
				del_txt(f);
				break;
			case 7:
				reg(darr1, n);
				break;
			case 8:
				death = 1;
				break;



			default:
				system("cls");
				printf("Choose more correctly\n");
				choice == 0;

			}

		}
	}
	free(darr1);

}

void everything(FILE* f) {
	int n = 0;//кол-во €чейк в darr1
	int death = 0;//переменна€ дл€ завершени€ работа программы
	printf("How many people will be on your list?\n");
	scanf_s("%d", &n);
	struct phonebook* darr1 = (struct phonebook*)malloc(n * sizeof(struct phonebook));
	zero(n, darr1);
	while (1) {//бесконечный цикл дл€ полной работы с телефонной книжкой
		int choice = 0;
		if (death == 1) {
			break;
		}
		menu();
		while (!choice && scanf_s("%1d", &choice) == 1) {
			switch (choice) {

			case 1: {
				int g = 0;
				for (int i = 0; i < n; i++) {
					if (strcmp(darr1[i].numb, "") == 0) {
						add_person(darr1, i);
						break;
					}
					else {
						g += 1;
					}
				}
				if (g == n) {
					system("cls");
					printf("Array is busy.\n");

				}
				break;
			}
			case 2:

				system("cls");
				show_persons(n, darr1);
				break;
			case 3: {
				int i = 0;
				system("cls");
				show_persons(n, darr1);
				printf("What you want to delete?\n");
				scanf_s("%d", &i);

				if (i != 0 && i <= show_persons(n, darr1)) {
					system("cls");
					i = i - 1;
					del(i, darr1);
				}
				else {
					system("cls");
					printf("Something wrong\n");
				}

				break;
			}
			case 4:
				sort(n, darr1);
				break;
			case 5:
				copy(darr1, n);
				break;
			case 6:
				del_txt(f);
				break;
			case 7:
				reg(darr1, n);
				break;
			case 8:
				death = 1;
				break;



			default:
				system("cls");
				printf("Choose more correctly\n");
				choice == 0;

			}

		}
	}
	free(darr1);
}

int main() {
	int more_people = 0;//переменна€ дл€ добавлени€ дополнительных людей, если есть .txt файл
	FILE* f;
	f = fopen(path, "rt");
	if (f) {//проверка на открытие файла
		printf("File opened.\n");
		int lines_count = 0;//счетчик строк в .txt файле

		if (fgetc(f) == '1') {

			while (!feof(f)) {
				if (fgetc(f) == '\n') {
					lines_count++;
				}
			}
			fclose(f);
			struct phonebook* darr2 = (struct phonebook*)malloc(lines_count * sizeof(struct phonebook));
			FILE* f;
			f = fopen(path, "rt");
			if (f) {

				int cou = 0;
				while (!feof(f)) {
					char cha[LEN * 3];
					int g = 0;
					char surnname[LEN] = "";
					char nname[LEN] = "";
					char nnumb[LEN] = "";
					fgets(cha, LEN * 3, f);
					for (int i = 0; i < LEN * 3; i++) {
						if (isalnum(cha[3 + i])) {
							surnname[i] = cha[3 + i];
						}
						else {

							strcpy(darr2[cou].surname, surnname);
							g = i + 4;
							break;
						}
					}
					for (int i = g, zero = 0; i < LEN * 3; i++, zero++) {
						if (isalnum(cha[i])) {
							nname[zero] = cha[i];
						}
						else {

							strcpy(darr2[cou].name, nname);

							g = i + 1;
							break;
						}
					}
					for (int i = g, zero = 0; i < LEN * 3; i++, zero++) {
						if (isalnum(cha[i])) {
							nnumb[zero] = cha[i];
						}
						else {
							strcpy(darr2[cou].numb, nnumb);
							break;
						}
					}
					cou += 1;
				}


			}
			else {
				printf("File not opened. 2\n");
			}
			more_people = lines_count;
			everything_darr2(f, darr2, more_people, lines_count);
			//free(darr2);//<- не хочет освобождать пам€ть

		}
		else {
			printf("First letter is not '1'\n");
			everything(f);
		}

	}
	else {

		printf("File not opened. 1\n");
		everything(f);

	}
	if (f) {
		fclose(f);
	}
	return 0;
}