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
#include<functional>

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
			while (fs >> x >> y) {
				xs.push_back(x);
				ys.push_back(y);
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

		T median() const {
			std::vector<T> v = ys;
			std::sort(v.begin(), v.end());
			T t = ys.size();
			return v[t / 2];
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
			T s, i;
			std::vector<T> tempx = xs;
			std::vector<T> tempy = ys;
			auto f = [=](T& slope, T& ysIntercept) {
				T totalXY = std::inner_product(tempx.begin(), tempx.end(), tempy.begin(), (T)0);
				T totalX = std::accumulate(tempx.begin(), tempx.end(), (T)0);
				T totalY = std::accumulate(tempy.begin(), tempy.end(), (T)0);
				T totalXX = std::inner_product(tempx.begin(), tempx.end(), tempx.begin(), (T)0);
				T no = tempy.size();
				slope = (no * totalXY - totalX * totalY) / (no * totalXX - totalX * totalX);
				ysIntercept = (totalY - slope * totalX) / no;
			};
			f(s, i);
			os << std::endl;
			os << "Statistics" << std::endl;
			os << "----------" << std::endl;
			os << "  y mean" << "    = " << std::setw(FW) << this->mean() << std::endl;
			os << "  y sigma" << "   = " << std::setw(FW) << this->sigma() << std::endl;
			os << "  y median" << "  = " << std::setw(FW) << this->median() << std::endl;
			os << "  slope" << "     = " << std::setw(FW) << s << std::endl;
			os << "  intercept" << " = " << std::setw(FW) << i << std::endl;
		}
	};
}
#endif // !DTABLE_H

