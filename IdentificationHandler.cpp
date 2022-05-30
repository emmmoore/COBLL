#include "Driver.h"

int Driver::IdentificationHandler() {
	std::ifstream InputFile(this->filename);
	AdvanceToLine(InputFile, Divisions[0].startline);
	int status = 0;

	line = "";

	// Loop through division until end, handling info as key-value pairs

	char c = ' ';

	int endline = Divisions[0].endline;

	while (InputFile.peek() != EOF && linenumber <= endline) {
		line = "";
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
	std::cout << Program.to_string() << std::endl;
	InputFile.close();
	return status;
}
