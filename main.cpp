#include <iostream>
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

void viewPatientDashboard() {

    //Present options
    //Based on what user chooses, execute one of following functions. 
    viewAppointments(); 
    viewSpecialtyList()
    viewProviderList(); 

    //Give user option to exit application.

}

void viewStaffDashboard() {

	//Present options
	//Based on what the user chooses, execute the following functions. 
	viewPatients()
	viewPatientAppointments()
	
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