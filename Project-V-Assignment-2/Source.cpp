#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

typedef struct STUDENT_DATA {
	string firstname;
	string lastname;
	string email; //step #5 new functionality
}STUDENT_DATA;

void ReadStudentData() {
	string filePath = ".\\StudentData.txt";
	ifstream readData(filePath);
	STUDENT_DATA student;
	
	string line;
	vector<STUDENT_DATA> vStudentData;
	if (readData.is_open()) {
		while (getline(readData, line)) {
			stringstream ss(line);
			getline(ss, student.firstname, ',');
			getline(ss, student.lastname, ',');
			
			vStudentData.push_back(student);
		}
		for (auto& data : vStudentData) {
			cout << data.firstname << " " << data.lastname << endl;
		}
	}
	else
		cout << "I don't have access to this file" << endl;
	readData.close();
}
void ReadStudentData_Emails() {
	string filePath = ".\\StudentData_Emails.txt";
	ifstream readData_Emails(filePath);
	STUDENT_DATA student;

	string line;
	vector<STUDENT_DATA> vStudentData_Emails;
	if (readData_Emails.is_open()) {
		while (getline(readData_Emails, line)) {
			stringstream ss(line);
			getline(ss, student.firstname, ',');
			getline(ss, student.lastname, ',');
			getline(ss, student.email, ',');

			vStudentData_Emails.push_back(student);
		}
		for (auto& data : vStudentData_Emails) {
			cout << data.firstname << " " << data.lastname << " " << data.email << endl;
		}
	}
	else
		cout << "I don't have access to this file" << endl;
	readData_Emails.close();
}

#define PRE_RELEASE

int main(void) {
	#ifdef PRE_RELEASE
		cout << "THE APPLICATION IS RUNNING THE PRE-RELEASE SOURCE CODE\n";
		ReadStudentData_Emails();
	#else
		cout << "THE APPLICATION IS RUNNING THE STANDARD SOURCE CODE\n";
	#endif //PRE_RELEASE

	#ifdef _DEBUG
		cout << "\n";
		cout << "DEBUG MODE\n";
		ReadStudentData();
	#endif // _DEBUG

	return 1;
}