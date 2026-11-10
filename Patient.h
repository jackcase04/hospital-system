#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include <vector>
#include "User.h"
#include "Bill.h"
#include "Appointment.h"
#include "ClinicalStaff.h"
using namespace std;

class Patient : public User {
public:
    vector<string> messages;
    string patient_profile;
    vector<Appointment> appointments;

    vector<string> view_medical_history();
    void schedule_appointment(string date, string time, ClinicalStaff clinStaff);
    void reschedule_appointment(int id, string date);
    void cancel_appointment(int id);
    vector<string> view_messages();


    
private:
    vector<string> medical_history;
    Bill bill;
    string insurance;
};

#endif