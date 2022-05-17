/*
 * Driver.h
 *
 *  Created on: Apr 20, 2022
 *      Author: elanor
 */
#include <string>
#include <iostream>
#include <fstream>
#include "ProgramInfo.h"
#include "DivisionInfo.h"

#ifndef DRIVER_H
#define DRIVER_H

class Driver {
public:
	/**
	 * No-args constructor
	 *
	 */
	Driver();
	/*
	 * Copy constructor
	 *
	 */
	Driver(std::string FileName);
	/*
	 * Constructs a Driver from a given filename
	 * Conducts first pass to identify division locations
	 */
	Driver(const Driver& other);
	/*
	 * Compiles each division
	 */
	int Compile();
	/*
	 * Implicit copy operator
	 */
	Driver& operator=(Driver other);
private:
//	std::ifstream InputFile;
	ProgramInfo Program;
	DivisionInfo Divisions[4];
	std::string filename;

	int linenumber;
	std::string line;
	/*
	 * Moves to the desired position in the file
	 */
	std::ifstream& AdvanceToLine(std::ifstream& file, int number);

	int IdentificationHandler();
	std::string IDInformation();

};

#endif /* DRIVER_H */
