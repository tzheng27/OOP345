/*
Name: Tian Zheng
Student Number: 155 394 174
Email: tzheng26@myseneca.ca
*/

#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

#include<fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include<iomanip>

extern int FW;
extern int ND;
namespace sict {
	template<typename T>
	class DataTable {
		std::vector<T> xs;
		std::vector<T> ys;
	public:
		DataTable(std::ifstream& fs) {
			T x, y;
			if (fs.is_open()) {
				while (!fs.eof()) {
					fs >> x;
					xs.push_back(x);
					fs >> y;
					ys.push_back(y);
				}
			}
		}

		T mean() const {
			T sum = std::accumulate(ys.begin(), ys.end(), (T)0);
			return sum / ys.size();
		}

		T sigma() const {
			T m = mean();
			T sum = 0;
			for (size_t i = 0; i < ys.size();i++)
				sum = sum + (ys.at(i) - m)*(ys.at(i) - m);
			return sqrt(static_cast<double>(sum / (ys.size() - 1)));
		}

		void displayData(std::ostream& os) const {
			os << "Data Values" << std::endl;
			os << "------------" << std::endl;
			os << std::setw(FW) << std::setprecision(ND) << std::fixed << 'x';
			os << std::setw(FW) << 'y' << std::endl;
			for (size_t i = 0; i < xs.size(); i++)
				os << std::setw(FW) << xs[i] << std::setw(FW) << ys[i] << std::endl;
		}

		void displayStatistics(std::ostream& os) const {
			os << std::endl;
			os << "Statistics" << std::endl;
			os << "----------" << std::endl;
			os << "  y mean" << "    = " << std::setw(FW) << this->mean() << std::endl;
			os << "  y sigma" << "   = " << std::setw(FW) << this->sigma() << std::endl;
		}
	};
}
#endif // !DTABLE_H

