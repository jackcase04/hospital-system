#ifndef PHYSICIAN_H
#define PHYSICIAN_H

#include "Patient.h"
#include "ClinicalStaff.h"
#include <string>

class Physician : public ClinicalStaff {
    private:
        /* data */
    public:
        void schedule_appointment(Patient patient, std::string date, std::string time, ClinicalStaff staff);
        void reschedule_appointment(Patient patient, int id, std::string date);
        void cancel_appointment(Patient patient, int id);
};

#endif