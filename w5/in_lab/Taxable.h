/*
Name: Tian Zheng
Student Number: 155 394 174
Email: tzheng26@myseneca.ca
*/

#include<iostream>

namespace sict {

	class Taxable {
		float mytaxRate;
	public:
		Taxable(float srctaxRate) {
			mytaxRate = srctaxRate;
		}

		float operator()(float price) {
			return price * (1 + mytaxRate);
		}
		
	};
}