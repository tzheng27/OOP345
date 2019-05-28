/*	Name: Tian Zheng
	Student number: 155 394 174
	Email: tzheng26@myseneca.ca
*/

#include<iostream>
#include <string>
#include"MessagePack.h"

namespace sict {
	MessagePack::MessagePack() {
		messages = nullptr;
		msgsSize = 0;
	}

	MessagePack::MessagePack(Message** msgsPtr, size_t size) {
		if (msgsPtr != nullptr && size > 0) {
			size_t empty;
			messages = new Message[size];
			for (size_t i = 0, j = 0;j < size;i++, j++) {
				if (msgsPtr[j]->empty())
					j++;
				messages[i] = *msgsPtr[j];
				empty = j - i;
			}
			msgsSize = size - empty;
		}
		else {
			*this = MessagePack();
		}
	}



	MessagePack::MessagePack(const MessagePack& src) {
		*this = src;
	}




	MessagePack& MessagePack::operator= (const MessagePack& src) {
		if (this != &src) {
			delete[] messages;
			messages = new Message[src.msgsSize];
			for (size_t i = 0; i < src.msgsSize;i++) {
				messages[i] = src.messages[i];
			}
			msgsSize = src.msgsSize;
		}
		return *this;
	}

	MessagePack::MessagePack(MessagePack&& src) {
		*this = std::move(src);
	}

	MessagePack& MessagePack::operator=(MessagePack&& src) {
		if (this != &src) {
			delete[] messages;
			messages = src.messages;
			msgsSize = src.msgsSize;
			src.messages = nullptr;
			src.msgsSize = 0;
		}
		return *this;
	}

	MessagePack::~MessagePack() {
		delete[] messages;
		messages = nullptr;
	}

	void MessagePack::display(std::ostream& os) const {
		for (size_t i = 0; i < this->msgsSize;i++) {
			this->messages[i].display(os);
		}
	}


	size_t MessagePack::size() const {
		return this->msgsSize;
	}

	std::ostream& operator<<(std::ostream& os, const MessagePack& msgpk) {
		msgpk.display(os);
		return os;
	}


}//namespace sict

