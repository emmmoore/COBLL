/*
 * Driver.h
 *
 *  Created on: Apr 20, 2022
 *      Author: elanor
 */
#include <string>
#include <iostream>
#include <fstream>

#ifndef DRIVER_H
#define DRIVER_H

// --------- STRUCTS & ENUMS ---------

struct ProgramInfo {
	std::string id;
	std::string author;
	std::string installation;
	std::string datewritten;
	std::string datecompiled;
	std::string security;

	ProgramInfo() {
		id = "Unspecified Program";
		author = "Unspecified Author";
		installation = "Unspecified Installation";
		datewritten = "Unspecified Date Written";
		datecompiled = "Unspecified Date Compiled";
		security = "Unspecified Security";
	}
	ProgramInfo(const ProgramInfo& pi): id(pi.id) {}
	ProgramInfo& operator=(ProgramInfo other) {
		this->id = other.id;
		this->author = other.author;
		this->installation = other.installation;
		this->datewritten = other.datewritten;
		this->datecompiled = other.datecompiled;
		this->security = other.security;
		return *this;
	}
};
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

// --------- DRIVER CLASS ---------
class Driver {
public:
	Driver();
	Driver(std::string FileName);
	Driver(const Driver& other);
	int DriverMain();

	Driver& operator=(Driver other);
	std::string filename;
	int testint;
private:
//	std::ifstream InputFile;
	ProgramInfo Program;
	DivisionInfo Divisions[4];
//	std::string filename;

	int linenumber;
	std::string line;
	std::ifstream& AdvanceToLine(std::ifstream& file, int number);

	int IdentificationHandler();
	std::string IDInformation();

//	int ProcedureHandler();
//	int gettok();
//	std::string token;

};

#endif /* DRIVER_H */
