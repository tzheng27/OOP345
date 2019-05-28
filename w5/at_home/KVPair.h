/*
Name: Tian Zheng
Student Number: 155 394 174
Email: tzheng26@myseneca.ca
*/

#include <iostream>

namespace sict {
	const int myfieldWidth =10;

	template<typename K, typename V>
	class KVPair {
		K mykey;
		V myvalue;
	public:
		KVPair() : mykey(), myvalue() {}

		KVPair(const K& srck, const V& srcv) {
			mykey = srck;
			myvalue = srcv;
		}
		
		template<typename F>
		void display(std::ostream& os, F f) const {
			KVPair temp;
			if (mykey != temp.mykey) {
				os << std::setw(myfieldWidth);
				os.setf(std::ios::left);
				os << mykey << ' ' << ':' << ' ';
				os.unsetf(std::ios::left);
				os << std::setw(myfieldWidth);
				os.setf(std::ios::right);
				os << myvalue;
				os << std::setw(myfieldWidth);
				os << f(myvalue) << std::endl;
				os.unsetf(std::ios::right);
			}
		}
	};
}