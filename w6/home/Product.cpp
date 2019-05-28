/*
Name: Tian Zheng
Student number: 155394174
Email: tzheng26@myseneca.ca
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include"Product.h"

extern int FW;

namespace sict {
	Product::Product(int srcNum, double srcPrice) {
		if (srcNum > 0 && srcPrice > 0) {
			prod_num = srcNum;
			prod_price = srcPrice;
		}
		else {
			prod_num = 0;
			prod_price = 0;
		}
	}

	double Product::price() const {
		return prod_price;
	}

	void Product::display(std::ostream& os) const {
		if (prod_num > 0) {
			os.width(FW);
			os << prod_num;
			os.width(FW);
			os.setf(std::ios::fixed);
			os.precision(2);
			os << prod_price;
			os.unsetf(std::ios::fixed);
			os.precision(6);
		}
	}

	

	double TaxableProduct::taxRate = 0;

	TaxableProduct::TaxableProduct(size_t srcProdNum, double srcPrice, char srcType):Product(srcProdNum, srcPrice) {
		if (srcType == 'H') {
			myType = taxType::HST;
		}
		else if (srcType == 'P') {
			myType = taxType::PST;
		}
		else {
			myType = taxType::NON;
		}	
	}

	void TaxableProduct::setRate(taxType t) {
		switch (t) {
		case TaxableProduct::taxType::HST:
			taxRate = 0.13;
			break;
		case TaxableProduct::taxType::PST:
			taxRate = 0.08;
			break;
		default:
			taxRate = 0;
		}
	}

	double TaxableProduct::price() const {
		return Product::price() * (1 + TaxableProduct::taxRate);
	}

	void TaxableProduct::display(std::ostream& os) const {
		std::string taxLetter;
		Product::display(os);

		this->setRate(myType);

		os << " ";
		switch (myType) {
		case TaxableProduct::taxType::HST:
			taxLetter = "HST";
			break;
		case TaxableProduct::taxType::PST:
			taxLetter = "PST";
			break;
		default:
			taxLetter.clear();
		}
		os << taxLetter;
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& p) {
		p.display(os);
		return os;
	}

	iProduct* readRecord(std::ifstream& file) {
		iProduct* newProd = nullptr;
		int newNum;
		double newPrice;
		char newTaxType;
		file >> newNum >> newPrice;

		newTaxType = file.get();

		if (newTaxType != '\n') {
			file >> newTaxType;
			newProd = new TaxableProduct(newNum, newPrice, newTaxType);
		}
		else {
			newProd = new Product(newNum, newPrice);
		}	
		return newProd;
	}
}