// Workshop 8 - Smart Pointers
// Utilities.cpp
// Chris Szalwinski from Cornel Barna
// 2019/03/17

/*
Name: Tian Zheng
Student Number: 155 394 174
Email: tzheng26@myseneca.ca
*/

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sict {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t i = 0; i < desc.size();i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					Product* p = new Product(desc[i].desc, price[j].price);
					try {
						p->validate();
						priceList += p;
						delete p;
						p = nullptr;
					}
					catch (const std::string& msg) {
						throw msg;
					}
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0; i < desc.size();i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					std::unique_ptr<Product> p(new Product(desc[i].desc, price[j].price));
					try {
						p->validate();
						priceList += std::move(p);
					}
					catch (const std::string& msg) {
						throw msg;
					}
				}
			}
		}
		return priceList;
	}
}