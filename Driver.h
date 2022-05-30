///
/// \file
/// This file contains the declaration of the Driver class, which handles the compilation of one COBOL file.
/// @author Elanor Moore
///

#include <string>
#include <iostream>
#include <fstream>
#include "ProgramInfo.h"
#include "DivisionInfo.h"

#ifndef DRIVER_H
#define DRIVER_H

///
/// Controls the reading and compilation of a COBOL file, start to finish.
///
/// When constructed, a Driver identifies the location of each COBOL division present in the file. To compile, the
/// Compile function then calls its own handler function for each division, which lexes, parses, generates code
/// for, and optimizes for that division.
///
class Driver {
public:
	///
	/// Constructs a generic Driver not corresponding to a file.
	///
	Driver();

	///
	/// Constructs a Driver as a copy of another Driver.
	///
	/// The Driver constructed gets the filename, program information, division information and line number
	/// from the Driver being copied.
	/// @param &other the Driver to be copied.
	Driver(const Driver& other);

	///
	/// Constructs a Driver from a given file name.
	/// @param FileName The name of the COBOL file to be compiled.
	///
	Driver(std::string FileName);

	///
	/// Compiles the file.
	///
	int Compile();

	///
	/// Overrides the implicit copy assignment operator.
	///

	Driver& operator=(Driver other);
private:
	/// -------- NON-DIVISION-SPECIFIC -------- ///

	///
	/// Stores the division information for each COBOL division.
	///
	DivisionInfo Divisions[4];
	///
	/// The file name of the COBOL File.
	///
	std::string filename;

	///
	/// The current line number in use.
	///
	int linenumber;

	///
	/// The current line in use.
	///
	std::string line;

	///
	/// Moves the file stream to the specified line number.
	/// @param file The ifstream object to be moved to a different line.
	/// @param number The line to be moved to.
	/// @returns The ifstream that was manipulated.
	///
	std::ifstream& AdvanceToLine(std::ifstream& file, int number);



	///
	/// Handles the lexing and parsing of the Identification Division, storing information in Program.
	///
	/// Since the Identification Division is a set of key-value pairs describing metadata about the program,
	/// no Abstract Syntax Tree, code generation, or optimization is required. The information in this
	/// Division is stored, but will often be unused (except for documentation and debugging purposes).
	///
	int IdentificationHandler();

	///
	/// Stores the information about the program found within the Identification Division.
	///
	ProgramInfo Program;



	///
	/// Handles the lexing and parsing of the Procedure Division.
	///
	/// Parsing will rely heavily on Abstract Syntax Tree generation and the ASTNode class hierarchy. This function
	/// will also handle the code generation and optimization of Procedure Division code.
	///
	int ProcedureHandler();

	///
	/// Stores the String value of the most recent String token.
	///
	std::string strVal = "";

	///
	/// Stores the numerical value of the most recent numerical token.
	///
	int intVal= 0;

};

#endif /* DRIVER_H */
