/*
 * DivisionInfo.h
 *
 *  Created on: May 16, 2022
 *      Author: elanor
 */
#include <string>
#include <iostream>
#include <fstream>

#ifndef DIVISIONINFO_H_
#define DIVISIONINFO_H_

struct DivisionInfo {
	std::string name;
	int startline;
	int endline;

	DivisionInfo() {
		startline = -1;
		endline = -1;
	}
	DivisionInfo(const DivisionInfo& di): name(di.name), startline(di.startline), endline(di.endline) {}
	DivisionInfo& operator=(DivisionInfo other) {
		this->name = other.name;
		this->startline = other.startline;
		this->endline = other.endline;
		return *this;
	}
	std::string to_string() {
		return name + ": [" + std::to_string(startline) + ", " + std::to_string(endline) + "]";
	}
};



#endif /* DIVISIONINFO_H_ */
