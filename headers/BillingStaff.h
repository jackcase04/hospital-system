#ifndef BILLING_STAFF_H
#define BILLING_STAFF_H

#include <string>
#include <vector>
#include "Patient.h"
#include "Bill.h"
#include "User.h"
using namespace std;

class BillingStaff : public User
{
public:
    void add_bill(Patient patient, Bill bill);
    string view_insurance(Patient patient);
};

#endif