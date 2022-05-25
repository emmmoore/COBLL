/*
 * Driver.cpp
 *
 *  Created on: Apr 20, 2022
 *      Author: elanor
 */

#include "Driver.h"

Driver::Driver() {
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
	// Initializes input file
	linenumber = 1;
	this->filename = FileName;


	Divisions[0].name = "IDENTIFICATION";
	Divisions[1].name = "ENVIRONMENT";
	Divisions[2].name = "DATA";
	Divisions[3].name = "PROCEDURE";
	std::ifstream InputFile(filename);

	line = "";

	int lastdiv = -1;
	int thisdiv = 0;

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
	InputFile.clear();

	Divisions[thisdiv].endline = linenumber-1;
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

	for (int i = 0; i < 4 && status == 0; i++) {
		int startline = Divisions[i].startline;
		if (startline > 0) {
			switch(i) {
				case 0:
					status = IdentificationHandler();
					break;
			}
		}
	}
	return status;
}


std::ifstream& Driver::AdvanceToLine(std::ifstream& file, int number) {
	if (number < linenumber) {
		file.clear();
		file.seekg(0, std::ios::beg);
		linenumber = 1;
	}

	char c = '\0';
	while (linenumber < number && file.peek() != EOF) {
		file.get(c);
		if (c == '\n')
			linenumber++;
	}
	return file;
}
