///
/// \file
/// This file contains the functions of the Driver class relevant to the Procedure Division.
///
/// This file is currently in progress and is the main focus of current work.
/// @author Elanor Moore
///

#include "Driver.h"
#include "ASTNodes.cpp"

// TODO: gettok for displaying strings
// TODO: Create node for extern to C's `printf`
// TODO: Create functionality to generate tree

///
/// Specifies the types of tokens the procedure parser can handle.
///
enum ProcToken {
	empty,
	display,
	strlit,
	ext,
	eof
};

namespace {
	static ProcToken gettok(std::ifstream& inputstream) {

		// Handles EOF.
		if (inputstream.peek() == EOF)
			return eof;
		char c = "\0";
		std::string value = "";

		// Ignores whitespace up to next token.
		while (isspace(c))
				inputstream.get(c);

		// Handles string literals (cannot use spaces as delimiters).
		if (c == "\"") {
			inputstream.get(c); // Opening "
			while (inputstream.peek() != EOF && c != "\"") {
				inputstream.get(c);
				value += c;
			}
			inputstream.get(c); // Closing "
			return strlit;
		} else { // Handles non-string tokens (space-sensitive).
			value += c;
			while (inputstream.peek() != EOF && isalpha(inputstream.peek())) {
				inputstream.get(c);
				value += c;
			}

			// Identifies and returns token.
			if (value == "DISPLAY")
				return display;
		}

		return empty;
	}

	std::unique_ptr<ASTNode> LogError(const char *Str) {
	  fprintf(stderr, "LogError: %s\n", Str);
	  return nullptr;
	}
	std::unique_ptr<ASTNode> LogErrorP(const char *Str) {
	  LogError(Str);
	  return nullptr;
	}
}

int Driver::ProcedureHandler() {
	int status = 0;

	// TODO Entire Procedure Handler

	return status;
}
