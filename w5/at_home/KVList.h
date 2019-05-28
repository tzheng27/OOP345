/*
Name: Tian Zheng
Student Number: 155 394 174
Email: tzheng26@myseneca.ca
*/

#include<iostream>

namespace sict {
	template<typename T>
	class KVList {
		T* tList;
		int size;
	public:
		KVList() {
			tList = nullptr;
			size = 0;
		}

		KVList(int n) {
			if (n > 0) {
				tList = new T[n];
				size = n;
			}
			else {
				throw n;
			}
		}

		KVList(KVList&& src) {
			if (src.tList != nullptr) {
				tList = src.tList;
				size = src.size;
				src.tList = nullptr;
				src.size = 0;
			}
			else {
				tList = nullptr;
				size = 0;
			}
		}

		~KVList() {
			delete [] tList;
			tList = nullptr;
		}

		const T& operator[](size_t i) const { 
			if (i < 0 || i >= size) {
				throw "Outside bounds";
			}
			return tList[i];
		}

		template<typename F>void display(std::ostream& os, F f) const {
			if (size != 0) {
				for (int i = 0;i < size;i++) {
					tList[i].display(os, f);
				}
			}
		}

		void push_back(const T& t) {
			static int n = 0;
			if (n < size) {
				tList[n] = t;
				n++;
			}
		}

		KVList(const KVList& src) = delete;
		KVList& operator=(const KVList& src) = delete;
		KVList& operator=(KVList&& src) = delete;
	};

}