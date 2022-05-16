#include <iostream>
#include <stdio.h>
#include "Driver.h"

// Populates struct Program with info about it
int Driver::IdentificationHandler() {
	if (this->filename == "")
		std::cout << "Filename is empty in ID Handler" << std::endl;
	else
		std::cout << this <<"File name according to Identification Handler: "<< this->filename << std::endl;
	std::ifstream idstream(this->filename);
	AdvanceToLine(idstream, Divisions[0].startline);
	int status = 0;

	line = "";

	// Loop through division until end, handling info as key-value pairs

	char c = ' ';

	int endline = Divisions[0].endline;

	while (idstream.peek() != EOF && linenumber <= endline) {
		line = "";
		while (idstream.peek() != EOF) {
			idstream.get(c);
			if (c == '\n')
				break;
			line += c;
		}

		std::cout << "Line number " << linenumber << std::endl;
		if (linenumber == Divisions[0].startline) {
			linenumber++;
			std::cout << "found start of div" << std::endl;
			continue;
		}
		//
		int col = 1;
		std::string identifier = "";
		std::string value = ""; // Assumes each line has one value, that ends in a period;
		// permits any amount of space on/between each value/key
		// Collect key
		c = ' ';
		for (; col <= line.size() && c != '.'; col++) {
			if (!isspace(c))
				identifier += c;
			c = line.at(col-1);
		}
		// Collect value
		c = ' ';
		for (; col <= line.size() && c!= '.'; col++) {
			if (!isspace(c))
				value += c;
			c = line.at(col-1);
		}
		if (identifier == "")
			continue;
		else if (value == "") {
			status = 1;
			return status;
		}
		// Assign correct value
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
	std::cout << IDInformation() << std::endl;
	idstream.close();
	return status;
}

std::string Driver::IDInformation() {
		std::string info = "";

		info += "Program ID: " + Program.id + "\n";
		info += "Author: " + Program.author + "\n";
		info += "Installation: " + Program.installation + "\n";
		info += "Date Written: " + Program.datewritten + "\n";
		info += "Date Compiled: " + Program.datecompiled + "\n";
		info += "Security: " + Program.security + "\n";

		return info;
}
