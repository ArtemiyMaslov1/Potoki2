#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;



void RussianMassage(const char* massage)
{
	char remessage[256];
	CharToOemA(massage, remessage);
	cout << remessage;
}
int RussianMenu()
{
	RussianMassage("\nВведите 1 для добавления новой структуры в файл\n");
	RussianMassage("\nВведите 2 для показа всех структур из файла\n");
	RussianMassage("\nВведите 3 для выхода\n");
	int choice;
	cin >> choice;
	return choice;
}

class Man
{
	int age;
	char* name;
	char* surname;
public:
	Man(const char* n, const char* s, int a)
	{
		name = new char[strlen(n) + 1];
		if (!name)
			RussianMassage("Ошибка при выделение памяти !!!");
		exit(1);
		strcpy(name, n);
		surname = new char[strlen(s) + 1];
		if (!surname)
			RussianMassage("Ошибка при выделение памяти !!!");
		exit(1);
		strcpy(surname, s);
		age = a;
	}

	Man()
	{
		name = 0;
		surname = 0;
		age = 0;
	}
	~Man()
	{
		delete[] name;
		delete[] surname;
	}
	void Put()
	{
		char temp[1024];
		RussianMassage("\nВведите имя:\n");
		cin >> temp;
		if (name)
			delete[]name;
		name = new char[strlen(temp) + 1];
		if (!name)
		{
			RussianMassage("Ошибка при выделение памяти !!!");
			exit(1);
		}
		strcpy(name, temp);

		RussianMassage("\nВведите фамилию:\n");
		cin >> temp;
		if (surname)
			delete[]surname;
		surname = new char[strlen(temp) + 1];
		if (!surname)
		{
			RussianMassage("Ошибка при выделение памяти !!!");
			exit(1);
		}
		strcpy(surname, temp);

		RussianMassage("\nВведите возраст:\n");
		cin >> age;
	}

	void Show()
	{
		RussianMassage("\nИмя:\n");
		cout << name;
		RussianMassage("\nИмя:\n");
		cout << surname;
		RussianMassage("\nИмя:\n");
		cout << age << endl;
	}

	void SaveToFile()
	{
		int size;
		fstream f("men.txt", ios::out | ios::binary | ios::app);
		if (!f)
		{
			RussianMassage("\nФайл не открылся для записи!!!:\n");
			exit(1);
		}
		f.write((char*)&age, sizeof(age));
		size = strlen(name);
		f.write((char*)&size, sizeof(int));
		f.write((char*)name, sizeof(char));
		size = strlen(surname);
		f.write((char*)&size, sizeof(int));
		f.write((char*)surname, sizeof(char));
		f.close();
	}
	void ShowFromFile()
	{
		fstream f("men.txt", ios::out | ios::binary);
		if (!f)
		{
			RussianMassage("Файл не открылся для записи!!!");
			exit(1);
		}
		char* n, * s;
		int a;
		int temp;
		while (f.read((char*)&a, sizeof(int)))
		{
			RussianMassage("\nИмя:\n");
			f.read((char*)&temp, sizeof(int));
			n = new char[temp + 1];
			if (!n)
			{
				RussianMassage("Файл не открылся для записи!!!");
				exit(1);
			}
			f.read((char*)n, temp *sizeof(int));
			n[temp] = '\0';
			cout << n;

			RussianMassage("\nФамилия:\n");
			f.read((char*)&temp, sizeof(int));
			s = new char[temp + 1];
			if (!s)
			{
				RussianMassage("Файл не открылся для записи!!!");
				exit(1);
			}
			f.read((char*)s, temp * sizeof(int));
			n[temp] = '\0';
			cout << s;

			RussianMassage("\nВозраст:\n");
			cout << a << endl;
			delete[] n;
			delete[] s;
		}
	}
};

int main()
{
	Man* a;
	do
	{
		switch (RussianMenu())
		{
		case 1:
			a = new Man;
			a->Put();
			a->SaveToFile();
			delete a;
			break;
		case 2:
			a = new Man;
			a->SaveToFile();
			delete a;
			break;
		case 3:
			RussianMassage("\nДо свидания\n");
			return 0;
		default:
			RussianMassage("\nНеверный ввод\n");
		}
	} while (1);
	return 0;
}