#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//параметры трубы
struct pipe {
	string name = "";
	float length = 0, diametr = 0;
	int status = 0;
};
//параметры КС
struct CS {
	string name = "";
	int shop = 0, workingShop = 0;
	int effectiveness = 0;
};
//проверка целочисленных данных
void checkCS(int& x) {
	while ((cin >> x).fail() || (x < 0) || (cin.peek() != '\n')) {
		cout << "Error! Input correct value!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}
//проверка целочисленных данных для меню и рабочих цехов
void checkMenu(int& x) {
	while ((cin >> x).fail() || (x < 0) || (cin.peek() != '\n')) {
		cout << "Error! Input correct value!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}
//проверка параметров трубы
void checkPipe(float& x) {
	while (((cin >> x).fail()) || (x <= 0) || (cin.peek() != '\n')) {
		cout << "Error! Input correct value!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}
//проверка статуса трубы
void checkStatusOfPipe(int& x) {
	while (((cin >> x).fail()) || (x < 0) || (x > 1) || (cin.peek() != '\n')) {
		cout << "Error! Input correct value!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}
//проверка эффективности КС
void checkEffectiveness(int& x) {
	while (((cin >> x).fail()) || (x < 1) || (x > 10) || (cin.peek() != '\n')) {
		cout << "Error!\nInput value from 1 to 10!\n";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}
//менюшка
void menu() {
	cout << "\nChoose operation:" << endl
		<< " 1.Add pipe" << endl
		<< " 2.Add CS" << endl
		<< " 3.View all objects" << endl
		<< " 4.Edit pipe" << endl
		<< " 5.Edit CS" << endl
		<< " 6.Save" << endl
		<< " 7.Download" << endl
		<< " 0.Exit" << endl;
}

//статус работы трубы
void statusPipe(pipe& p) {
	if (p.status == 0) {
		cout << "Pipe is repairing\n";
	}
	else {
		cout << "Pipe works\n";
	}
}
//добавление трубы
void addPipe(pipe& p) {
	cout << "Input name:" << endl;
	cin >> p.name;
	cout << "Input lenght:\n";
	checkPipe(p.length);
	cout << "Input diametr:\n";
	checkPipe(p.diametr);
	cout << "Choose status of pipe:\n0.if repairing \n1.if works\n";
	checkStatusOfPipe(p.status);
	statusPipe(p);
}
//проверка (количество рабочих цехов не может быть больше всех)
void numberWorkingShops(int max, int& x) {
	while (((cin >> x).fail()) || (x < 0) || (x > max)) {
		cout << "Error!\n";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}
//добавление КС
void addCS(CS& cs) {
	cout << "Enter the name of the CS:\n";
	cin >> cs.name;
	cout << "Input the number of shops:\n";
	checkCS(cs.shop);
	cout << "Input the number of working shops:\n";
	numberWorkingShops(cs.shop, cs.workingShop);
	cout << "Enter CS efficiency (from 1 to 10)\n";
	checkEffectiveness(cs.effectiveness);
}
//просмотр всех объектов
void viewAll(pipe p, CS cs) {
	if (p.length != 0) {
		cout << "Pipe:\n";
		cout << "name:" << p.name << endl;
		cout << "length: " << p.length;
		cout << "\ndiametr: " << p.diametr;
		cout << "\nstatus: "; statusPipe(p);
	}
	else {
		cout << "\nThe pipe does not exist!";
	}
	if (cs.shop != 0) {
		cout << "\nCS:";
		cout << "\nName: " << cs.name;
		cout << "\nThe number of shops: " << cs.shop;
		cout << "\nThe number of working shops: " << cs.workingShop;
		cout << "\nCS efficiency: " << cs.effectiveness << endl;
	}
	else {
		cout << "\nThe CS does not exist!" << endl;
	}
}
//основная часть (body)
int main() {
	int operation = -1;
	pipe p;
	CS cs;
	while (true) {
		menu();
		checkMenu(operation);
		switch (operation) {
			//добавление трубы
		case 1: {
			addPipe(p);
			break;
		}
			  //добавление КС
		case 2: {
			addCS(cs);
			break;
		}
			  //просмотр всех объектов
		case 3: {
			viewAll(p, cs);
			break;
		}
			  // редактирование статуса трубы
		case 4: {
			editPipe(p);
			break;
		}
			  // редактирование количества рабочих цехов
		case 5: {
			editCS(cs);
			break;
		}
			  // сохранение данных в блокнот
		case 6: {
			saveData(p, cs);
			break;
		}
			  // выгрузка данных из блокнота
		case 7: {
			loadData(p, cs);
			break;
		}
			  // выход 
		case 0: {
			return 0;
		}
		default: {
			cout << "Error!\nInput correct value!\n";
		}
		}
	}
}