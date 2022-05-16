/*
 * ProcedureHandler.cpp
 *
 *  Created on: Apr 27, 2022
 *      Author: elanor
 */
#include "Driver.h"
#include "ASTNodes.cpp"

enum ProcToken {
	empty = 0,
	display = -1,
	strlit = -2
};

// //Declaration of helper routines
//int Driver::gettok() {
////	line = "";
////	char c = '\0';
////	while (InputFile.peek() != EOF) {
////		InputFile.get(c);
////		if (c == '\n')
////			break;
////		line += c;
////	}
//
//	token = "";
//	char c = ' ';
//	while (InputFile.peek() != EOF && isspace(c))
//		InputFile.get(c);
//	bool strexp = false;
//	while(InputFile.peek() != EOF) {
//		bool strexp = false;
//		InputFile.get(c);
//		if (strexp) {
//			strexp = false;
//			if (token == '\"')
//				return strlit;
//			token += c;
//		} else if (c == '\"') {
//			strexp = true;
//		} else if (isspace(c)) {
//			break;
//		} else {
//			token += c;
//		}
//	}
//
//	if (token == "DISPLAY")
//		return display;
//}
//
//static std::unique_ptr<DisplayNode> ParseDisplay() {
//
//}

int Driver::ProcedureHandler() {
	int status = 0;

	// TODO Entire Procedure Handler

	return status;
}

// Implementation of helper routines
namespace {

}
