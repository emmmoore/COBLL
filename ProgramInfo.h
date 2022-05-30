/*
 * ProgramInfo.h
 *
 *  Created on: May 16, 2022
 *      Author: elanor
 */
#include <string>
#include <iostream>
#include <fstream>

#ifndef PROGRAMINFO_H_
#define PROGRAMINFO_H_

struct ProgramInfo {
	std::string id;
	std::string author;
	std::string installation;
	std::string datewritten;
	std::string datecompiled;
	std::string security;

	ProgramInfo() {
		id = "Unspecified Program";
		author = "Unspecified Author";
		installation = "Unspecified Installation";
		datewritten = "Unspecified Date Written";
		datecompiled = "Unspecified Date Compiled";
		security = "Unspecified Security";
	}
	ProgramInfo(const ProgramInfo& pi): id(pi.id) {}
	ProgramInfo& operator=(ProgramInfo other) {
		this->id = other.id;
		this->author = other.author;
		this->installation = other.installation;
		this->datewritten = other.datewritten;
		this->datecompiled = other.datecompiled;
		this->security = other.security;
		return *this;
	}

	///
	/// Returns a String representation of a ProgramInfo containing the information in its fields.
	///
	/// The representation is a multi-line block with one key-value pair on each line.
	///
	std::string to_string() {
		std::string info = "";

		info += "Program ID: " + id + "\n";
		info += "Author: " + author + "\n";
		info += "Installation: " + installation + "\n";
		info += "Date Written: " + datewritten + "\n";
		info += "Date Compiled: " + datecompiled + "\n";
		info += "Security: " + security + "\n";

		return info;
	}
};


#endif /* PROGRAMINFO_H_ */
