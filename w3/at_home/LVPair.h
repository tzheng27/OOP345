/*	Name: Tian Zheng
	Student number: 155 394 174
	Email: tzheng26@myseneca.ca		*/

#ifndef LVPair_SICT_H
#define LVPair_SICT_H

#include <iostream>

namespace sict {
	template<typename L, typename V>
	class LVPair {
		L mylabel;
		V myvalue;
	public:
		LVPair() : mylabel(), myvalue() {}
		LVPair(const L& label, const V& value) {
			mylabel = label;
			myvalue = value;
		}
		virtual void display(std::ostream& os) const {
			os << mylabel << " : " << myvalue << std::endl;
		}

		L getLabel() const { return mylabel; }
		V getValue() const { return myvalue; }
	};

	template<typename L, typename V>
	std::ostream& operator<< (std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}


	template<typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {
		static V init;
		static size_t fieldWidth;
	public:
		SummableLVPair() {}

		SummableLVPair(const L& label, const V& v) : LVPair<L, V>(label, v) {
			if (fieldWidth < label.size())
				fieldWidth = label.size();
		}
		static const V& getInitialValue() { return init; }


		V sum(const L& label, const V& sum) const {
			V result = LVPair<L, V>::getValue() + sum;
			return result;
		}

		virtual void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(fieldWidth);
			os << LVPair<L, V>::getLabel() << " : " << LVPair<L, V>::getValue() << std::endl;
			os.unsetf(std::ios::left);
		}

		
	};

	

	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& value) const {
		std::string result = value + " " + LVPair<std::string, std::string>::getValue();
		return result;
	}

}
#endif // !LIST_SICT_H
