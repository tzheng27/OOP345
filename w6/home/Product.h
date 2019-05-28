/*
Name: Tian Zheng
Student number: 155394174
Email: tzheng26@myseneca.ca
*/

#ifndef PROD_H
#define PROD_H

#include <iostream>
#include "iProduct.h"



namespace sict {
	class Product : public iProduct {
		int prod_num;
		double prod_price;
	public:
		Product(int, double);
		double price() const;
		void display(std::ostream& os) const;
	};

	class TaxableProduct : public Product {
	public:
		enum class taxType { HST, PST, NON };
		TaxableProduct(size_t srcProdNum, double srcPrice, char srcType);
		double price() const;
		void display(std::ostream& os) const;
		static void setRate(taxType t);
	private:
		taxType myType;
		static double taxRate;
	};

	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);
}


#endif // !PROD_H

