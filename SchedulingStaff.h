#ifndef SCHEDULING_STAFF_H
#define SCHEDULING_STAFF_H

#include <string>
#include <vector>
#include "Appointment.h"
#include "Patient.h"
#include "User.h"
#include "Physician.h"
using namespace std;

class SchedulingStaff : public User
{
public:
    vector<Appointment> appointments;

    void message_patient(Patient patient, string message);
    void message_physican(Physician physician, string message);
    void approve_appointment(Appointment appointment);
    void deny_appointment(Appointment appointment);
};
#endif