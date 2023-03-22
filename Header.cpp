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
		cout << "1. ���� ��������� ������ 1e-6 < a <= 30 ; 1e-6 < b <= 1 ����� �������" << endl;
		cout << "2. ���� ��������� ������ ����� ����" << endl;
		cout << "3. ����� �������� (5/4)*a*|Xn - Xn-1| < b ����� ���� ����������� �������" << endl;
		cout << "4. ����� �������� (5/4)*a*|Xn - Xn-1| < b ����� ����" << endl;
		cout << "5. ����� ���������� ������ ��������� �� �����, � �������" << endl;
		cout << "6. �������" << endl;
		cout << "7. ������" << endl;
		cout << "8. ���������� ������" << endl;
		do
		{
			cout << "������� ����� ���� �� 1 �� 8 --> ";
			cin >> choice;
			if ((choice < 1) || (choice > 8))
			{
				cout << "������ �������� �������, ��������� ����" << endl;
			}
			if (cin.fail())
			{
				cout << endl << "������ �������� �������, ��������� ����" << endl;
				cin.clear();
				cin.ignore(32767, '\n'); /*������ �� ����� ��������*/
				choice = -1;
			}
			if ((proverka == false) && ((choice == 3) || (choice == 4)))
			{
				cout << "�� ����� �������� ������, �� �� ������ ������ ������������ ������ �� ����� �� �������������� ��������." << endl << "��������� ����, ��� ����� ������� 1, ������� 1�-6 < a < 30, 1e-6 < b < 1" << endl << "��� ������� 2, ������ ����� ������� ������������� �� �����." << endl;
				choice = -1;
			}
			if ((proverka1 == false) && (choice == 5))
			{
				cout << "�� ��������� �������, �� �� ������ ������� ������, ����������� �������, ��� ����� ������� 3 ��� 4" << endl;
				choice = -1;
			}
		} while ((choice < 1) || (choice > 8));
		switch (choice)
		{
		case 1:
			cout << "�� ������� �������� �� ������� " << endl;
			fout << "�� ������� �������� �� ������� " << endl;
			input(a, b);
			proverka = true;
			fout << "a=" << a << endl;
			fout << "b=" << b << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "�������� ����� ������� � ����� " << endl;
			fout << "�������� ����� ������� � ����� " << endl;
			inputfile(a, b);
			proverka = true;
			system("pause");
			system("cls");
			break;
		case 3:
			fout << "������� �� ��������� � ������� ��������" << endl;
			cout << "������� �� ��������� � ������� ��������" << endl;
			rekurs(a, b, v, rez, n, x2);
			proverka1 = true;
			system("pause");
			system("cls");
			break;
		case 4:
			fout << "������� �� ��������� � ������� �����" << endl;
			cout << "������� �� ��������� � ������� �����" << endl;
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
			cout << "������ ���������" << endl;
			fout << "������ ���������" << endl;
			fout << "----------------" << endl << endl << endl;
			fout.close();
			break;
		default:
			cout << "����� ������� ���!" << endl;
			break;
		}
	} while (choice != 8);
}