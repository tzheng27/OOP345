/*	Name: Tian Zheng
	Student number: 155 394 174
	Email: tzheng26@myseneca.ca
*/


#ifndef MSGPK_SICT_H
#define MSGPK_SICT_H

#include "Message.h"

namespace sict {

	class MessagePack {
		Message* messages = nullptr;
		size_t msgsSize;
	public:
		MessagePack();
		MessagePack(Message** msgsPtr, size_t size);
		MessagePack(const MessagePack&);
		MessagePack& operator= (const MessagePack&);
		MessagePack(MessagePack&&);
		MessagePack& operator=(MessagePack&&);
		~MessagePack();
		void display(std::ostream& os) const;
		size_t size() const;
	};
	std::ostream& operator<<(std::ostream& os, const MessagePack& msgpk);
}



#endif // !MSGPK

