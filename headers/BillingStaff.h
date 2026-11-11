#ifndef BILLING_STAFF_H
#define BILLING_STAFF_H

#include "Patient.h"
#include "Bill.h"
#include "User.h"

#include <string>

class Patient;

class BillingStaff : public User {
    public:
        void add_bill(Patient &patient, Bill bill);
        std::string view_insurance(Patient &patient);
};

#endif