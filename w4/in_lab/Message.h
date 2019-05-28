/*	Name: Tian Zheng
	Student number: 155 394 174
	Email: tzheng26@myseneca.ca
*/



#ifndef MSG_SICT_H
#define MSG_SICT_H

#include<iostream>

namespace sict {
	const std::string preface("@");

	class Message {
		std::string user;
		std::string receiver;
		std::string message;
	public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
	};
}


#endif // !MSG_SICT_H