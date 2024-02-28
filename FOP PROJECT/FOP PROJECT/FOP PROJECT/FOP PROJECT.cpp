#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<ios>
#include<fstream>
#include<string>
using namespace std;

struct grades {
	string subject, grade_obtained;
	double credit_hours;
};

void display_data(int);
void Enter_data();
void Delete_data();
void Edit_data();
void Key_checker();
void Roll_checker();
void IDpos_searchengine();
void file_printer(int);
void ID_EXISTANCE(int);
void Data_entry();
void encrypt_data();
string Decrypt_line();
void Store_grades();
double grade_point_checker(string);
void find_transcript();
void print_transcript();
void encrypt_transcript(grades);
string Decrypt_transcript();

char ch, opt[6];
bool search, save;
string  roll, address, name, fname, dob, gender, E_subject, E_grade;
int c, x, id, n = 0, y, key; double cgpa, p;
fstream studentrec_file, Grade_rec;


int main()
{
	cout << "\n\n\n\n\n\t#" << setfill('#') << setw(95) << "#\n\t#" << setfill(' ') << setw(95) << "#\n\t#" << setfill(' ') << setw(50) << "WELCOME!" << setfill(' ') << setw(45) << "#\n\t#" << setfill(' ') << setw(95) << "#\n\t#" << setfill('#') << setw(95) << "#\n\n\n";
	Sleep(3000);
	system("cls");
	do {
		cout << "\t\t\t-----------------------\n\t\t\tWhat do you want to do?\n\t\t\t-----------------------\n\t\t\t1) Display the students record\n\t\t\t2) Add a new student to record\n\t\t\t3) Edit the records\n\t\t\t4) Erase all data\n\t\t\t5) Quit this program\n\nEnter your choice: ";
		cin >> c;
		switch (c) {
		case 1:
			do {
				cout << "\t\t\t1) To display all the record\n\t\t\t2) To display the record of a specific student\n\t\t\t3) To return tomain menu\nEnter your choice: " << endl;
				cin >> x;
				display_data(x);
			} while (x != 3);
			system("cls");

			break;
		case 2:
			Enter_data();
			system("cls");
			break;
		case 3:
			system("cls");
			Edit_data();
			system("pause");
			system("cls");
			break;
		case 4:
			Delete_data();
			system("cls");
			break;
		case 5:
			break;
		default:
			system("cls");
			cout << "\t\t\tInvalid Input\n" << endl;
			break;
		}
	} while (c != 5);
	system("cls");
	cout << "\n\n\n\n\n\t#" << setfill('#') << setw(95) << "#\n\t#" << setfill(' ') << setw(95) << "#\n\t#" << setfill(' ') << setw(60) << "THIS PROGRAM IS CREATED BY DEV.LABS" << setfill(' ') << setw(35) << "#\n\t#" << setfill(' ') << setw(95) << "#\n\t#" << setfill('#') << setw(95) << "#\n\n\n";
	Sleep(5000);
	system("cls");
	return 0;
}

void display_data(int x) {
	switch (x) {
	case 1:
		system("cls");
		Key_checker();
		if (key == 1234) {
			cout << "|" << setfill('-') << setw(159) << "|\n" << setfill(' ') << setw(10) << "Roll" << setw(13) << "Name" << setw(25) << "Gender" << setw(15) << "Father" << setw(25) << "CGPA" << setw(20) << "DOB" << setw(25) << "Address\n|" << setfill('-') << setw(158) << "|" << setfill(' ') << "\n" << setw(5);
			studentrec_file.open("new_file_write", ios::in);
			if (!studentrec_file)
				cout << "\n\nfile not found \n";
			else
				file_printer(y = 0);
			cout << endl;
			system("pause");
			system("cls");
			studentrec_file.close();
		}system("cls");
		break;
	case 2:
		system("cls");
		search = false;
		Roll_checker();
		if (roll.size() == 6) {
			studentrec_file.open("new_file_write", ios::in);
			if (studentrec_file) {
				IDpos_searchengine();
				if (search == true) {
					studentrec_file.close();
					studentrec_file.open("new_file_write", ios::in);
					studentrec_file.seekg(c, ios::beg);
					cout << "\t\tID FOUND\n|" << setfill('-') << setw(159) << "|\n" << setfill(' ') << setw(10) << "Roll" << setw(13) << "Name" << setw(25) << "Gender" << setw(15) << "Father" << setw(25) << "CGPA" << setw(20) << "DOB" << setw(25) << "Address\n|" << setfill('-') << setw(158) << "|" << setfill(' ') << "\n" << setw(5);
					file_printer(y = 2);
					cout << "\n#" << setfill('#') << setw(150) << "#\n" << setfill(' ') << setw(45) << "Transcript of student\n" << endl;
					find_transcript();
					Grade_rec.open("Transcript_file", ios::in);
					Grade_rec.seekg(p + 6, ios::beg);
					print_transcript();
				}
				else
					cout << "ID NOT FOUND" << endl;
				studentrec_file.close();
			}
			else
				cout << "File not found" << endl;
			cout << endl;
			system("pause");
		}
		system("cls");
		break;
	case 3:
		break;
	default:
		cout << "\t\t\tInvalid Input\n" << endl;
		break;
	}
}

void Enter_data() {
	int j = 0;
	save = false;
	system("cls");
	Key_checker();
	if (key == 1234) {
		roll = "";
		while (roll != "0" && save != true) {
			ID_EXISTANCE(y = 2);
			if (roll != "0" && search == false)
				Data_entry();
		}
	}
	if (save == true) {
		cout << "Data saved successfully" << endl;
		Sleep(1000);
	}
}

void Delete_data() {
	system("cls");
	Key_checker();
	if (key == 1234) {
		studentrec_file.open("new_file_write");
		if (!studentrec_file)
			cout << "File not found" << endl;
		else {
			ofstream studentrec_file("new_file_write", ios::trunc);
			ofstream Grade_rec("Transcript_file", ios::trunc);
			cout << "Data successfully removed!" << endl;
		}
	}
	studentrec_file.close();
	Sleep(2000);
}

void Edit_data() {
	string line3, replacement = "";
	int j, q;
	Key_checker();
	if (key = 1234) {
		save = false, search = false;
		while (roll != "0" && save != true) {
			ID_EXISTANCE(y = 1);
			system("cls");
			if (search == true) {
				line3 = Decrypt_line();
				j = line3.find(':');
				studentrec_file.seekg(0);
				studentrec_file >> line3;
				studentrec_file.close();
				line3.replace(c, j + 1, replacement);
				ofstream studentrec_file("new_file_write", ios::out);
				studentrec_file << line3;
				studentrec_file.close();
				cout << "\t\tEnter the following data and avoid using - , ; & :\n";
				find_transcript();
				line3 = Decrypt_transcript();
				q = line3.find(':');
				line3.replace(p, q + 1, replacement);
				ofstream Grade_rec("Transcript_file", ios::out);
				Grade_rec << line3;
				Grade_rec.close();
				cout << line3; system("pause");
				Data_entry();
			}
			if (save == true) {
				cout << "Data has been edited" << endl;
				Sleep(1000);
			}
		}
	}
}

void Key_checker() {
	::key = 0;
	cout << setfill(' ') << setw(35) << "Admin key required : ";
	while (key != 1234 && key != 2) {
		cin >> key;
		if (key != 1234 || key == 2)
			cout << "\n\t\tWrong key entered\n\t\tAdmin key required or enter 2 to exit to main menu : ";
	}
}

void Roll_checker() {
	roll = "";
	while (roll.size() != 6 && roll != "0") {
		cout << setfill(' ') << setw(35) << "Enter student's roll number : ";
		cin >> roll;
		if (roll.size() == 6)
			break;
		system("cls");
		cout << "\n\t\tIncorrect ID entered\n\t\tEnter 0 to exit to menu or\n";
	}
}

void IDpos_searchengine() {
	string line2; c = 0;
	line2 = Decrypt_line();
	::c = line2.find(roll);
	if (::c != string::npos)
		search = true;
}

void ID_EXISTANCE(int y) {
	studentrec_file.open("new_file_write");
	if (studentrec_file) {
		search = false;
		while (search != true && roll != "0") {
			Roll_checker();
			if (roll.size() == 6) {
				IDpos_searchengine();
				if (search == false || roll == "0") {
					if (y == 1 && roll != "0") {
						cout << "\nID doesn't exist in data" << endl;
						system("pause");
					}
					system("cls");
					break;
				}
				if (y == 2)
					cout << "\nID already exist in data" << endl;
				system("pause");
				system("cls");
				studentrec_file.close();
			}
		}
	}
}

string Decrypt_line() {
	string Q = "", line;
	studentrec_file.close();
	studentrec_file.seekg(c);
	studentrec_file.open("new_file_write", ios::in);
	studentrec_file >> line;
	for (int i = 0; line[i] != '\0'; i++) {
		int val = int(line[i]);
		if (val == 59 || val == 58 || val == 45 || val == 44)
			Q += char(val);
		else
			Q += char(val - 100);
	}
	studentrec_file.close();
	return Q;
}

void file_printer(int a) {
	while (!studentrec_file.eof()) {
		studentrec_file >> ch;
		if (ch == '<') {
			cout << setw(14);
			continue;
		}
		if (ch == '>') {
			if (y == 2) {
				cout << "\n";
				break;
			}
			else {
				cout << "\n" << setw(5);
				continue;
			}
		}
		if (ch == '^') {
			cout << setw(7);
			continue;
		}
		ch -= 100;
		if (ch == '?')
			cout << " ";
		else
			cout << ch;
	}
}

void Data_entry() {
	cout << "Please Enter the following data\n\n" << setfill(' ') << setw(45) << "Student name (Middle Last) : ";
	cin.ignore();
	getline(cin, name);
	for (int i = 0; name[i] != '\0'; i++) {
		if (name[i] == ' ')
			name[i] = '?';
	}
	if (name.size() > 14)
		name.replace(14, name.size(), "");
	if (name.size() < 14)
		name.insert(name.size(), 14, '?');

	cout << "\n" << setfill(' ') << setw(45) << "Father name (Middle Last) : ";
	cin.ignore(-1);
	getline(cin, fname);
	bool gender_check = false;
	while (gender_check != true) {
		cout << "\n" << setfill(' ') << setw(45) << "Student Gender (F/M/O) : ";
		cin.ignore(-1);
		getline(cin, gender);
		gender[0] = toupper(gender[0]);
		if (gender == "M" || gender == "F" || gender == "O")
			gender_check = true;
		else
			cout << "\n" << setfill(' ') << setw(45) << "Wrong gender entered!";
	}
	cout << "\n" << setfill(' ') << setw(45) << "Student's Address : ";
	cin.ignore(-1);
	getline(cin, address);
	for (int i = 0; fname[i] != '\0'; i++) {
		if (fname[i] == ' ')
			fname[i] = '?';
	}
	if (fname.size() > 14)
		fname.replace(14, fname.size(), "");
	if (fname.size() < 14)
		fname.insert(fname.size(), 14, '?');
	for (int i = 0; address[i] != '\0'; i++) {
		if (address[i] == ' ')
			address[i] = '?';
	}
	if (address.size() > 28)
		address.replace(28, address.size(), "");
	if (address.size() < 28)
		address.insert(address.size(), 28, '?');
	while (dob.size() != 8) {
		cout << "\n" << setfill(' ') << setw(45) << "Student's DOB (DD/MM/YY): ";
		cin.ignore(-1);
		getline(cin, dob);
		if (dob.size() > 8 || dob.size() < 8)
			cout << "\n" << setfill(' ') << setw(45) << "Wrong dob entered!";
	}
	encrypt_data();
	Store_grades();
	string c;
	c = to_string(cgpa);
	for (int i = 0; c[i] != '\0'; i++)
		c[i] += 100;  c.replace(4, c.size(), "");
	studentrec_file.open("new_file_write");
	if (!studentrec_file) {
		studentrec_file.open("new_file_write", ios::out);
		studentrec_file << roll << "^" << name << "<" << gender << "<" << fname << "<" << c << "<" << dob << "<" << address << ">";
	}

	else {
		ofstream studentrec_file("new_file_write", ios::app);
		studentrec_file << roll << "^" << name << "<" << gender << "<" << fname << "<" << c << "<" << dob << "<" << address << ">";
	}
	studentrec_file.close();
	cout << endl;
	save = true;
}

void encrypt_data() {
	for (int i = 0; roll[i] != '\0'; i++)
		roll[i] += 100;
	for (int i = 0; name[i] != '\0'; i++)
		name[i] += 100;
	for (int i = 0; fname[i] != '\0'; i++)
		fname[i] += 100;
	for (int i = 0; dob[i] != '\0'; i++)
		dob[i] += 100;
	for (int i = 0; address[i] != '\0'; i++)
		address[i] += 100;
	for (int i = 0; gender[i] != '\0'; i++)
		gender[i] += 100;
}

void Store_grades() {
	int totalcredithours = 0; cgpa = 0; double grade_point, totalpoints = 0;  bool verify; grades* subject; string grade;
	cout << "\n" << setw(45) << "Number of subjects : ";
	cin >> n;
	subject = new (nothrow) grades[n];
	Grade_rec.open("Transcrip_file");
	if (!Grade_rec) {
		Grade_rec.open("Transcript_file", ios::out);
		Grade_rec << ":" << roll;
		Grade_rec.close();
	}
	else {
		Grade_rec.open("Transcript_file", ios::app);
		Grade_rec << roll;
		Grade_rec.close();
	}
	std::cin.clear();
	for (int i = 0; i < n; i++) {
		system("cls");
		cout << "\n" << setw(65) << "Enter subject " << i + 1 << " name : ";
		cin >> subject[i].subject;
		std::cin.clear();
		if (subject[i].subject.size() > 4)
			subject[i].subject.replace(4, subject[i].subject.size(), "");
		if (subject[i].subject.size() < 4)
			subject[i].subject.insert(subject[i].subject.size(), 4, ',');
		verify = false;
		while (verify != true) {
			cout << "\n" << setw(65) << "please enter grades from A - F, (may include +/-) : ";
			cin >> grade;
			std::cin.clear();
			grade[0] = toupper(grade[0]);
			if (grade == "A-" || grade == "A+" || grade == "A" || grade == "B-" || grade == "B+" || grade == "B" || grade == "C-" || grade == "C+" || grade == "C" || grade == "D-" || grade == "D+" || grade == "D" || grade == "F")
				verify = true;
			else
				cout << "\n" << setw(65) << "wrong grade entered!";
		}
		subject[i].grade_obtained = grade;
		cout << "\n" << setw(65) << "Enter credit hour : ";
		cin >> subject[i].credit_hours;
		std::cin.clear();
		grade_point = grade_point_checker(subject[i].grade_obtained);
		totalpoints += (grade_point * subject[i].credit_hours);
		totalcredithours += subject[i].credit_hours;
		encrypt_transcript(subject[i]);
		Grade_rec.open("Transcript_file", ios::app);
		Grade_rec << ";" << E_subject << "-" << E_grade;
		Grade_rec.close();
	}
	Grade_rec.open("Transcript_file", ios::app);
	Grade_rec << ":";
	Grade_rec.close();
	cgpa = totalpoints / totalcredithours;
}

double grade_point_checker(string x) {
	double y;
	if (x == "A+" || x == "A")
		y = 4.0;
	if (x == "A-")
		y = 3.7;
	if (x == "B+")
		y = 3.3;
	if (x == "B")
		y = 3.0;
	if (x == "B-")
		y = 2.7;
	if (x == "C+")
		y = 2.3;
	if (x == "C")
		y = 2.0;
	if (x == "C-")
		y = 1.7;
	if (x == "D+")
		y = 1.3;
	if (x == "D")
		y = 1.0;
	if (x == "F")
		y = 0;
	return y;
}

void find_transcript() {
	string line4; p = 0;
	line4 = Decrypt_transcript();
	::p = line4.find(roll);
}

void encrypt_transcript(grades x) {
	E_subject = x.subject;
	E_grade = x.grade_obtained;
	for (int i = 0; E_subject[i] != '\0'; i++)
		E_subject[i] += 100;
	for (int i = 0; E_grade[i] != '\0'; i++)
		E_grade[i] += 100;
}

void print_transcript() {
	while (!Grade_rec.eof()) {
		Grade_rec >> ch;
		if (ch == ';') {
			cout << "\n" << setw(15);
			continue;
		}
		if (ch == ':')
			break;
		if (ch == ',') {
			cout << " ";
			continue;
		}
		if (ch == '-') {
			cout << setw(16);
			continue;
		}
		cout << char(ch - 100);
	}
}

string Decrypt_transcript() {
	string Q, line5; Q = "";
	Grade_rec.close();
	Grade_rec.seekg(p);
	Grade_rec.open("Transcript_file", ios::in);
	Grade_rec >> line5;
	for (int i = 0; line5[i] != '\0'; i++) {
		int val = int(line5[i]);
		if (val == 59 || val == 58 || val == 45)
			Q += char(val);
		else
			Q += char(val - 100);
	}
	Grade_rec.close();
	return Q;
}
