///
/// \file
/// This file contains the functions of the Driver class relevant to the Identification Division.
/// @author Elanor Moore
///

#include "Driver.h"

int Driver::IdentificationHandler() {
	// Initializes the file stream and local variables.
	std::ifstream InputFile(this->filename);
	AdvanceToLine(InputFile, Divisions[0].startline);
	int status = 0;

	line = "";

	char c = ' ';

	int endline = Divisions[0].endline;

	// Loops through the division in the source code.
	while (InputFile.peek() != EOF && linenumber <= endline) {
		// Collects a line.
		line = "";
		int col = 1;
		while (InputFile.peek() != EOF) {
			InputFile.get(c);
			if (c == '\n')
				break;
			line += c;
		}

		if (linenumber == Divisions[0].startline) {
			linenumber++;
			continue;
		}

		// Identifies key within line. Assumes 'proper' formatting, including having identifier and value on one line.
		std::string identifier = "";
		c = ' ';
		for (; col <= line.size() && c != '.'; col++) {
			if (!isspace(c))
				identifier += c;
			c = line.at(col-1);
		}

		// Identifies value within line. Assumes 'proper' formatting, including having identifier and value on one line.
		std::string value = "";
		c = ' ';
		for (; col <= line.size() && c!= '.'; col++) {
			if (!isspace(c))
				value += c;
			c = line.at(col-1);
		}

		// If the identifier is empty, skip to the next line.
		if (identifier == "")
			continue;
		// If the identifier is not empty but value is, an error has occurred.
		else if (value == "") {
			status = 1;
			return status;
		}
		// Assigns the correct value.
		if (identifier == "PROGRAM-ID")
			Program.id = value;
		else if (identifier == "AUTHOR")
			Program.author = value;
		else if (identifier == "INSTALLATION")
			Program.installation = value;
		else if (identifier == "DATE-WRITTEN")
				Program.datewritten = value;
		else if (identifier == "DATE-COMPILED")
				Program.datecompiled = value;
		else if (identifier == "SECURITY")
				Program.security = value;

		linenumber++;
	}

	// Prints the keys and values found (primarily for debugging purposes).
	std::cout << Program.to_string() << std::endl;
	InputFile.close();
	return status;
}
