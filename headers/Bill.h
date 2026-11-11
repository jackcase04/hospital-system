#ifndef BILL_H
#define BILL_H

#include <string>
#include <vector>

class Bill {
    public:
        float dollar_amount;
        std::string date;
        std::string due_date;
        std::vector<std::string> itemized_list;
};

#endif