///
/// \file
/// This file contains function bodies for all Driver class constructors, and all functions of the Driver class
/// that are not division-specific.
/// @author Elanor Moore
///

#include "Driver.h"

Driver::Driver() {
	// Initializes Driver with default values.
	Program.id = "Unspecified Program";
	linenumber = 1;
	line = "";

	Divisions[0].name = "IDENTIFICATION";
	Divisions[1].name = "ENVIRONMENT";
	Divisions[2].name = "DATA";
	Divisions[3].name = "PROCEDURE";
}

Driver::Driver(const Driver& other) {
	linenumber = other.linenumber;
	Program = other.Program;
	line = "";
	std::copy(std::begin(other.Divisions), std::end(other.Divisions), std::begin(Divisions));
}

Driver::Driver(std::string FileName) {
	linenumber = 1;

	this->filename = FileName;
	std::ifstream InputFile(filename);

	Divisions[0].name = "IDENTIFICATION";
	Divisions[1].name = "ENVIRONMENT";
	Divisions[2].name = "DATA";
	Divisions[3].name = "PROCEDURE";

	line = "";

	int lastdiv = -1;
	int thisdiv = 0;

	// Completes a pass through the file to identify the location of each division and store it in Divisions.
	char c = '\0';
	while (InputFile.peek() != EOF) {
		while (InputFile.peek() != EOF) {
			InputFile.get(c);
			if (c == '\n')
				break;
			line += c;
		}

		for (int i = 0; i < 4; i++) {
			if (line  == "       " + Divisions[i].name + " DIVISION.") {
				thisdiv = i;

				if (thisdiv <= lastdiv)
					return;
				if (lastdiv != -1)
					Divisions[lastdiv].endline = linenumber - 1;
				Divisions[thisdiv].startline = linenumber;

				break;
			}
		}
		linenumber++;
	}
	Divisions[thisdiv].endline = linenumber-1;

	InputFile.clear();
	InputFile.close();

}

Driver& Driver::operator=(Driver other) {
	this->linenumber = other.linenumber;
	this->Program = other.Program;
	std::copy(std::begin(other.Divisions), std::end(other.Divisions), std::begin(this->Divisions));
	return *this;
}

int Driver::Compile() {
	int status = 0;

	// Calls the handler for each division as appropriate.
	for (int i = 0; i < 4 && status == 0; i++) {
		int startline = Divisions[i].startline;
		if (startline > 0) {
			switch(i) {
				case 0:
					status = IdentificationHandler();
					break;
				// Other cases (1-3) need to be added for the other three divisions.
			}
		}
	}
	return status;
}


std::ifstream& Driver::AdvanceToLine(std::ifstream& file, int number) {
	// Returns to the start of the file if the desired line is above the current line
	if (number < linenumber) {
		file.clear();
		file.seekg(0, std::ios::beg);
		linenumber = 1;
	}

	// "Eats" characters until the desired line is reached.
	char c = '\0';
	while (linenumber < number && file.peek() != EOF) {
		file.get(c);
		if (c == '\n')
			linenumber++;
	}
	return file;
}
