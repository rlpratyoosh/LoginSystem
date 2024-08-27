#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
	string id, password, line;
	int choose = 0;
	bool found = false;
	bool login = false;
start:
	system("cls");
	system("color 2");
	cout << "WELCOME TO THE LOGIN WINDOW" << endl;
	cout << "1. Login" << endl;
	cout << "2. Register" << endl;
	cout << "3. Quit" << endl;
	cin >> choose;
	
	switch (choose)
	{
	case 1:
	{
		system("cls");
		cout << "Enter Id: ";
		cin >> id;
		ifstream in("ids.csv");
		if (!in.is_open()) {
			cout << "Error opening file" << endl;
			return 1;
		}
		getline(in, line);
		while (getline(in, line)) {
			stringstream ss(line);
			string tempId;
			string tempPassword;
			getline(ss, tempId, ',');
			getline(ss, tempPassword);
			if (id == tempId) {
				cout << "Enter Password: ";
				cin >> password;
				found = true;
				if (password == tempPassword) {
					cout << "Logged In Successfully" << endl;
					login = true;
					this_thread::sleep_for(chrono::seconds(2));
					break;
				}
				else {
					system("cls");
					cout << "Wrong Password" << endl;
					this_thread::sleep_for(chrono::seconds(2));
					goto start;
				}
			}
		}
		if (!found) {
			cout << "Id not Found" << endl;
		}
		break;
	}
	case 2:
	{
		system("cls");
		cout << "Enter Id: ";
		cin >> id;
		cout << "Enter Password: ";
		cin >> password;
		ofstream out("ids.csv", ios::app);
		if (!out.is_open()) {
			cout << "Error Opening File" << endl;
		}
		out << endl << id << "," << password;
		out.close();
		cout << "Registered Successfully" << endl;
		this_thread::sleep_for(chrono::seconds(2));
		break;
	}
	case 3:
		goto end;
	default:
		cout << "Invalid Input" << endl;
		break;
	}
	goto start;
end:
	cout << "Login Condition: " << login << endl;
	cout << "Quitting...";
	return 0;
}