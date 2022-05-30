///
/// \file
/// This file contains the declaration of the DivisionInfo struct.
/// @author Elanor Moore
///

#include <string>
#include <iostream>
#include <fstream>

#ifndef DIVISIONINFO_H_
#define DIVISIONINFO_H_

///
/// A structure to represent information about a division.
///
struct DivisionInfo {
	///
	/// The name of this division.
	///
	std::string name;
	///
	/// This division's starting line.
	///
	int startline;
	///
	/// This division's ending line.
	///
	int endline;

	///
	/// Constructs a nameless DivisionInfo with starting and ending lines of -1.
	///
	DivisionInfo() {
		startline = -1;
		endline = -1;
	}

	///
	/// Constructs a DivisionInfo from another DivisionInfo, essentially creating this as a copy of the other.
	/// @param other The DivisionInfo to be copied from.
	///
	DivisionInfo(const DivisionInfo& other): name(other.name), startline(other.startline), endline(other.endline) {}
	DivisionInfo& operator=(DivisionInfo other) {
		this->name = other.name;
		this->startline = other.startline;
		this->endline = other.endline;
		return *this;
	}

	///
	/// Returns a String representation of a DivisionInfo containing the information in its fields.
	///
	/// Example: A representation for a division named "My Division" with starting and ending lines 9 and 20:
	/// "My Division: [9, 20]"
	///
	std::string to_string() {
		return name + ": [" + std::to_string(startline) + ", " + std::to_string(endline) + "]";
	}
};



#endif /* DIVISIONINFO_H_ */
