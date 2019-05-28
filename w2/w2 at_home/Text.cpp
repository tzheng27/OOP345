/* Name: Tian Zheng
   Student Number: 155394174
   Email: tzheng26@myseneca.ca */

#include<iostream>
#include<fstream>
#include<string>
#include"Text.h"

namespace sict {
	Text::Text() {
		texts = nullptr;
		countstrings = 0;
	}

	Text::Text(char* filename) {
		size_t count = 0;
		std::string templine;
		std::ifstream fin;
		fin.open(filename);
		while (std::getline(fin, templine)) {
			count++;
		}
		countstrings = count;
		fin.close();
		texts = new std::string[count];
		fin.open(filename);
		for (size_t i = 0; i < countstrings; i++) {
			std::getline(fin, texts[i]);
		}
	}

	Text::Text(const Text& src) {
		texts = nullptr;
		*this = src;
	}

	Text::Text(Text&& src) {
		texts = nullptr;
		*this = std::move(src);
	}

	Text& Text::operator=(const Text& src) {
		if (this != &src) {
			countstrings = src.countstrings;

			texts = nullptr;
			texts = new std::string[countstrings];
			for (size_t i = 0; i < countstrings;i++)
				texts[i].assign(src.texts[i]);
		}
		return *this;
	}

	Text& Text::operator=(Text&& src) {
		if (this != &src) {
			countstrings = src.countstrings;

			texts = nullptr;
			texts = src.texts;

			src.countstrings = 0;
			src.texts = nullptr;
		}
		return *this;
	}

	Text::~Text() {
		delete[] texts;
		texts = nullptr;
	}
	size_t Text::size() const {
		return countstrings;
	}
}
