#include <iostream> 
#include <string>
#include <windows.h>  
#include <iomanip>  
#include <fstream>   
#include "Header.h"  

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double a, b, v, rez, x2, n;
	bool proverka = false;
	bool proverka1 = false;
	int choice;
	ofstream fout;
	fout.open("rezultat.txt", ios::app);

	do
	{
		cout << "1. Ввод начальных данных 1e-6 < a <= 30 ; 1e-6 < b <= 1 через консоль" << endl;
		cout << "2. Ввод начальных данных через файл" << endl;
		cout << "3. Поиск элемента (5/4)*a*|Xn - Xn-1| < b через цикл рекурсивной функции" << endl;
		cout << "4. Поиск элемента (5/4)*a*|Xn - Xn-1| < b через цикл" << endl;
		cout << "5. Вывод результата работы программы на экран, в консоль" << endl;
		cout << "6. Справка" << endl;
		cout << "7. Помощь" << endl;
		cout << "8. Завершение работы" << endl;
		do
		{
			cout << "Введите пункт меню от 1 до 8 --> ";
			cin >> choice;
			if ((choice < 1) || (choice > 8))
			{
				cout << "Данное значение неверно, повторите ввод" << endl;
			}
			if (cin.fail())
			{
				cout << endl << "Данное значение неверно, повторите ввод" << endl;
				cin.clear();
				cin.ignore(32767, '\n'); /*Защита от ввода символов*/
				choice = -1;
			}
			if ((proverka == false) && ((choice == 3) || (choice == 4)))
			{
				cout << "Не введя исходные данные, вы не можете решать поставленную задачу ни одним из представленных способов." << endl << "Повторите ввод, для этого нажмите 1, введите 1е-6 < a < 30, 1e-6 < b < 1" << endl << "Или нажмите 2, данные будут введены автоматически из файла." << endl;
				choice = -1;
			}
			if ((proverka1 == false) && (choice == 5))
			{
				cout << "Не произведя расчеты, вы не можете вывести данные, произведите расчеты, для этого нажмите 3 или 4" << endl;
				choice = -1;
			}
		} while ((choice < 1) || (choice > 8));
		switch (choice)
		{
		case 1:
			cout << "Вы вводите значение из консоли " << endl;
			fout << "Вы вводите значение из консоли " << endl;
			input(a, b);
			proverka = true;
			fout << "a=" << a << endl;
			fout << "b=" << b << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "Значение будет введено и файла " << endl;
			fout << "Значение будет введено и файла " << endl;
			inputfile(a, b);
			proverka = true;
			system("pause");
			system("cls");
			break;
		case 3:
			fout << "Расчеты по итерациям с помощью рекурсии" << endl;
			cout << "Расчеты по итерациям с помощью рекурсии" << endl;
			rekurs(a, b, v, rez, n, x2);
			proverka1 = true;
			system("pause");
			system("cls");
			break;
		case 4:
			fout << "Расчеты по итерациям с помощью цикла" << endl;
			cout << "Расчеты по итерациям с помощью цикла" << endl;
			zikl(a, b, v, rez, n, x2);
			proverka1 = true;
			system("pause");
			system("cls");
			break;
		case 5:
			output(a, b, v, rez, n, x2);
			system("pause");
			system("cls");
			break;
		case 6:
			about();
			system("pause");
			system("cls");
			break;
		case 7:
			help();
			system("pause");
			system("cls");
			break;
		case 8:
			cout << "Работа завершена" << endl;
			fout << "Работа завершена" << endl;
			fout << "----------------" << endl << endl << endl;
			fout.close();
			break;
		default:
			cout << "Такой функции нет!" << endl;
			break;
		}
	} while (choice != 8);
}