/*
 * Utils.cpp
 *
 *  Created on: 02/12/2012
 *      Author: jamesmadley
 */

#include "Utils.h"

string Utils::toLower(string s) {
	for (std::size_t i = 0; i < s.length(); i++) {
		s[i] = tolower((int)s[i]);
	}
	return s;
}
