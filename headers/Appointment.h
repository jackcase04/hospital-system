#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "Patient.h"
#include "ClinicalStaff.h"

#include <string>

class Patient;

class Appointment {
    public:
        int id;
        std::string date;
        std::string time;
        ClinicalStaff staff;
        Patient *patient;
        std::string description;
};

#endif