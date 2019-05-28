/*	Name: Tian Zheng
	Student number: 155 394 174
	Email: tzheng26@myseneca.ca
*/

#include<iostream>
#include <string>
#include"Message.h"

namespace sict {
	Message::Message() {
		user.assign("NA");
		receiver.assign("NA");
		content.assign("NA");
	}

	Message::Message(const std::string& str) {
		bool valid = false;
		size_t firstSpace = str.find(" ");
		size_t findPreface = str.find(preface);
		size_t secSpace;
		// (str.find('\n') != std::string::npos) {
		if (firstSpace != std::string::npos && firstSpace != 0) {
			user = str.substr(0, firstSpace);
			if (findPreface != std::string::npos) {
				secSpace = str.find(" ", findPreface);
				receiver = str.substr(findPreface + 1, secSpace - findPreface-1);
			}
			else {
				secSpace = firstSpace;
				receiver.assign("NA");
			}
			content = str.substr(secSpace + 1);
			content.append("\n");
			valid = true;
		}

		//}

		if (!valid) { *this = Message(); }

	}

	

	bool Message::empty() const {
		return user.compare("NA") == 0;
	}

	void Message::display(std::ostream& os) const {
		if (!this->empty()) {
			os << ">User  : " << user << std::endl;
			
			if (receiver.compare("NA") != 0)
				os << " Reply : " << receiver << std::endl;
			
			os << " Tweet : " << content << std::endl;
		}
	}







}


