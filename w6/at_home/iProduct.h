/*
Name: Tian Zheng
Student number: 155394174
Email: tzheng26@myseneca.ca
*/

#ifndef IPROD_H
#define IPROD_H

#include <iostream>

namespace sict {
	class iProduct {
	public:
		virtual double price() const = 0;
		virtual void display(std::ostream& os) const = 0;
	};

	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);
}

#endif // !IPROD_H
