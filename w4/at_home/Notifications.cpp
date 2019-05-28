/*	Name: Tian Zheng
	Student number: 155 394 174
	Email: tzheng26@myseneca.ca
*/

#include<iostream>
#include "Message.h"
#include"Notifications.h"

namespace sict {
	Notifications::Notifications() {
		msgsptr = nullptr;
		maxAdd = 0;
		accurateAdd = 0;
	}

	Notifications::Notifications(const int srcMax) {
		if (srcMax > 0) {
			maxAdd = srcMax;
			msgsptr = new const Message*[srcMax];
			for (int i = 0;i < srcMax;i++)
				msgsptr[i] = nullptr;
			accurateAdd = 0;
		}
		else { *this = Notifications(); }
	}

	Notifications::Notifications(const Notifications& src) {
		*this = src;
	}

	Notifications& Notifications::operator=(const Notifications& src) {
		if (this != &src) {
			delete[]msgsptr;
			msgsptr = new const Message*[src.maxAdd];
			
			for (int i = 0;i < src.accurateAdd;i++)
				msgsptr[i] = src.msgsptr[i];

			maxAdd = src.maxAdd;
			accurateAdd = src.accurateAdd;
		}
		return *this;
	}

	Notifications::Notifications(Notifications&& src) {
		*this = std::move(src);
	}

	Notifications& Notifications::operator=(Notifications&& src) {
		if (this != &src) {
			delete[] msgsptr;
			msgsptr = src.msgsptr;			
			maxAdd = src.maxAdd;
			accurateAdd = src.accurateAdd;

			src.msgsptr = nullptr;
			src.maxAdd = 0;
			src.accurateAdd = 0;
		}
		return *this;
	}

	Notifications::~Notifications() {
		delete[] msgsptr;
		msgsptr = nullptr;
	}
	Notifications& Notifications::operator+=(const Message& msg) {
		if (!msg.empty() && (accurateAdd < maxAdd)) {
			msgsptr[accurateAdd] = &msg;
			accurateAdd++;
		}
		return *this;
	}

	Notifications& Notifications::operator-=(const Message& msg) {
		int target, flag=1;
		if (!msg.empty()) {
			for (int i = 0;i < accurateAdd && flag == 1;i++) {
				if (msgsptr[i] == &msg) {
					target = i;
					flag = 0;
				}
			}
			if (flag == 0) {
				for (int i = target;i < accurateAdd - 1; i++) {
					msgsptr[i] = msgsptr[i + 1];
				}
				
				msgsptr[accurateAdd - 1] = nullptr;
				accurateAdd--;
			}
		}
		return *this;
	}

	void Notifications::display(std::ostream& os) const {
		for (int i = 0;i < accurateAdd;i++) {
			if (msgsptr[i] != nullptr) {
				msgsptr[i]->display(os);
			}
		}
	}

	size_t Notifications::size() const {
		return accurateAdd;
	}

	std::ostream& operator<<(std::ostream& os, const Notifications& srcNotification) {
		srcNotification.display(os);
		return os;
	}

}