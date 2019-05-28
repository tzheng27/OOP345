/*	Name: Tian Zheng
	Student number: 155 394 174
	Email: tzheng26@myseneca.ca		*/

#ifndef LIST_SICT_H
#define LIST_SICT_H

#include <iostream>

namespace sict {
	template<class T, int N>
	class List {
		T data[N];
		size_t elemNum{ 0u };
	public:
		size_t size() const { return elemNum; }
		const T& operator[](size_t i) const {
			const T& ref = data[i];
			return ref;
		}
		void operator+=(const T& t) {
			if (elemNum < N) {
				data[elemNum] = t;
				elemNum++;
			}
		}
	};
}

#endif // !LIST_SICT_H
