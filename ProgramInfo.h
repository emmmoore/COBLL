///
/// \file
/// This file contains the declaration of the ProgramInfo struct.
/// @author Elanor Moore
///

#include <string>
#include <iostream>
#include <fstream>

#ifndef PROGRAMINFO_H_
#define PROGRAMINFO_H_

///
/// A structure to represent information about the program being compiled.
///
/// Information within the structure comes form the source file's Identification Division.
///
struct ProgramInfo {
	std::string id;
	std::string author;
	std::string installation;
	std::string datewritten;
	std::string datecompiled;
	std::string security;

	///
	/// Constructs a nameless ProgramInfo with default ("Unspecified") values.
	///
	ProgramInfo() {
		id = "Unspecified Program";
		author = "Unspecified Author";
		installation = "Unspecified Installation";
		datewritten = "Unspecified Date Written";
		datecompiled = "Unspecified Date Compiled";
		security = "Unspecified Security";
	}

	///
	/// Constructs a ProgramInfo from another ProgramInfo, essentially creating this as a copy of the other.
	/// @param other The ProgramInfo to be copied from.
	///
	ProgramInfo(const ProgramInfo& other): id(other.id) {}

	///
	/// Overrides the implicit copy assignment operator.
	///
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
