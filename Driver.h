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
	/**
	 * Stores locations of divisions
	 */
	DivisionInfo Divisions[4];
	/**
	 * Stores filename of source
	 */
	std::string filename;

	/**
	 * Stores current line number
	 */
	int linenumber;
	/**
	 * Stores current line
	 */
	std::string line;
	/*
	 * Moves to the desired position in the file
	 */
	std::ifstream& AdvanceToLine(std::ifstream& file, int number);

	/**
	 * Handles Identification Division
	 */
	int IdentificationHandler();
	/**
	 * Contains ID Division metadata
	 */
	ProgramInfo Program;
	/**
	 * Testing: Returns ID Division metadata
	 */
	std::string IDInformation();


	/**
	 * Holds token value
	 */
	std::string strVal = "";
	double douVal = 0.0;
	int intVal= 0;

	/**
	 * Handles Procedure Division
	 */
	int ProcedureHandler();
};

#endif /* DRIVER_H */
