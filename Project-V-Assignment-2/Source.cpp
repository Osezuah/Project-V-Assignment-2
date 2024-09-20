#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

typedef struct STUDENT_DATA {
	string firstname;
	string lastname;
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

int main(void) {
	ReadStudentData();
	return 1;
}