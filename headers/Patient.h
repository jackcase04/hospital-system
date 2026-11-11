#ifndef PATIENT_H
#define PATIENT_H

#include "User.h"
#include "Bill.h"
#include "Appointment.h"
#include "ClinicalStaff.h"

#include <string>
#include <vector>

class Patient : public User {
    public:
        using User::User;
        using User::display_info;

        std::string role() const override { return "Patient"; }

        std::vector<std::string> messages;
        std::string patient_profile;
        std::vector<Appointment> appointments;

        std::vector<std::string> view_medical_history();
        void schedule_appointment(std::string date, std::string time, ClinicalStaff clinStaff);
        void reschedule_appointment(int id, std::string date);
        void cancel_appointment(int id);
        std::vector<std::string> view_messages();
        
    private:
        std::vector<std::string> medical_history;
        Bill bill;
        std::string insurance;
};

#endif