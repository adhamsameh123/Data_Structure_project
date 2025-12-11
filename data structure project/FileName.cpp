#include<iostream>
using namespace std;
class Branch {
public:
	int id;//عاوز احسنه اخلي المستخدم ميدخلوش 
	string name;
	string location;
	Branch* next;
	Branch() {
		id = 0;
		name = "unknown";
		location = "unknown";
		next = NULL;
	}
};
class BranchLinkedList {
public:
	Branch* head = NULL;
	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	void addBranch(int id, string name, string location) { //insert from front later i will make insert from end
		Branch* newBranch = new Branch;
		newBranch->id = id;
		newBranch->name = name;
		newBranch->location = location;
		if (isEmpty()) {
			head = newBranch;
		}
		else {
			newBranch->next = head;
			head = newBranch;
		}
	}
	bool searchBranchById(int id) {
		Branch* temp = head;
		while (temp->next != NULL) {
			if (temp->id == id) {
				cout << "Branch was found";
				cout << "it's name is:" << temp->name << "it's address is:" << temp->location;
				return true;
			}
			temp = temp->next;
		}
		cout << "location was not found";
		return false;
	}
	void DisplayBranches() {
		Branch* temp = head;
		while (temp->next != NULL) {
			cout << "Branch id:" << temp->id << "Branch name:" << temp->name << "Branch location:" << temp->location<<endl;
			temp = temp->next;
		}
	}
	void removeBranch(int id) {
		if (searchBranchById(id)) {
			Branch* current = head;
			//if Branch is first node we use delete at first method
			if (head->id == id) {
				head = head->next;
				delete current;
			}
			else {
				Branch* previous = NULL;
				while (current->id != id) {
					previous = current;
					current = current->next;
				}
				previous->next = current->next;
				delete current;
			}
		}
		else {
			cout << "please enter Branch id in the list of Branch";
		}
	}
};
class Doctor {
public:
	int id;//عاوز احسنه اخلي المستخدم ميدخلوش 
	string name;
	string Specialization;
	string hospitalBranch; // مش عارف دي صح ولا لا 
	Doctor* next;
	Doctor() {
		id = 0;
		name = "unknown";
		Specialization= "unknown";
		hospitalBranch= "unknown";
		next = NULL;
	}
};
class DoctorLinkedList {
public:
	Doctor* head = NULL;
	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	void addDoctor(int id, string name, string Specialization, string hospitalBranch) { //insert from front later i will make insert from end
		Doctor* newDoctor = new Doctor;
		newDoctor->id = id;
		newDoctor->name = name;
		newDoctor->Specialization = Specialization;
		newDoctor->hospitalBranch = hospitalBranch;
		if (isEmpty()) {
			head = newDoctor;
		}
		else {
			newDoctor->next = head;
			head = newDoctor;
		}
	}
	bool searchDoctorById(int id) {
		Doctor* temp = head;
		while (temp->next != NULL) {
			if (temp->id == id) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	void removeDoctor(int id) {
		if (searchDoctorById(id)) {
			Doctor* current = head;
			//if Doctor is first node we use delete at first method
			if (head->id == id) {
				head = head->next;
				delete current;
			}
			else {
				Doctor* previous = NULL;
				while (current->id != id) {
					previous = current;
					current = current->next;
				}
				previous->next = current->next;
				delete current;
			}
		}
		else {
			cout << "please enter Doctor id in the list of Doctor";
		}
	}
	void DisplayAppointments(){}//مش عارف هنعلمها ازاي لسه 

};
class Patient {
public:
	int id; //عاوز احسنه اخلي المستخدم ميدخلوش 
	string name;
	string address;
	string appointment;
	Patient* next;
	Patient() {
		id = 0;
		name = "unknown";
		address = "unknown";
		appointment = "unknown";
		next = NULL;
	}
};
class PatientLinkedList {
public:
	Patient* head = NULL;
	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	void addPatient(int id, string name, string address, string appointment) { //insert from front later i will make insert from end
		Patient* newPatient = new Patient;
		newPatient->id = id;
		newPatient->name = name;
		newPatient->address = address;
		newPatient->appointment = appointment;
		if (isEmpty()) {
			head = newPatient;
		}
		else {
			newPatient->next = head;
			head = newPatient;
		}
	}
	bool searchPatientById(int id) {
		Patient* temp = head;
		while (temp->next != NULL) {
			if (temp->id == id) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	bool searchPatientByName(string name) {
		Patient* temp = head;
		while (temp->next != NULL) {
			if (temp->name == name) {
				cout << "Patient was found";
				cout << "they id is:" << temp->id << "they address is:" << temp->address << "they Appointment is:" << temp->appointment;
				return true;
			}
			temp = temp->next;
		}
		cout<< "Patient was not found";
		return false;
	}
	void removePatient(int id) {
		if (searchPatientById(id)) {
			Patient* current = head;
			//if Patient is first node we use delete at first method
			if (head->id == id) {
				head = head->next;
				delete current;
			}
			else {
				Patient* previous = NULL;
				while (current->id != id) {
					previous = current;
					current = current->next;
				}
				previous->next = current->next;
				delete current;
			}
		}
		else {
			cout << "please enter patient id in the list of patient";
		}
	}
	void bookAppointment(){}//مش عارف هنعلمها ازاي لسه 
	void updatePatientInformation() {
		cout << "enter Patient id for the Patient you want to update they information";
		int id;
		cin >> id;
		if (searchPatientById(id)) {
			cout << "enter number the represent the information you want to update";
			cout << "[1] to update id"<<endl;
			cout << "[2] to update name" << endl;
			cout << "[3] to update address" << endl;
			cout << "[4] to update Appointment" << endl;
			cout << "[5] to update all information" << endl;
			int operationId;
			cin >> operationId;
			Patient* temp = head;
			while (temp->next != NULL) {
				if (temp->id == id) {
					break;
				}
				temp = temp->next;
			}
			switch(operationId) {
				case 1:{
					cout << "enter the new id";
					int newId;
					cin >> newId;
					temp->id = newId;
					break;
				}
				case 2:{
					cout << "enter the new name";
					string newName;
					cin >> newName;
					temp->name = newName;
					break;
				}
				case 3:{
					cout << "enter the new address";
					string newAddress;
					cin >> newAddress;
					temp->address = newAddress;
					break;
				}
				case 4:{
					cout << "enter the new Appointment";
					string newAppointment;
					cin >> newAppointment;
					temp->appointment = newAppointment;
					break;
				}
				case 5:{
					int newId;
					string newName;
					string newAddress;
					string newAppointment;
					cout << "enter the new id";
					cin >> newId;
					cout << "enter the new name";
					cin >> newName;
					cout << "enter the new address";
					cin >> newAddress;
					cout << "enter the new Appointment";
					cin >> newAppointment;
					temp->id = newId;
					temp->name = newName;
					temp->address = newAddress;
					temp->appointment = newAppointment;
					break;
				}
				default:{
					cout << "enter valid number";
					break;
				}
			}

		}
		else {
			cout << "please enter patient id in the list of patient";
		}
	}
};


int main() {

}