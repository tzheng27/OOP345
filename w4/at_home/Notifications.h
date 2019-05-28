/*	Name: Tian Zheng
	Student number: 155 394 174
	Email: tzheng26@myseneca.ca
*/


#ifndef NOTE_SICT_H
#define NOTE_SICT_H

#include"Message.h"

namespace sict {
	class Notifications {
		const Message** msgsptr = nullptr;
		int maxAdd;
		int accurateAdd;
	public:
		Notifications();
		Notifications(const int srcMax);
		Notifications(const Notifications& src);
		Notifications& operator=(const Notifications& src);
		Notifications(Notifications&& src);
		Notifications& operator=(Notifications&& src);
		~Notifications();
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		size_t size() const;
	};

	std::ostream& operator<<(std::ostream& os, const Notifications& srcNotification);
}

#endif // !NOTE_SICT_H

