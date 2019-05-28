/*	Name: Tian Zheng
	Student number: 155 394 174
	Email: tzheng26@myseneca.ca		*/

#ifndef LVPair_SICT_H
#define LVPair_SICT_H

#include <iostream>

namespace sict {
	template<typename L, typename V>
	class LVPair {
		L label;
		V value;
	public:
		LVPair() : label(), value() {}
		LVPair(const L& srclabel, const V& srcvalue) {
			label = srclabel;
			value = srcvalue;
		}
		void display(std::ostream& os) const {
			os << label << " : " << value << std::endl;
		}
	};

	template<typename L, typename V>
	std::ostream& operator<< (std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}
}

#endif // !LIST_SICT_H
