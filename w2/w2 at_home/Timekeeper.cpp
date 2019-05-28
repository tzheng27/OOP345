/* Name: Tian Zheng
   Student Number: 155394174
   Email: tzheng26@myseneca.ca */

#include<iostream>
#include<chrono>
#include<cstring>
#include"Timekeeper.h"

namespace sict {

	Timekeeper::Timekeeper() {
		num_of_records = 0;
		starttime = std::chrono::steady_clock::now();
		endtime = std::chrono::steady_clock::now();
		for (int i = 0; i < MAX; i++) {
			record[i].message = "NA";
			record[i].units = "NA";
			record[i].duration = endtime - starttime;
		}
	}

	void Timekeeper::start() {
		starttime = std::chrono::steady_clock::now();
	}

	void Timekeeper::stop() {
		endtime = std::chrono::steady_clock::now();
	}

	void Timekeeper::recordEvent(const char* description) {
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(endtime - starttime);
		if (num_of_records < MAX) {
			record[num_of_records].message = description;
			record[num_of_records].units = UNITS;
			record[num_of_records].duration = ms;
			num_of_records++;
		}
	}

	void Timekeeper::report(std::ostream& os) const {
		os << "\nExecution Times:" << std::endl;
		for (int i = 0; i < num_of_records; i++) {
			os.setf(std::ios::left);
			os.width(20);
			os << record[i].message;
			os.unsetf(std::ios::left);

			os.setf(std::ios::right);
			os.width(5);
			os.setf(std::ios::fixed);
			os.precision(0);
			os << record[i].duration.count() / 1000000 << " ";
			
			os.unsetf(std::ios::fixed);
			os.unsetf(std::ios::right);
			os.precision(6);

			os << record[i].units << std::endl;
		}
	}
}