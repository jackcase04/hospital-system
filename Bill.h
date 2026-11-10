#ifndef BILL_H
#define BILL_H
#include <string>
#include <vector>
using namespace std;
class Bill {
    public:
        float dollar_amount;
        string date;
        string due_date;
        vector<string> itemized_list;
};

#endif