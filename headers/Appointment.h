#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include <vector>
#include "Patient.h"
#include "ClinicalStaff.h"
using namespace std;

class Appointment {
    public:
    int id;
    string date;
    string time;
    ClinicalStaff staff;
    Patient patient;
    string description;
};

#endif