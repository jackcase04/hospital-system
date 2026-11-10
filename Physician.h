#ifndef PHYSICIAN_H
#define PHYSICIAN_H

#include "Patient.h"
#include "ClinicalStaff.h"
#include <string>
#include <vector>
using namespace std;

class Physician : public ClinicalStaff
{
private:
    /* data */
public:
    void schedule_appointment(Patient patient, string date, string time, ClinicalStaff staff);
    void reschedule_appointment(Patient patient, int id, string date);
    void cancel_appointment(Patient patient, int id);
};


#endif