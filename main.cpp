#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
#include<Windows.h>
#include "Welcome.h"
#include <vector>
#include <algorithm>
using namespace std;

struct teachers {
	string fam;
	string name;
	enum status { prepod=1, docent, doctor_nauk } st;
	int status_int;
};

vector<struct teachers> teacherList; // ������� ������ ������ ��������
void dobav()
{
	struct teachers teacher;
	cout << "������� ������� : ";
	cin >> teacher.fam;
	cout << "������� ��� : ";
	cin >> teacher.name;
	cout << "������� ������ (1-�������������, 2-������, 3-������ ���� : " << endl;
	int i;
	cin >> i;
	switch (i)
	{
	case 1:
		teacher.st = teachers::prepod;break;

	case 2:
		teacher.st = teachers::docent;break;

	case 3:
		teacher.st = teachers::doctor_nauk;break;
	}
	teacher.status_int = i;
	//teachers::status= static_cast<teachers::status>(statusInput);
	// ��������� ������� � ������
	teacherList.push_back(teacher);
}
string state_switch(teachers::status st) {
	switch (st) {
	case teachers::prepod:
		return "�������������";
	case teachers::docent:
		return "������";
	case teachers::doctor_nauk:
		return "������ ����";
	default:
		return "����������� ������";
	}
}

void print() {
	cout << "..................................................................................."<<endl;
	cout <<endl<<setw(1)<<"�"<< setw(13) << "�������" << setw(15) << "��� " << setw(15) << "������" << endl;
	for (size_t i = 0; i < teacherList.size(); ++i) {
		string statusString = state_switch(teacherList[i].st);
		cout << setw(1) << i + 1 << ": " << setw(12) << teacherList[i].fam<< setw(14) << teacherList[i].name<<setw(15)<< statusString << endl;
	}
	cout << "..................................................................................." << endl<<endl<<endl<<endl;
}

void poisk_fam_name() {
	string fam_p, name_p;
	cout << "������ ������� � ��� ������������, �������� �� ������ ����� : ";
	cin >> fam_p >> name_p;
	cout << endl;
	int flag = 0;
	for (size_t i = 0; i < teacherList.size(); ++i) {
		string statusString = state_switch(teacherList[i].st);
		if (fam_p == teacherList[i].fam && name_p == teacherList[i].name) {
			cout<<"������� ������������: " << setw(1) << i + 1 << ": " << setw(12) << teacherList[i].fam << setw(14) << teacherList[i].name << setw(15) << statusString << endl;
			flag = 1;

		}
	}
	if (flag == 0) cout << "������ ������������ ���"<<endl;
}

void poisk_status() {
	int stat_i;
	cout << "������ ������ ������������(��), ��������(��) �� ������ �����(�������������=1, ������=2, ������ ����-3) : ";
	cin >> stat_i;cout << endl;
	int flag = 0;
	for (size_t i = 0; i < teacherList.size(); ++i) {
		string statusString = state_switch(teacherList[i].st);
		if (stat_i == teacherList[i].status_int) {
			cout<< setw(1) << i + 1 << ": " << setw(12) << teacherList[i].fam << setw(14) << teacherList[i].name << setw(15) << statusString << endl;
			flag = 1;
		}
	}
	if (flag == 0) cout << "��� ������������� � ����� ��������" << endl;
}

bool compareByFam(const teachers& a, const teachers& b) {
	return a.fam < b.fam;
}

void filtr_fam() {
	// ���������� ������ �������� �� �������
	sort(teacherList.begin(), teacherList.end(), compareByFam);
	// ����� ���������������� ������ ��������
	print();
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	int size = 0;
	int q;
	welcome();
	cin >> q;
	string s;
	 
	while (q != 0) {
		if (q == 1) {
			dobav();
		}
		if (q == 2) print();
		if (q == 3) poisk_fam_name();
		if (q == 4) poisk_status();
		if (q == 5) filtr_fam();
		welcome();
		cin >> q;
	}

	cin.get();
}