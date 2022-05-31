///
/// \mainpage COBLL
/// COBLL is an (aspiring) LLVM-based COBOL compiler.
///
/// Navigate through classes and files through the menu above.
///
/// \file
/// This file contains the main function of COBLL, which takes in COBOL file names from the command line and compiles them.
/// @author Elanor Moore
///

#include <iostream>
#include <regex>
#include "Driver.h"
///
/// Takes in command-line arguments representing COBOL file names, and compiles the corresponding COBOL files.
/// @returns 1 if a non-COBOL file is supplied or a file cannot be compiled; 0 otherwise.
///
int main(int argc, char *argv[]) {

	std::cout << "Working..." << std::endl;

	// Declares array of drivers.
	Driver *drivers[argc];

	// Initializes the array of drivers and attempt to compile.
	for (int i = 1; i < argc; i++) {
		// Checks the file is a COBOL file.
		std::regex fileformat ("^[a-zA-Z0-9]*.(cbl|CBL|cob|COB|cobol|COBOL)$");
		if (!std::regex_match(argv[i], fileformat)) {

			std::cout << "One or more of the files does not seem to be a COBOL file." << std::endl;

			return 1;
		}

		// Constructs the driver.
		Driver temp = Driver(argv[i]);
		drivers[i] = &temp;

		// Compiles the file.
		int status = (*drivers[i]).Compile();
		if (status != 0) {

			std::cout << "One or more of the files could not be compiled." << std::endl;

			return 1;
		}
	}
	return 0;
}

