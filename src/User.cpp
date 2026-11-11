#include "User.h"

#include <iostream>

using namespace std;

User::User(int id, std::string name, std::string address, std::string birthday) {
    this->id = id;
    this->name = name;
    this->address = address;
    this->birthday = birthday;
}

void User::display_info() {
    cout << "Id: " << id << endl;
    cout << "Name: " << name << endl;
}