/*
 * COBLL.cpp
 *
 *  Created on: Apr 21, 2022
 *      Author: elanor
 */

#include <iostream>
#include <regex>
#include "Driver.h"
// --------- MAIN FUNCTION ---------
int main(int argc, char *argv[]) {
	// Initialize and exectue Drivers for command-line file arguments
	std::cout << "Working..." << std::endl;

	Driver *drivers[argc];

	for (int i = 1; i < argc; i++) {
		// Check the file is a COBOL file
		std::regex fileformat ("^[a-zA-Z0-9]*.(cbl|CBL|cob|COB|cobol|COBOL)$");
		if (!std::regex_match(argv[i], fileformat)) {

			std::cout << "One or more of the files does not seem to be a COBOL file." << std::endl;

			return 1;
		}

		// Construct the driver
		Driver temp = Driver(argv[i]);
		drivers[i] = &temp;

		// Compile the file
		int status = (*drivers[i]).Compile();
		if (status != 0) {

			std::cout << "One or more of the files could not be compiled." << std::endl;

			return 1;
		}
	}
	return 0;
}

