#include <iostream>
#include "Headers.h"

using namespace std; 

int authenticate(); 
void viewPatientDashboard(); 
void viewStaffDashboard();
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

int main() {

    int role = -1; 
    role = authenticate(); 

    if(role == 1) {
        viewPatientDashboard();
    } else if (role == 2) {
        viewStaffDashboard(); 
    } else {
        showAuthError(); 
    }

    return 0; 

}

int authenticate() {
    return 1;
}

void viewPatientDashboard() {

    int patientOption;

    //Present options
    //Based on what user chooses, execute one of following functions. 
    //Give user option to exit application
    cout << "Select an option" << "\n";
    cout << "1. View Appointments: " << "\n";
    cout << "2. View Specialty List: " << "\n";
    cout << "3. View Provider List: " << "\n";
    cout << "4. Exit Applicaiton" << "\n";
    cin >> patientOption;

    switch(patientOption){
        case 1:
            viewAppointments();
            //break;
        case 2:
            viewSpecialtyList();
            //break;
        case 3:
            viewProviderList();
           // break;
        case 4:
            return;
    }
    
    if (patientOption > 4){
        cout <<"Invalid option";
    }

}

void viewStaffDashboard() {

	//Present options
	//Based on what the user chooses, execute the following functions. 
	// viewPatients();
	// viewPatientAppointments();
	
	//Give user the option to exit application.

}

void viewAppointments() {

    int selection;
	//Just have a print out of some dummy appointments. 
	//Give the user the ability to enter a number to view a specific appointment or a control value to return control
	//to the calling function. 
    cout << "Available Appointments" << "\n";
    cout << "1. Friday, November 13th" << "\n";
    cout << "2. Monday, November 16th" << "\n";
    cout << "3. Tuesday, November 17th" << "\n";
    cout << "4. Return to dashboard";

    cout << "Select an appointment: ";
    cin >> selection;
    
    if (selection < 4){
        viewAppointmentDetails(selection);
    }
    else if (selection == 4){
        viewPatientDashboard();
    }
    else{
        cout << "Invalid option";
    }



}

void viewAppointmentDetails(int selection) {

	//Just print out dummy information for that specific appointment. 
	//Return control to the calling function by default.
    switch(selection){
        case 1:
            cout << "asdgkf";
        case 2:
            cout << "dskjghf";
        case 3:
            cout << "dsgfh";
    }

}

void viewSpecialtyList() {

    int selection;
	//Just have a print out of some dummy specialties. 
	//Give the user the option to select a given specialty for detailed information.

    cout << "Specialty List\n";
    cout << "1. Primary Care\n";
    cout << "2. Dermatologist\n";
    cout << "3. Cardiologist\n";
    cout << "4. Endocrinologist\n";
    cout << "Select a number: ";
    cin >> selection;

    if (selection > 4){
        viewSpecialtyDetails(selection);
    }
    else if (selection == 4){
        viewPatientDashboard();
    }
    else{
        cout << "Invalid option";
    }

}

void viewSpecialtyDetails(int selection) {

	//Just print out dummy information for that specific specialty. 
	//Return control to the calling function by default.


}

void viewProviderList() {

    int selection;
	//Just have a print out of some dummy providers
	//Give the user the option to select a given provider for detailed information.
    cout << "Provider List"<< "\n";
    cout << "1. Friday, November 13th" << "\n";
    cout << "2. Monday, November 16th" << "\n";
    cout << "3. Tuesday, November 17th" << "\n";
    cout << "4. Return to dashboard";

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

int authenticate(){ ////temp
    return 1;
}