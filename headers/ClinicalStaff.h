#ifndef CLINICAL_STAFF_H
#define CLINICAL_STAFF_H

#include "User.h"
#include "Patient.h"
#include "Appointment.h"

#include <string>
#include <vector>

class Patient;
class Appointment;

class ClinicalStaff : public User {
    public:
        using User::User;
        using User::display_info;

        std::string role() const override { return "ClinicalStaff"; }

        std::vector<std::string> personal_profile;
        std::vector<Patient> patients;

        std::vector<Appointment> view_patient_appointments(Patient &patient);
        std::vector<std::string> view_patient_history(Patient &patient);
        void manage_personal_profile();
        void message_patient(Patient &patient, std::string message);

};

#endif