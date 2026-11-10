#ifndef CLINICAL_STAFF_H
#define CLINICAL_STAFF_H

#include <string>
#include "User.h"
#include <vector>
#include "Patient.h"
#include "Appointment.h"
using namespace std;

class ClinicalStaff : public User {
    public:
        vector<string> personal_profile;
        vector<Patient> patients;

        vector<Appointment> view_patient_appointments(Patient patient);
        vector<string> view_patient_history(Patient patient);
        void manage_personal_profile();
        void message_patient(Patient patient, string message);

};
#endif