#ifndef SCHEDULING_STAFF_H
#define SCHEDULING_STAFF_H

#include "Appointment.h"
#include "Patient.h"
#include "User.h"
#include "Physician.h"

#include <string>
#include <vector>

class SchedulingStaff : public User {
    public:
        using User::User;
        using User::display_info;
        std::string role() const override { return "SchedulingStaff"; }

        std::vector<Appointment> appointments;

        void message_patient(Patient patient, std::string message);
        void message_physican(Physician physician, std::string message);
        void approve_appointment(Appointment appointment);
        void deny_appointment(Appointment appointment);
};

#endif