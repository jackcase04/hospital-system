#include "BillingStaff.h"
#include "ClinicalStaff.h"
#include "Physician.h"
#include "SchedulingStaff.h"

#include <iostream>
#include <memory>
#include <unordered_map>

using namespace std; 

void init_fake_database();
User* authenticate(); 
void viewPatientDashboard(User* user); 
void viewStaffDashboard(User* user);
void viewAppointments(); 
void viewAppointmentDetails(int selection);
void viewSpecialtyList();
void viewSpecialtyDetails(int selection); 
void viewProviderList(); 
void viewProviderDetails(); 
void viewPatientList();
void viewPatient(int selection); 
void checkInPatient(); 
void editPatientInfo(); 
void showAuthError(); 

// Our fake "database" with the users
unordered_map<int, unique_ptr<User>> users;

int main() {
    init_fake_database();

    User* user = authenticate(); 

    if (user->role() == "Patient") {
        viewPatientDashboard(user);
    } else {
        viewStaffDashboard(user); 
    }

    return 0; 

}

void init_fake_database() {
    // All our users
    auto physician = make_unique<Physician>(0, "Jack", "123 Random St", "09-10-2004");
    auto billing = make_unique<BillingStaff>(1, "Case", "123 Random St", "05-20-2004");
    auto clinical = make_unique<ClinicalStaff>(2, "Connor", "456 Hello St", "12-23-2004");
    auto patient1 = make_unique<Patient>(3, "Person1", "101 Patient St", "01-01-2001");
    auto patient2 = make_unique<Patient>(4, "Person2", "102 Patient St", "03-03-2003");
    auto scheduler = make_unique<SchedulingStaff>(5, "Maris", "984 Hello St", "04-03-2003");

    // Add relationships
    clinical->patients[3] = patient1.get();
    clinical->patients[4] = patient2.get();
    physician->patients[3] = patient1.get();
    physician->patients[4] = patient2.get();
   
    // Add them to db
    users[0] = std::move(physician);
    users[1] = std::move(billing);
    users[2] = std::move(clinical);
    users[3] = std::move(patient1);
    users[4] = std::move(patient2);
    users[5] = std::move(scheduler);
}

User* authenticate() {
    cout << "\n-----------------------------------------------------\n";
    cout << "------------------Authentication---------------------\n";

    for (auto &user : users) {
        user.second.get()->display_info();
        cout << "\n";
    }
    
    cout << "Enter the ID of your user: ";

    int role;

    while (true) {
        while (!(cin >> role)) {
            cout << "Invalid input. Try again: ";
            cin.clear();
            cin.ignore(10000, '\n'); 
        }

        auto it = users.find(role);
        if (it != users.end()) {
            break;
        } else {
            cout << "Invalid input. Try again: ";
            cin.clear();
            cin.ignore(10000, '\n'); 
        }
    }

    return users[role].get();
}

void viewPatientDashboard(User* user) {
    cout << "Patient\n";

    //Present options
    //Based on what user chooses, execute one of following functions. 
    viewAppointments(); 
	viewSpecialtyList();
    viewProviderList(); 

    //Give user option to exit application.

}

void viewStaffDashboard(User* user) {
    cout << "\n\n-----------------------------------------------------\n";
    cout << "------------------Staff Dashboard--------------------\n\n";
    cout << "Hello, " << user->name << endl;
    cout << "What would you like to do today?\n";

    string role = user->role();
    bool can_view = false;

    Physician* physician;
   
    // Just doing physician right now for simplicity. Spent too long trying to get others to work also
    if (role == "Physician") {
        physician = dynamic_cast<Physician*>(user);
        can_view = true;
        cout << "Type 1 to view your patients\n";
    }
    
    cout << "Type 0 to quit\n";

    int choice;

    while (!(cin >> choice) || (choice < 0 || choice > can_view ? 1 : 0)) {
        cout << "Invalid input. Try again: ";
        cin.clear();
        cin.ignore(10000, '\n'); 
    }

    if (choice == 1) {
        for (auto pat : physician->patients) {
            cout << "\n";
            pat.second->display_info();
        }

        cout << "Enter the id of the patient you wish to view the appointments of: ";

        while (true) {
            while (!(cin >> choice)) {
                cout << "Invalid input. Try again: ";
                cin.clear();
                cin.ignore(10000, '\n'); 
            }

            auto it = physician->patients.find(choice);
            if (it != physician->patients.end()) {
                break;
            } else {
                cout << "Invalid input. Try again: ";
                cin.clear();
                cin.ignore(10000, '\n'); 
            }
        }

        cout << "Finally a valid input\n";
    }

	//Present options
	//Based on what the user chooses, execute the following functions. 
	// viewPatients();
	// viewPatientAppointments();
	
	//Give user the option to exit application.

}

void viewAppointments() {

	//Just have a print out of some dummy appointments. 
	//Give the user the ability to enter a number to view a specific appointment or a control value to return control
	//to the calling function. 

}

void viewAppointmentDetails(int selection) {

	//Just print out dummy information for that specific appointment. 
	//Return control to the calling function by default.

}

void viewSpecialtyList() {

	//Just have a print out of some dummy specialties. 
	//Give the user the option to select a given specialty for detailed information.

}

void viewSpecialtyDetails(int selection) {

	//Just print out dummy information for that specific specialty. 
	//Return control to the calling function by default.

}

void viewProviderList() {

	//Just have a print out of some dummy providers
	//Give the user the option to select a given provider for detailed information.

}

void viewProviderDetails(int selection) {

	//Just print out dummy information for that specific specialty. 
	//Return control to the calling function default. 

}

void viewPatientList() {

	//Just print a dummy list of patients that can be selected from. 
	//Upon user exit return to calling function. 

}

void viewPatient(int selection) {

	//Just print information for a specific patient.
	//Give user the option to edit patient info.  
	
	
}

void checkInPatient() {

    //Simply set the patient's check-in status to in.
    //Return control to earlier function.

}

void editPatientInfo() {

    //Allow user to edit patient info one component at a time.
    //They can enter a special entry to avoid editing a 
    //specific component. 

    //Upon finishing edit, the new patient information is printed
    //and control is return to viewing patient list.

}

void showAuthError() {

    //Print an error message saying the user failed to authenticate.

}