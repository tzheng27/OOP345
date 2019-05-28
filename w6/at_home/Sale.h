/*
Name: Tian Zheng
Student number: 155394174
Email: tzheng26@myseneca.ca
*/

#ifndef SALE_H
#define SALE_H

#include<vector>
#include"Product.h"

namespace sict {
	class Sale {
		std::vector<iProduct*> products;
	public:
		Sale(char* file);
		void display(std::ostream& os) const;
	};
}


#endif // !SALE_H

