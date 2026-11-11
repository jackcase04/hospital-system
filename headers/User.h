#ifndef USER_H
#define USER_H

#include <string>

class User {
	public:
		User(int id, std::string name, std::string address, std::string birthday);
		void display_info();
		virtual std::string role() const = 0;

		int id;
		std::string name;
		std::string address;
		std::string birthday; // MM-DD-YYYY format
};

#endif