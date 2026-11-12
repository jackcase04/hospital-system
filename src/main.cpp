#include "BillingStaff.h"
#include "ClinicalStaff.h"
#include "Physician.h"
#include "SchedulingStaff.h"

#include <iostream>
#include <memory>

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
vector<unique_ptr<User>> users;

int main() {
    init_fake_database();

    User* user = authenticate(); 

    if (user->role() == "Patient") {
        viewPatientDashboard(user);
    } else if (user->role() == "BillingStaff" || user->role() == "ClinicalStaff" || user->role() == "Physician" || user->role() == "SchedulingStaff") {
        viewStaffDashboard(user); 
    } else {
        showAuthError(); 
    }

    return 0; 

}

void init_fake_database() {
    // Add some fake users
    users.push_back(make_unique<Physician>(0, "Jack", "123 Random St", "09-10-2004"));
    users.push_back(make_unique<BillingStaff>(1, "Case", "123 Random St", "05-20-2004"));
    users.push_back(make_unique<ClinicalStaff>(2, "Connor", "456 Hello St", "12-23-2004"));
    users.push_back(make_unique<Patient>(3, "Person1", "101 Patient St", "01-01-2001"));
    users.push_back(make_unique<Patient>(4, "Person2", "102 Patient St", "03-03-2003"));
    users.push_back(make_unique<SchedulingStaff>(5, "Maris", "984 Hello St", "04-03-2003"));
}

User* authenticate() {
    int role;

    cout << "\n-----------------------------------------------------\n";
    cout << "------------------Authentication---------------------\n";

    for (auto &user : users) {
        user.get()->display_info();
    }
    
    cout << "Enter the ID of your user: ";

    while (!(cin >> role) || (role < 0 || role >= users.size())) {
        cout << "Invalid input. Try again: ";
        cin.clear();
        cin.ignore(10000, '\n'); 
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
    int selection; 
    bool exit = false; 

    do {

        cout << "\n\n-----------------------------------------------------\n";
        cout << "------------------Staff Dashboard--------------------\n\n";
        cout << "Logged in as: " << user->name << endl;

        cout << "\n\n You may select from the following options: " << endl; 
        cout << "(1) View Patients" << endl; 
        //cout << "(2) View Patient Appointments" << endl;  Not implemented yet for staff as a function. TODO in the future.
        cout << "(2) Exit Application" << endl; 
        cout << "\n Enter the appropriate number to select: "; 

        cin >> selection; 
        if (selection == 1) {
            viewPatientList(); 
        } else if (selection == 2) {
            exit = true;
        } else {
            while(selection != 1 && selection != 2) {
                cout << "You selected an invalid option. Please try again: ";
                if (selection == 1) {
                    viewPatientList(); 
                } else if (selection == 2) {
                    exit = true;
                }
            }
        }

    } while (!exit); 

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
    cout << "Authentication failed. Please try again later." << endl; 

}