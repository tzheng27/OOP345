/* Name: Tian Zheng
   Student Number: 155394174
   Email: tzheng26@myseneca.ca */

#ifndef SICT_TKP_H
#define	SICT_TKP_H

#include <iostream>
#include <chrono>

namespace sict {
	const int MAX = 10;
	const char UNITS[] = "seconds";

	class  Timekeeper {
		int num_of_records;
		std::chrono::steady_clock::time_point starttime;
		std::chrono::steady_clock::time_point endtime;
		struct {
			const char* message;
			const char* units;
			std::chrono::steady_clock::duration duration;
		} record[MAX];
	public:
		Timekeeper();
		void start();
		void stop();
		void recordEvent(const char*);
		void report(std::ostream&) const;
	};
}

#endif // !SICT_TKP_H
