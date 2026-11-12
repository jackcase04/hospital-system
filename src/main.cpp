#include "BillingStaff.h"
#include "ClinicalStaff.h"
#include "Physician.h"
#include "SchedulingStaff.h"

#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std; 

void init_fake_database();
User* authenticate(); 
void viewPatientDashboard(User* user); 
void viewStaffDashboard(User* user);
void viewAppointments(User* user); 
void viewAppointmentDetails(int selection, User* user);
void viewSpecialtyList(User* user);
void viewSpecialtyDetails(int selection, User* user); 
void viewProviderList(User* user); 
void viewProviderDetails(int selection, User* user); 
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
    cout << "\n\n-----------------------------------------------------\n";
    cout << "------------------Patient Dashboard--------------------\n\n";
    cout << "Logged in as: " << user->name << endl;
    cout << "\n" << endl;

    int patientOption;

    //Present options
    //Based on what user chooses, execute one of following functions. 
    //Give user option to exit application

    cout << "1. View Appointments\n";
    cout << "2. View Specialty List\n";
    cout << "3. View Provider List\n";
    cout << "4. Exit Applicaiton\n";
    cout << "Selection: ";
    cin >> patientOption;

    switch(patientOption){
        case 1:
            viewAppointments(user);
            break;
        case 2:
            viewSpecialtyList(user);
            break;
        case 3:
            viewProviderList(user);
            break;
        case 4:
            return;
    }
    
    if (patientOption > 4){
        cout <<"Invalid option";
    }

}

void viewStaffDashboard(User* user) {
    int selection;
    bool done = false;

    do {
        cout << "\n\n-----------------------------------------------------\n";
        cout << "------------------Staff Dashboard--------------------\n\n";
        cout << "Logged in as: " << user->name << endl;

        cout << "\n\nYou may select from the following options:" << endl;
        cout << "(1) View Patients" << endl;
        // cout << "(2) View Patient Appointments" << endl;  TODO
        cout << "(2) Exit Application" << endl;
        cout << "\nEnter the appropriate number to select: ";

        // Keep asking until we get a valid number (1 or 2)
        while (!(cin >> selection) || (selection != 1 && selection != 2)) {
            cout << "You selected an invalid option. Please try again: ";
            cin.clear();              // clear the error state if they typed letters
            cin.ignore(10000, '\n');  // throw away the bad input
        }

        if (selection == 1) {
            viewPatientList();
        } else {
            done = true;
        }

    } while (!done);
}

	//Present options
	//Based on what the user chooses, execute the following functions. 
	// viewPatients();
	// viewPatientAppointments();
	
	//Give user the option to exit application.


void viewAppointments(User* user) {

    Patient* patient = dynamic_cast<Patient*>(user);

	//Just have a print out of some dummy appointments. 
	//Give the user the ability to enter a number to view a specific appointment or a control value to return control
	//to the calling function. 

    if (patient == nullptr) {
        cout << "Unable to access patient appointments.\n";
        return;
    }

    int selection;

    cout << "------------------Available Appointments--------------------\n\n";
    cout <<"1. November 16, 2:00 PM\n";
    cout <<"2. November 17, 2:30 PM\n";
    cout <<"3. Return to dashboard\n";

    cout <<"\nSelect an appointment:";
    cin >> selection;

    if(selection >= 1 && selection <= 3){
        viewAppointmentDetails(selection, user);
    }
    else if(selection == 3){
        viewPatientDashboard(user);
    }
    else{
        cout <<"Invalid option\n";
    }

}

void viewAppointmentDetails(int selection, User* user) {

    Patient* patient = dynamic_cast<Patient*>(user);

    string apptChoice;

	//Just print out dummy information for that specific appointment. 
	//Return control to the calling function by default.

    switch(selection){
        case 1:
            cout << "Dr. A : Primary Care\n";
            break;
        case 2:
            cout << "Dr. C : Cardiologist\n";
            break;
    }

    cout << "\nWould you like to Confirm, Reschedule, or Cancel your appointment?\n";
    cin >> apptChoice;

    if(apptChoice == "Confirm"){
        cout << "Your appointment has been confirmed!";
    }
    else if(apptChoice == "Reschedule"){
        string newDate;

        cout << "Enter new appointment date: ";
        cin >> newDate;

        patient->reschedule_appointment(selection, newDate);
    }
    else if(apptChoice == "Cancel"){
        cout << "Your appointment has been canceled\n";
        patient->cancel_appointment(selection);
        cout << "Redirecting you to the dashboard\n";
        viewPatientDashboard(user);
    }
    else{
        cout << "Invalid option\n";
    }

}

void viewSpecialtyList(User* user) {

    int selection;
	//Just have a print out of some dummy specialties. 
	//Give the user the option to select a given specialty for detailed information.

    cout << "\n\n------------------Specialty List--------------------\n\n";
    cout << "1. Primary Care\n";
    cout << "2. Dermatologist\n";
    cout << "3. Cardiologist\n";
    cout << "4. Return to Dashboard\n";

    cout << "Select a number: ";
    cin >> selection;

    if (selection >= 1 && selection <=3){
        viewSpecialtyDetails(selection, user);
    }
    else if (selection == 4){
        viewPatientDashboard(user);
    }
    else{
        cout << "Invalid option";
    }

}

void viewSpecialtyDetails(int selection, User* user) {

	//Just print out dummy information for that specific specialty. 
	//Return control to the calling function by default.
    cout <<"------------------Specialty Details--------------------\n\n";

    switch(selection){
        case 1:
            cout << "Primary Care:\n\n";
            cout <<  "Provides general care for everyday health needs.";
            return viewSpecialtyList(user);
        case 2:
            cout << "Dermatologist:\n\n";
            cout << "Provides care related to skin conditions";
            return viewSpecialtyList(user);
        case 3:
            cout << "Cardiologist:\n\n";
            cout << "Provides care related to heard and blood conditions";
            return viewSpecialtyList(user);
    }

}

void viewProviderList(User* user) {

	//Just have a print out of some dummy providers
	//Give the user the option to select a given provider for detailed information.

    int selection;

    cout << "\n\n------------------Provider List--------------------\n\n";
    cout << "1. Dr. A - Primary Care\n";
    cout << "2. Dr. B - Dermatologist\n";
    cout << "3. Dr. C - Cardiologist\n";
    cout << "4. Return to dashboard\n";

    cout << "Select a provider: ";
    cin >> selection;

    if(selection >= 1 && selection <= 3){
        viewProviderDetails(selection, user);
    }
    else if(selection == 4){
        return;
    }
    else{
        cout << "Invalid option\n";
    }
}

void viewProviderDetails(int selection, User* user) {

	//Just print out dummy information for that specific specialty. 
	//Return control to the calling function default. 

    cout << "------------------Provider Details--------------------\n\n";
    switch(selection){
        case 1:
            cout << "Dr. A:";
            cout << "Services: General examinations and consultations";
            return viewProviderList(user);
        case 2:
            cout << "Dr. B:";
            cout << "Services: Skin examinations and consultations";
            return viewProviderList(user);
        case 3:
            cout << "Dr. C:";
            cout << "Services: Heart and blood screenings and consultations";
            viewProviderList(user);
    }

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

//Added for patient appointment settings (in functions but not really being used atm)
void Patient::reschedule_appointment(int id, string date){
    for(Appointment& appt : appointments){
        if (appt.id == id){
            appt.date = date;
            return;
        }
    }
}

void Patient::cancel_appointment(int id){
    for(auto it = appointments.begin(); it != appointments.end(); ++it){
        if (it->id == id){
            appointments.erase(it);
            return;
        }
    }
}