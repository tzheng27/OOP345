#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H
// Workshop 8 - Smart Pointers
// Utilities.h
// Chris Szalwinski from Cornel Barna
// 2019/03/17

/*
Name: Tian Zheng
Student Number: 155 394 174
Email: tzheng26@myseneca.ca
*/

#include "List.h"
#include "Element.h"

namespace sict {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
}

#endif