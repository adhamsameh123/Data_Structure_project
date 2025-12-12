#include<iostream>
using namespace std;
class Branch {
public:
	int id;
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
	void addBranch(int id, string name, string location) { 
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
	void addBranchFromEnd(int id, string name, string location) { 
		Branch* newBranch = new Branch;
		newBranch->id = id;
		newBranch->name = name;
		newBranch->location = location;
		Branch* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newBranch;
	}
	bool searchBranchById(int id) {
		Branch* temp = head;
		//if the patient was the first and only node in list
		if (temp->id == id) {
			cout << "Branch was found";
			cout << "it's name is:" << temp->name << "it's address is:" << temp->location;
			return true;
		}
		while (temp->next != NULL) {
			if (temp->id == id) {
				cout << "Branch was found";
				cout << "it's name is:" << temp->name << "it's address is:" << temp->location;
				return true;
			}
			temp = temp->next;
		}
		//check if patient in the last node
		if (temp->id == id) {
			cout << "Branch was found";
			cout << "it's name is:" << temp->name << "it's address is:" << temp->location;
			return true;
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
	void DisplayAppointmentsPerBranch(BranchLinkedList& branches, DoctorLinkedList& doctors, PatientLinkedList& patients) {
		Branch* branch = branches.head;

		while (branch != NULL) {
			cout << "Branch ID: " << branch->id << "Name: " << branch->name << "Location: " << branch->location << endl;
			cout << "---------------------------------" << endl;

			Doctor* doc = doctors.head;
			bool anyAppointments = false;

			while (doc != NULL) {
				if (doc->hospitalBranch == branch->id) {
					Patient* p = patients.head;

					while (p != NULL) {
						if (p->appointment.doctorId == doc->id) {
							cout << "Doctor: " << doc->name << "Patient: " << p->name<< "Date: " << p->appointment.date<< "Time: " << p->appointment.time << endl;
							anyAppointments = true;
						}
						p = p->next;
					}
				}
				doc = doc->next;
			}

			if (!anyAppointments) {
				cout << "No appointments in this branch." << endl;
			}

			cout << endl;
			branch = branch->next;
		}
	}

};
class Doctor {
public:
	int id;
	string name;
	string Specialization;
	int hospitalBranch; // this the id of the branch that doctor work in 
	Doctor* next;
	Doctor() {
		id = 0;
		name = "unknown";
		Specialization= "unknown";
		hospitalBranch = 0;
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
	void addDoctor(int id, string name, string Specialization,BranchLinkedList branch,int hospitalBranch) {
		Doctor* newDoctor = new Doctor;
		newDoctor->id = id;
		newDoctor->name = name;
		newDoctor->Specialization = Specialization;
		if (!branch.searchBranchById(hospitalBranch)) {
			cout << "please enter a valid Branch id";
		}
		newDoctor->hospitalBranch = hospitalBranch;
		if (isEmpty()) {
			head = newDoctor;
		}
		else {
			newDoctor->next = head;
			head = newDoctor;
		}
	}
	void addBranchFromEnd(int id, string name, string Specialization, int hospitalBranch) {
		Doctor* newDoctor = new Doctor;
		newDoctor->id = id;
		newDoctor->name = name;
		newDoctor->Specialization = Specialization;
		newDoctor->hospitalBranch = hospitalBranch;
		Doctor* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newDoctor;
	}
	bool searchDoctorById(int id) {
		Doctor* temp = head;
		//if the Doctor was the first and only node in list
		if (temp->id == id) {
			return true;
		}
		while (temp->next != NULL) {
			if (temp->id == id) {
				return true;
			}
			temp = temp->next;
		}
		//check if Doctor in the last node
		if (temp->id == id) {
			return true;
		}
		return false;
	}
	int searchDoctorByNameAndReturnID(string name) {
		Doctor* temp = head;
		//if the doctor was the first and only node in list
		if (temp->name == name) {
			return temp->id;
		}

		while (temp->next != NULL) {
			if (temp->name == name) {
				return temp->id;
			}
			temp = temp->next;
		}
		//check if doctor in the last node
		if (temp->name == name) {
			return temp->id;
		}
		cout << "doctor was not found" << endl;
		return -1;
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
	void DisplayAppointments(PatientLinkedList& patients) {
		if (isEmpty()) {
			cout << "Doctor list is empty" << endl;
			return;
		}

		cout << "Enter doctor ID to view his appointments: ";
		int doctorId;
		cin >> doctorId;

		if (!searchDoctorById(doctorId)) {
			cout << "Doctor not found." << endl;
			return;
		}

		//نعدي علي المرضي في قائمة المرضي ونشوف مين فيهم الي حاجز مع الدكتور ده ونقوم نعرض معلومات الحجز واسم المريض 
		Patient* temp = patients.head;
		bool found = false;

		while (temp != NULL) {
			if (temp->appointment.doctorId == doctorId) {
				cout << "Patient Name: " << temp->name << endl;
				cout << "Date: " << temp->appointment.date << endl;
				cout << "Time: " << temp->appointment.time << endl;
				cout << "--------------------------" << endl;
				found = true;
			}
			temp = temp->next;
		}

		if (!found) {
			cout << "This doctor has no appointments." << endl;
		}
	}


};
class Patient {
public:
	int id;
	string name;
	string address;
	Appointment appointment;
	Patient* next;
	Patient() {
		id = 0;
		name = "unknown";
		address = "unknown";
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
	void addPatient(int id, string name, string address) {
		Patient* newPatient = new Patient;
		newPatient->id = id;
		newPatient->name = name;
		newPatient->address = address;
		if (isEmpty()) {
			head = newPatient;
		}
		else {
			newPatient->next = head;
			head = newPatient;
		}
	}
	void addPatientFromEnd(int id, string name, string address) {
		Patient* newPatient = new Patient;
		newPatient->id = id;
		newPatient->name = name;
		newPatient->address = address;
		Patient* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newPatient;
	}
	bool searchPatientById(int id) {
		Patient* temp = head;
		//if the patient was the first and only node in list
		if (temp->id == id) {
			return true;
		}
		while (temp->next != NULL) {
			if (temp->id == id) {
				return true;
			}
			temp = temp->next;
		}
		//check if patient in the last node
		if (temp->id == id) {
			return true;
		}
		return false;
	}
	bool searchPatientByName(string name) {
		Patient* temp = head;
		//if the patient was the first and only node in list
		if (temp->name == name) {
			cout << "Patient was found" << endl;
			cout << "they id is:" << temp->id << " " << "they address is:" << temp->address << " " << "they Appointment is:" << endl;
			return true;
		}

		while (temp->next != NULL) {
			if (temp->name == name) {
				cout << "Patient was found" << endl;
				cout << "they id is:" << temp->id << "they address is:" << temp->address << "they Appointment is:" <<  endl;
				return true;
			}
			temp = temp->next;
		}
		//check if patient in the last node
		if (temp->name == name) {
			return true;
		}
		cout << "Patient was not found" << endl;
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
	void bookAppointment() {}//مش عارف هنعلمها ازاي لسه 
	void updatePatientInformation() {
		cout << "enter Patient id for the Patient you want to update they information" << endl;
		int id;
		cin >> id;
		if (searchPatientById(id)) {
			cout << "enter number the represent the information you want to update" << endl;
			cout << "[1] to update id" << endl;
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
			switch (operationId) {
			case 1: {
				cout << "enter the new id" << endl;
				int newId;
				cin >> newId;
				temp->id = newId;
				break;
			}
			case 2: {
				cout << "enter the new name" << endl;
				string newName;
				cin >> newName;
				temp->name = newName;
				break;
			}
			case 3: {
				cout << "enter the new address" << endl;
				string newAddress;
				cin >> newAddress;
				temp->address = newAddress;
				break;
			}
			case 4: {
				cout << "enter the new Appointment" << endl;
				string newAppointment;
				cin >> newAppointment;
				//will fix it later
				break;
			}
			case 5: {
				int newId;
				string newName;
				string newAddress;
				string newAppointment;
				cout << "enter the new id" << endl;
				cin >> newId;
				cout << "enter the new name" << endl;
				cin >> newName;
				cout << "enter the new address" << endl;
				cin >> newAddress;
				cin >> newAppointment;
				temp->id = newId;
				temp->name = newName;
				temp->address = newAddress;
				break;
			}
			default: {
				cout << "enter valid number" << endl;
				break;
			}
			}

		}
		else {
			cout << "please enter patient id in the list of patient";
		}
	}
	void bookAppointment(DoctorLinkedList& doctors) {
		cout << "enter the id of the patient that want to book an appointment";
		int patientID;
		cin >> patientID;
		cout << "enter the name of the doctor you want to book an appointment with ";
		string doctorName;
		cin >> doctorName;
		int doctorID = doctors.searchDoctorByNameAndReturnID(doctorName);
		cout << "enter the date when you want to book an appointment";
		string appointmentDate;
		cin >> appointmentDate;
		cout << "enter the time when you want to book an appointment";
		string appointmentTime;
		cin >> appointmentTime;
		Patient* temp = head;
		//if the patient was the first and only node in list
		if (isEmpty()) {
			if (temp->id == patientID) {
				temp->appointment.doctorId = doctorID;
				temp->appointment.date = appointmentDate;
				temp->appointment.time = appointmentTime;
				return;
			}
			while (temp->next != NULL) {
				if (temp->id == patientID) {
					temp->appointment.doctorId = doctorID;
					temp->appointment.date = appointmentDate;
					temp->appointment.time = appointmentTime;
					return;
				}
				temp = temp->next;
			}
			//check if patient in the last node
			if (temp->id == patientID) {
				temp->appointment.doctorId = doctorID;
				temp->appointment.date = appointmentDate;
				temp->appointment.time = appointmentTime;
				return;
			}
			else {
				cout << "there is no patient in list of patient has this patient id";
			}
		}
		else {
			cout << "patient list is empty enter patients first";
		}
	}

		
	
};
struct Appointment {
	int doctorId;      
	string date;       
	string time;       
};

int main() {

}